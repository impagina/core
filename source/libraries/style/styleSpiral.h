#ifndef STYLESPIRAL_H
#define STYLESPIRAL_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class STYLESHARED_EXPORT StyleSpiral
{
public:
    StyleSpiral();
    void setAngleStart(QString angleStart) {this->angleStart = angleStart.TOQREAL();}
    void setAngleEnd(QString angleEnd) {this->angleEnd = angleEnd.TOQREAL();}
    void setFactor(QString factor) {this->factor = factor.TOQREAL();}
protected:
    qreal angleStart;
    qreal angleEnd;
    qreal factor;
};

#endif // STYLESPIRAL_H
