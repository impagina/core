#ifndef STYLEPOLYGON_H
#define STYLEPOLYGON_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class STYLESHARED_EXPORT StylePolygon
{
public:
    StylePolygon();
    // TODO: shouldn't it also have line settings?
    void setCorners(QString corners) {this->corners = corners.toInt();}
    void setConvexityFactor(QString convexityFactor) {this->convexityFactor = convexityFactor.TOQREAL();}
    void setRotation(QString rotation) {this->rotation = rotation.TOQREAL();}
    void setRotationInner(QString rotationInner) {this->rotationInner = rotationInner.TOQREAL();}
    void setCurvatureInner(QString curvatureInner) {this->curvatureInner = curvatureInner.TOQREAL();}
    void setCurvatureOuter(QString curvatureOuter) {this->curvatureOuter = curvatureOuter.TOQREAL();}
    void setFactorEnabled(QString factorEnabled) {this->factorEnabled = factorEnabled.TOBOOL();}
protected:
    int corners;
    qreal convexityFactor;
    qreal rotation;
    qreal rotationInner;
    qreal curvatureInner;
    qreal curvatureOuter;
    bool factorEnabled;
};

#endif // STYLEPOLYGON_H
