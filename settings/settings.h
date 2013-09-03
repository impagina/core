#ifndef SETTINGS_H
#define SETTINGS_H

#include "settings_global.h"

#include <QString>
#include <QRect>
// TODO: find a way to include the QtGui's QColor if it's available
// #include <QColor>
#include "QtNoGui/qcolor.h"
#include "global/global.h"

class DocumentPage;
class DocumentLayout;
class DocumentTypography;

class SETTINGSSHARED_EXPORT Settings
{
public:
    Settings();
    void setPage(DocumentPage *page) {this->page = page;}
    void setLayout(DocumentLayout *layout) {this->layout = layout;}
    void setTypography(DocumentTypography *typography) {this->typography = typography;}

    void setLengthUnit(QString unit) {lengthUnit = unit.toInt();}
    void setAutomaticSave(QString automatic) {automaticSave = automatic.TOBOOL();}
    void setAutomaticSaveTime(QString time) {automaticSaveTime = time.toInt();}
    void setPageGapHorizontal(QString gap) {pageGapHorizontal = gap.TOQREAL();}
    void setPageGapVertical(QString gap) {pageGapVertical = gap.TOQREAL();}
    void setScratchSpace(QString t, QString r, QString b, QString l) {
        this->scratchSpace = Rectangle(
            t.TOQREAL(),
            r.TOQREAL(),
            b.TOQREAL(),
            l.TOQREAL()
        );
    }
    void setPaperColor(QString color) {paperColor = QColor(color);}
    void setMarginAreaCovered(QString covered) {marginAreaCovered = covered.TOBOOL();}

protected:
    DocumentPage *page; // used for document settings
    DocumentLayout *layout; // used for document settings
    DocumentTypography *typography; // used for document settings

    int lengthUnit; // TODO: should be a set (ale/20130901)
    bool automaticSave;
    int automaticSaveTime;
    qreal pageGapHorizontal;
    qreal pageGapVertical;
    Rectangle scratchSpace;
    QColor paperColor;
    bool marginAreaCovered;
};

#endif // SETTINGS_H
