#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    mFormat.setFontWeight(QFont::Bold);
    mFormat.setForeground(QColor("red"));
}

void Highlighter::setPattern(const QRegularExpression &pattern)
{
    if (pattern != mPattern) {
        mPattern = pattern;
        this->rehighlight();
        emit patternChanged(pattern);
    }
}

void Highlighter::highlightBlock(const QString &text)
{
    QRegularExpressionMatchIterator it = mPattern.globalMatch(text);
    while (it.hasNext())
    {
      QRegularExpressionMatch match = it.next();
      setFormat(match.capturedStart(), match.capturedLength(), mFormat);
    }
}
