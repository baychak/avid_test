#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent);

private:
    void highlightBlock(const QString &text) override;

public slots:
   void setPattern(const QRegularExpression &pattern);

signals:
   void patternChanged(const QRegularExpression &newPattern) const;

private:
    QRegularExpression mPattern;
    QTextCharFormat mFormat;
};

#endif // HIGHLIGHTER_H

