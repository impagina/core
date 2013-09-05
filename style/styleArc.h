#ifndef STYLEARC_H
#define STYLEARC_H

#include "style_global.h"

#include "global/global.h"

#include <QString>

class STYLESHARED_EXPORT StyleArc
{
public:
    StyleArc();
    void setAngleStart(QString start) {this->angleStart = start.TOQREAL();}
    void setAngleEnd(QString end) {this->angleEnd = end.TOQREAL();}
protected:
    qreal angleStart;
    qreal angleEnd;
};

#endif // STYLEARC_H
