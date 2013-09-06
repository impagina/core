#ifndef DOCUMENTPAGE_H
#define DOCUMENTPAGE_H

#include "document_global.h"
#include <QString>

#include "document.h"
#include "global/global.h"

#if !defined(TOQREAL)
#define TOBOOL() toInt() == 1
#if defined(QT_NO_FPU) || defined(QT_ARCH_ARM) || defined(QT_ARCH_WINDOWSCE) || defined(QT_ARCH_SYMBIAN)
#define TOQREAL() toFloat()
#else
#define TOQREAL() toDouble()
#endif
#endif

class DOCUMENTSHARED_EXPORT DocumentPage
{

public:
    DocumentPage();
    void setSize(QString size) {this->size = size;}
    void setOrientationPortrait(bool portrait) {this->orientationPortrait = portrait;}
    void setWidth(QString width) {this->width = width.TOQREAL();}
    void setHeight(QString height) {this->height = height.TOQREAL();}
    void setMargins(QString t, QString r, QString b, QString l) {
        this->margins = Rectangle(
            t.TOQREAL(),
            r.TOQREAL(),
            b.TOQREAL(),
            l.TOQREAL()
        );
    }
    void setMarginsTemplate(QString marginsTemplate) {
        this->marginsTemplate = marginsTemplate.toInt();
    }
    void setBleed(QString bleed) {this->bleed = bleed.TOQREAL();}
protected:
    QString size; // TODO: or use a set? (ale/20130831)
    QString orientationPortrait;
    qreal width;
    qreal height;
    Rectangle margins;
    int marginsTemplate; // an enum? (fibonacci, ...)
    qreal bleed; // is defined as trbl in scribus. useless.
};

#endif // DOCUMENTPAGE_H
