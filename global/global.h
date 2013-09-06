#ifndef GLOBAL_H
#define GLOBAL_H

#include "global_global.h"

// TODO: this is not good but works in simple cases: what's the alternative? (ale/20130901)
#define TOBOOL() toInt() == 1
#if defined(QT_NO_FPU) || defined(QT_ARCH_ARM) || defined(QT_ARCH_WINDOWSCE) || defined(QT_ARCH_SYMBIAN)
#define TOQREAL() toFloat()
#else
#define TOQREAL() toDouble()
#endif


class GLOBALSHARED_EXPORT Global
{
    
public:
    Global();
};

class GLOBALSHARED_EXPORT Rectangle
{
public:
    Rectangle() {};
    Rectangle(qreal t, qreal r, qreal b, qreal l) {top = t; right = r; bottom = b; left = l;};
protected:
    qreal top;
    qreal right;
    qreal bottom;
    qreal left;
};

#endif // GLOBAL_H
