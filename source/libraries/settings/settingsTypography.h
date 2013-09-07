#ifndef SETTINGSTYPOGRAPHY_H
#define SETTINGSTYPOGRAPHY_H

#include "settings_global.h"
#include "global/global.h"

#include <QString>

class SETTINGSSHARED_EXPORT SettingsTypography
{
public:
    SettingsTypography();
    void setSuperscriptDisplacement(QString superscriptDisplacement) {this->superscriptDisplacement = superscriptDisplacement.toInt();}
    void setSuperscriptScaling(QString superscriptScaling) {this->superscriptScaling = superscriptScaling.toInt();}
    void setSubscriptDisplacement(QString subscriptDisplacement) {this->subscriptDisplacement = subscriptDisplacement.toInt();}
    void setSubscriptScaling(QString subscriptScaling) {this->subscriptScaling = subscriptScaling.toInt();}
    void setSmallCaps(QString smallCaps) {this->smallCaps = smallCaps.toInt();}
    void setBaselineGrid(QString baselineGrid) {this->baselineGrid = baselineGrid.TOQREAL();}
    void setBaselineGridOffset(QString baselineGridOffset) {this->baselineGridOffset = baselineGridOffset.TOQREAL();}
    void setLineSpacingAuto(QString lineSpacingAuto) {this->lineSpacingAuto = lineSpacingAuto.toInt();}
    void setUnderlineDisplacement(QString underlineDisplacement) {this->underlineDisplacement = underlineDisplacement.toInt();}
    void setUnderlineWidth(QString underlineWidth) {this->underlineWidth = underlineWidth.toInt();}
    void setValueStrikeoutDisplacement(QString valueStrikeoutDisplacement) {this->valueStrikeoutDisplacement = valueStrikeoutDisplacement.toInt();}
    void setValueStrikeoutWidth(QString valueStrikeoutWidth) {this->valueStrikeoutWidth = valueStrikeoutWidth.toInt();}
protected:
    int superscriptDisplacement;
    int superscriptScaling;
    int subscriptDisplacement;
    int subscriptScaling;
    int smallCaps;
    qreal baselineGrid;
    qreal baselineGridOffset;
    int lineSpacingAuto;
    int underlineDisplacement;
    int underlineWidth;
    int valueStrikeoutDisplacement;
    int valueStrikeoutWidth;
};

#endif // SETTINGSTYPOGRAPHY_H
