#ifndef DOCUMENTLAYOUT_H
#define DOCUMENTLAYOUT_H

#include "document_global.h"
#include <QString>
#include <QList>

#include "global/global.h"

#include "thirdparty/QtNoGui/qcolor.h"

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

    void setMinorGridSpacing(QString minorGridSpacing) {this->minorGridSpacing = minorGridSpacing.TOQREAL();}
    void setMajorGridSpacing(QString majorGridSpacing) {this->majorGridSpacing = majorGridSpacing.TOQREAL();}
    void setGridVisible(QString gridVisible) {this->gridVisible = gridVisible.TOBOOL();}
    void setGuidesVisible(QString guidesVisible) {this->guidesVisible = guidesVisible.TOBOOL();}
    void setColumnBordersVisible(QString columnBordersVisible) {this->columnBordersVisible = columnBordersVisible.TOBOOL();}
    void setFrameVisible(QString frameVisible) {this->frameVisible = frameVisible.TOBOOL();}
    void setLayerMarkerVisible(QString layerMarkerVisible) {this->layerMarkerVisible = layerMarkerVisible.TOBOOL();}
    void setMarginVisible(QString marginVisible) {this->marginVisible = marginVisible.TOBOOL();}
    void setBaselineGridVisible(QString baselineGridVisible) {this->baselineGridVisible = baselineGridVisible.TOBOOL();}
    void setImageVisible(QString imageVisible) {this->imageVisible = imageVisible.TOBOOL();}
    void setTextFrameLinkVisible(QString textFrameLinkVisible) {this->textFrameLinkVisible = textFrameLinkVisible.TOBOOL();}
    void setControlCharacterVisible(QString controlCharacterVisible) {this->controlCharacterVisible = controlCharacterVisible.TOBOOL();}
    void setRulersVisible(QString rulersVisible) {this->rulersVisible = rulersVisible.TOBOOL();}
    void setRulerRelativeToPage(QString rulerRelativeToPage) {this->rulerRelativeToPage = rulerRelativeToPage.TOBOOL();}
    void setBleedVisible(QString bleedVisible) {this->bleedVisible = bleedVisible.TOBOOL();}
    void setMarginColor(QString marginColor) {if (marginColor != "") {this->marginColor = QColor(marginColor);}}
    void setMinorGridColor(QString minorGridColor) {if (minorGridColor != "") {this->minorGridColor = QColor(minorGridColor);}}
    void setMajorGridColor(QString majorGridColor) {if (majorGridColor != "") {this->majorGridColor = QColor(majorGridColor);}}
    void setGuideColor(QString guideColor) {if (guideColor != "") {this->guideColor = QColor(guideColor);}}
    void setBaselineGridColor(QString baselineGridColor) {if (baselineGridColor != "") {this->baselineGridColor = QColor(baselineGridColor);}}
    void setRenderStackOrder(QString renderStackOrder)
    {
        if (renderStackOrder != "") // TODO: take care that it should be initialized to the QList corresponding to 0 1 2 3 4 (ale/20130903)
        {
            foreach (QString item, renderStackOrder.split(" "))
            {
                this->renderStackOrder << item.toInt();
            }
        }
    }
    void setGridType(QString gridType) {this->gridType = gridType.toInt();}
    void setGuideGrabRadius(QString guideGrabRadius) {this->guideGrabRadius = guideGrabRadius.TOQREAL();}
    void setHandleGrabRadius(QString handleGrabRadius) {this->handleGrabRadius = handleGrabRadius.toInt();}

protected:
    qreal pageNumberStart; // TODO: probably not used (cf. sections; ale/20130901)
    qreal folds;
    bool automaticTextFrames;
    int automaticTextFramesColumns;
    qreal automaticTextFramesGap;
    bool guidesLocked;
    bool guidesSnapping;
    bool guidesSnappingElement;
    bool guidesSnappingGrid;
    qreal rulerXOffset;
    qreal rulerYOffset;

    bool minorGridSpacing;
    bool majorGridSpacing;
    bool gridVisible;
    bool guidesVisible;
    bool columnBordersVisible;
    bool frameVisible;
    bool layerMarkerVisible;
    bool marginVisible;
    bool baselineGridVisible;
    bool imageVisible;
    bool textFrameLinkVisible;
    bool controlCharacterVisible;
    bool rulersVisible;
    bool rulerRelativeToPage;
    bool bleedVisible;
    QColor marginColor;
    QColor minorGridColor;
    QColor majorGridColor;
    QColor guideColor;
    QColor baselineGridColor;
    QList<int> renderStackOrder;
    int gridType;
    qreal guideGrabRadius;
    int handleGrabRadius;
};

#endif // DOCUMENTLAYOUT_H
