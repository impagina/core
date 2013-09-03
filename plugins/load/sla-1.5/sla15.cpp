/**
  * Load a Scribus 1.5.0svn file
  */

#include "sla15.h"
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
#include <document/document.h>
#include <document/documentLayout.h>
#include <document/documentPage.h>
#include <document/documentTypography.h>
#include <settings/settings.h>
#include <QHash>

#define XML_HAS_NEXT(XML) (\
    !XML-atEnd() && !XML->hasError()\
    )

QString LoadSla15::getName()
{
    return SCRIBUSPLUGINNAME;
}

bool LoadSla15::loadFile(QString filename)
{
    QFile *file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    // TODO: it seams that Document should be compiled as a library
    // and not in the executable to be accessed in a plugin
    document = new Document();


    QXmlStreamReader *xml = new QXmlStreamReader(file);
    QXmlStreamReader::TokenType token;
    QXmlStreamAttributes attributes;
    QString element;
    while(!xml->atEnd() && !xml->hasError())
    {
        token = xml->readNext();
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        // TODO: uncomment if we're only interested in the start elements
        // if (tType != QXmlStreamReader::StartElement)
        //    continue;

        if(token == QXmlStreamReader::StartElement)
        {
            // qDebug() << "xml item name" << xml->name();
            element = xml->name().toString();
            if(element == "SCRIBUSUTF8NEW") {
                document->setVersion(xml->attributes().value("Version").toString());
            }
            if (element == "DOCUMENT")
            {
                attributes = xml->attributes();
                // qDebug() << xml->readElementText();
                Settings *settings = new Settings();
                DocumentLayout *layout = new DocumentLayout();
                DocumentPage *page = new DocumentPage();
                DocumentTypography *typography = new DocumentTypography();

                page->setSize(attributes.value("PAGESIZE").toString());
                page->setOrientationPortrait(attributes.value("ORIENTATION").toString() == "0");
                page->setWidth(attributes.value("PAGEWIDTH").toString());
                page->setHeight(attributes.value("PAGEHEIGHT").toString());
                page->setMargins(
                    attributes.value("BORDERTOP").toString(),
                    attributes.value("BORDERRIGHT").toString(),
                    attributes.value("BORDERBOTTOM").toString(),
                    attributes.value("BORDERLEFT").toString()
                );
                page->setMarginsTemplate(attributes.value("PRESET").toString());
                page->setBleed(attributes.value("BleedTop").toString()); // ignore the other bleed: they should always all be equal
                settings->setLengthUnit(attributes.value("UNITS").toString());
                layout->setPageNumberStart(attributes.value("FIRSTNUM").toString()); // TODO: probably not used (cf. sections; ale/20130901)
                layout->setFolds(attributes.value("BOOK").toString());
                layout->setAutomaticTextFrames(attributes.value("AUTOTEXT").toString());
                layout->setAutomaticTextFramesColumns(attributes.value("AUTOSPALTEN").toString());
                layout->setAutomaticTextFramesGap(attributes.value("ABSTSPALTEN").toString());
                typography->setHyphenationLanguage(attributes.value("LANGUAGE").toString());
                typography->setHyphenationMinimumWordLength(attributes.value("MINWORDLEN").toString());
                typography->setHyphenationConsecutiveLines(attributes.value("HYCOUNT").toString());
                typography->setHyphenationAutomatic(attributes.value("AUTOMATIC").toString());
                layout->setGuidesLocked(attributes.value("GUIDELOCK").toString());
                layout->setGuidesSnapping(attributes.value("SnapToGuides").toString());
                layout->setGuidesSnappingElement(attributes.value("SnapToElement").toString());
                layout->setGuidesSnappingGrid(attributes.value("SnapToGrid").toString());
                layout->setRulerXOffset(attributes.value("rulerXoffset").toString());
                layout->setRulerYOffset(attributes.value("rulerYoffset").toString());
                settings->setAutomaticSave(attributes.value("AutoSave").toString());
                settings->setAutomaticSaveTime(attributes.value("AutoSaveTime").toString());
                settings->setScratchSpace(
                    attributes.value("ScratchTop").toString(),
                    attributes.value("ScratchRight").toString(),
                    attributes.value("ScratchBottom").toString(),
                    attributes.value("ScratchLeft").toString()
                );
                settings->setPageGapHorizontal(attributes.value("GapHorizontal").toString());
                settings->setPageGapVertical(attributes.value("GapVertical").toString());
                settings->setPaperColor(attributes.value("PAGEC").toString());
                settings->setMarginAreaCovered(attributes.value("RANDF").toString());

                settings->setLayout(layout);
                settings->setPage(page);
                settings->setTypography(typography);
                document->setSettings(settings);
                // qDebug() << "document" << document;
                /*
                readCMSSettings(doc, attrs);
                readDocumentInfo(doc, attrs);
                readGuideSettings(doc, attrs);
                readToolSettings(doc, attrs);
                readTypographicSettings(doc, attrs);
                */
            }
         }
    }

    return true;
}

Q_EXPORT_PLUGIN2(loadSla15, LoadSla15)
