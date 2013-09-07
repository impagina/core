#ifndef STYLEPARAGRAPH_H
#define STYLEPARAGRAPH_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class STYLESHARED_EXPORT StyleParagraph
{
public:
    StyleParagraph();
    void setTabFillChar(QString tabFillChar) {this->tabFillChar = tabFillChar;}
    void setTabWidth(QString tabWidth) {this->tabWidth = tabWidth.TOQREAL();}
protected:
    QString tabFillChar;
    qreal tabWidth;
};

#endif // STYLEPARAGRAPH_H
