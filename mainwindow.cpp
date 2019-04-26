#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mInputString = getInputString();
    mWordsSet = getWordsSet();
    mLongestWord = findLongestWord(mInputString, mWordsSet);

    mInputTextHighlighter = new Highlighter(ui->textEdit->document());
    mWordsSetHighlighter = new Highlighter(ui->textEdit_2->document());

    QObject::connect(mWordsSetHighlighter, SIGNAL(patternChanged(QRegularExpression)),
                     mInputTextHighlighter, SLOT(setPattern(QRegularExpression)));
    QObject::connect(this, SIGNAL(longestWordChanged(QRegularExpression)),
                     mWordsSetHighlighter, SLOT(setPattern(QRegularExpression)));
    mWordsSetHighlighter->setPattern(QRegularExpression(mLongestWord));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mInputTextHighlighter;
    delete mWordsSetHighlighter;
}

QString MainWindow::getInputString() const
{
    return ui->textEdit->toPlainText();
}

QStringList MainWindow::getWordsSet() const
{
    return ui->textEdit_2->toPlainText().split(QRegularExpression("\\s+"));
}

QString MainWindow::findLongestWord(const QString &string, const QStringList &wordsSet) const
{
    QString longestWord("");

    foreach (const QString &word, wordsSet)
    {
        if (string.contains(word) && longestWord.length() < word.length())
        {
            longestWord = word;
        }
    }

    return longestWord;
}

void MainWindow::checkLongestWord()
{
    QString longestWord = findLongestWord(mInputString, mWordsSet);
    if (longestWord != mLongestWord)
    {
        mLongestWord = longestWord;
        emit longestWordChanged(QRegularExpression(mLongestWord));
    }
}

void MainWindow::on_textEdit_textChanged()
{
    mInputString = getInputString();
    checkLongestWord();
}

void MainWindow::on_textEdit_2_textChanged()
{
    mWordsSet = getWordsSet();
    checkLongestWord();
}
