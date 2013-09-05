#ifndef STYLEIMAGE_H
#define STYLEIMAGE_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class StyleLine;
class StyleFill;

class STYLESHARED_EXPORT StyleImage
{
public:
    StyleImage();
    void setScaleX(QString scaleX) {this->scaleX = scaleX.TOQREAL();}
    void setScaleY(QString scaleY) {this->scaleY = scaleY.TOQREAL();}
    void setScaleType(QString scaleType) {this->scaleType = scaleType.TOBOOL();}
    void setAspectRatio(QString aspectRatio) {this->aspectRatio = aspectRatio.TOBOOL();}
    void setLowResType(QString lowResType) {this->lowResType = lowResType.toInt();}
    void setUseEmbeddedPath(QString useEmbeddedPath) {this->useEmbeddedPath = useEmbeddedPath.TOBOOL();}
    StyleLine *getLine() {return line;}
    StyleFill *getFill() {return fill;}
protected:
    qreal scaleX;
    qreal scaleY;
    bool scaleType;
    bool aspectRatio;
    int lowResType;
    bool useEmbeddedPath;
    StyleLine *line;
    StyleFill *fill;
};

#endif // STYLEIMAGE_H
