#ifndef STYLELINE_H
#define STYLELINE_H

#include "style_global.h"

#include <QString>

#include "global/global.h"


class STYLESHARED_EXPORT StyleLine
{
public:
    StyleLine();
    void setArrowStart(QString arrowStart) {this->arrowStart = arrowStart.toInt();}
    void setArrowEnd(QString arrowEnd) {this->arrowEnd = arrowEnd.toInt();}
    void setColor(QString color) {this->color = color;}
    void setStyle(QString style) {this->style = style.toInt();}
    void setWidth(QString width) {this->width = width.TOQREAL();}
    void setColorShading(QString shading) {this->colorShading = shading.toInt();}
protected:
    int arrowStart;
    int arrowEnd;
    QString color;
    // TODO: doc->itemToolPrefs().shapeLineStyle    = static_cast<Qt::PenStyle>(attrs.valueAsInt("STIL")); (ale/20130905)
    int style;
    qreal width;
    int colorShading;

};

#endif // STYLELINE_H
