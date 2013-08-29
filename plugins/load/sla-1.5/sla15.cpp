#include "sla15.h"

QString LoadSla15::getName()
{
    return SCRIBUSPLUGINNAME;
}

Q_EXPORT_PLUGIN2(loadSla15, LoadSla15)
