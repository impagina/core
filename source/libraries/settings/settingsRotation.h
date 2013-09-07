#ifndef SETTINGSROTATION_H
#define SETTINGSROTATION_H

#include "settings_global.h"

#include "global/global.h"

#include <QString>

class SETTINGSSHARED_EXPORT SettingsRotation
{
public:
    SettingsRotation();
    void setStepConstraint(QString stepConstraint) {this->stepConstraint = stepConstraint.TOQREAL();}
protected:
    qreal stepConstraint;
};

#endif // SETTINGSROTATION_H
