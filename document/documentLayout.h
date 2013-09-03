#ifndef DOCUMENTLAYOUT_H
#define DOCUMENTLAYOUT_H

#include "document_global.h"
#include <QString>

#include "global/global.h"

class DOCUMENTSHARED_EXPORT DocumentLayout
{

public:
    DocumentLayout();
    void setPageNumberStart(QString start) {pageNumberStart = start.toInt();}
    void setFolds(QString folds) {this->folds = folds.toInt();};
    void setAutomaticTextFrames(QString automatic) {automaticTextFrames = automatic.TOBOOL();};
    void setAutomaticTextFramesColumns(QString automatic) {automaticTextFramesColumns = automatic.TOBOOL();};
    void setAutomaticTextFramesGap(QString automatic) {automaticTextFramesGap = automatic.TOQREAL();};
    void setGuidesLocked(QString locked) {guidesLocked = locked.TOQREAL();};
    void setGuidesSnapping(QString snapping) {guidesSnapping = snapping.TOQREAL();};
    void setGuidesSnappingElement(QString snapping) {guidesSnappingElement = snapping.TOQREAL();};
    void setGuidesSnappingGrid(QString snapping) {guidesSnappingGrid = snapping.TOQREAL();};
    void setRulerXOffset(QString offset) {rulerXOffset = offset.TOQREAL();};
    void setRulerYOffset(QString offset) {rulerYOffset = offset.TOQREAL();};
protected:
    int pageNumberStart; // TODO: probably not used (cf. sections; ale/20130901)
    int folds;
    bool automaticTextFrames;
    int automaticTextFramesColumns;
    qreal automaticTextFramesGap;
    bool guidesLocked;
    bool guidesSnapping;
    bool guidesSnappingElement;
    bool guidesSnappingGrid;
    qreal rulerXOffset;
    qreal rulerYOffset;
};

#endif // DOCUMENTLAYOUT_H
