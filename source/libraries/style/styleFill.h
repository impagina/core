#ifndef STYLEFILL_H
#define STYLEFILL_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class STYLESHARED_EXPORT StyleFill
{
public:
    StyleFill();
    void setColor(QString color) {this->color = color;}
    void setColorShading(QString colorShading) {this->colorShading = colorShading.toInt();}
protected:
    QString color;
    int colorShading;
};

#endif // STYLEFILL_H
