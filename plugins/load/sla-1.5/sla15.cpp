#include "sla15.h"
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
#include <document/document.h>

QString LoadSla15::getName()
{
    return SCRIBUSPLUGINNAME;
}

/**
  *
  */
bool LoadSla15::loadFile(QString filename)
{
    QFile *file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    // TODO: it seams that Document should be compiled as a library and not in the executable to be accessed in a plugin
    document = new Document();


    QXmlStreamReader *xmlReader = new QXmlStreamReader(file);
    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }

        if(token == QXmlStreamReader::StartElement)
        {
            qDebug() << "xml item name" << xmlReader->name();
            if(xmlReader->name() == "name") {
                continue;
            }
            if(xmlReader->name() == "id") {
                qDebug() << xmlReader->readElementText();
            }
         }
    }

    return true;
}

Q_EXPORT_PLUGIN2(loadSla15, LoadSla15)
