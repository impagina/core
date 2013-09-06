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
class DocumentColorManagement;
class DocumentInformation;
class StyleCharacter;
class StyleParagraph;
class StylePolygon;
class StyleArc;
class StyleSpiral;
class StyleLine;
class StyleImage;
class StyleShape;
class StyleCalligraphicPen;
class SettingsDuplicateItem;
class SettingsRotation;
class SettingsTypography;

class SETTINGSSHARED_EXPORT Settings
{
public:
    Settings();
    void setPage(DocumentPage *page) {this->page = page;}
    void setLayout(DocumentLayout *layout) {this->layout = layout;}
    void setTypography(DocumentTypography *typography) {this->typography = typography;}
    void setColorManagement(DocumentColorManagement *colorManagement) {this->colorManagement = colorManagement;}
    void setInformation(DocumentInformation *information) {this->information = information;}
    void setCharacter(StyleCharacter *character) {this->character = character;}
    void setParagraph(StyleParagraph *paragraph) {this->paragraph = paragraph;}
    void setPolygon(StylePolygon *polygon) {this->polygon = polygon;}
    void setArc(StyleArc *arc) {this->arc = arc;}
    void setSpiral(StyleSpiral *spiral) {this->spiral = spiral;}
    void setLine(StyleLine *line) {this->line = line;}
    void setImage(StyleImage *image) {this->image = image;}
    void setShape(StyleShape *shape) {this->shape = shape;}
    void setCalligraphicPen(StyleCalligraphicPen *calligraphicPen) {this->calligraphicPen = calligraphicPen;}
    void setDuplicateItem(SettingsDuplicateItem *duplicateItem) {this->duplicateItem = duplicateItem;}
    void setRotation(SettingsRotation *rotation) {this->rotation = rotation;}
    void setTypographySettings(SettingsTypography *typography) {this->typographySettings = typography;}

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
    // used for document settings
    DocumentPage *page;
    DocumentLayout *layout;
    DocumentTypography *typography;
    DocumentColorManagement *colorManagement;
    DocumentInformation *information;
    StyleCharacter *character;
    StyleParagraph *paragraph;
    StylePolygon *polygon;
    StyleArc *arc;
    StyleSpiral *spiral;
    StyleLine *line;
    StyleImage *image;
    StyleShape *shape;
    StyleCalligraphicPen *calligraphicPen;
    SettingsDuplicateItem *duplicateItem;
    SettingsRotation *rotation;
    SettingsTypography *typographySettings;

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
