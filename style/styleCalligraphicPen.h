#ifndef STYLECALLIGRAPHICPEN_H
#define STYLECALLIGRAPHICPEN_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class StyleLine;
class StyleFill;

class STYLESHARED_EXPORT StyleCalligraphicPen
{
public:
    StyleCalligraphicPen();
    void setAngle(QString angle) {this->angle = angle.TOQREAL();}
    void setWidth(QString width) {this->width = width.TOQREAL();}
    StyleLine *getLine() {return line;}
    StyleFill *getFill() {return fill;}
protected:
    qreal angle;
    qreal width;
    StyleLine *line;
    StyleFill *fill;
};

#endif // STYLECALLIGRAPHICPEN_H
