#ifndef STYLECHARACTER_H
#define STYLECHARACTER_H

#include "style_global.h"

#include <QString>

#include "global/global.h"

class STYLESHARED_EXPORT StyleCharacter
{
public:
    StyleCharacter();

    void setFont(QString font) {this->font = font;}
    void setSize(QString size) {this->size = size.TOQREAL();}
    void setColumns(QString columns) {this->columns = columns.toInt();}
    void setColumnGap(QString gap) {this->columnGap = gap.TOQREAL();}
    void setColor(QString color) {this->color = color;}
    void setStrokeColor(QString color) {this->strokeColor = color;}
    void setFillColor(QString color) {this->fillColor = color;}
    void setLineColor(QString color) {this->lineColor = color;}
    void setFillColorShade(QString shade) {this->fillColorShade = shade.toInt();}
    void setLineColorShade(QString shade) {this->lineColorShade = shade.toInt();}
    void setShade(QString shade) {this->shade = shade.toInt();}
    void setStrokeShade(QString shade) {this->strokeShade = shade.toInt();}
protected:
    // ^f(DA;j^
    QString font;
    qreal size;
    int columns;
    qreal columnGap;

    QString color;
    QString strokeColor;
    QString fillColor;
    QString lineColor;
    int fillColorShade;
    int lineColorShade;
    int shade;
    int strokeShade;
};

#endif // STYLECHARACTER_H
