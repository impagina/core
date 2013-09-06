#ifndef SETTINGSDUPLICATEITEM_H
#define SETTINGSDUPLICATEITEM_H

#include "settings_global.h"

#include "global/global.h"

#include <QString>

class SETTINGSSHARED_EXPORT SettingsDuplicateItem
{
public:
    SettingsDuplicateItem();
    void setDisplacementX(QString displacementX) {this->displacementX = displacementX.TOQREAL();}
    void setDisplacementY(QString displacementY) {this->displacementY = displacementY.TOQREAL();}
protected:
    qreal displacementX;
    qreal displacementY;
};

#endif // SETTINGSDUPLICATEITEM_H
