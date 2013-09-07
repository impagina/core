#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "document_global.h"

#include "global/global.h"

#include <QString>

class Settings;

class DOCUMENTSHARED_EXPORT Document
{
public:
    Document();
    void setVersion(QString version) {this->version = version;}
    void setSettings(Settings *settings) {this->settings = settings;}
protected:
    QString version;
    Settings *settings;
};

#endif // DOCUMENT_H
