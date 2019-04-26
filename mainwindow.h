#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QString getInputString() const;
    QStringList getWordsSet() const;
    QString findLongestWord(const QString &string, const QStringList &wordsSet) const;
    void checkLongestWord();

private slots:
    void on_textEdit_textChanged();
    void on_textEdit_2_textChanged();

signals:
    void longestWordChanged(const QRegularExpression &newPattern) const;

private:
    Ui::MainWindow *ui;
    Highlighter *mInputTextHighlighter;
    Highlighter *mWordsSetHighlighter;
    QString mLongestWord;
    QString mInputString;
    QStringList mWordsSet;
};

#endif // MAINWINDOW_H
