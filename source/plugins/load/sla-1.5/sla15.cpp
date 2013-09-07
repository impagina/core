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
#include <document/documentColorManagement.h>
#include <document/documentInformation.h>
#include <style/styleLine.h>
#include <style/styleFill.h>
#include <settings/settings.h>
#include <settings/settingsDuplicateItem.h>
#include <settings/settingsRotation.h>
#include <settings/settingsTypography.h>
#include <style/styleArc.h>
#include <style/styleCalligraphicPen.h>
#include <style/styleCharacter.h>
#include <style/styleFill.h>
#include <style/style_global.h>
#include <style/style.h>
#include <style/styleImage.h>
#include <style/styleLine.h>
#include <style/styleParagraph.h>
#include <style/stylePolygon.h>
#include <style/styleShape.h>
#include <style/styleSpiral.h>

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
                DocumentColorManagement *colorManagement = new DocumentColorManagement();
                DocumentInformation *information = new DocumentInformation();
                SettingsTypography *settingsTypography = new SettingsTypography();

                StyleLine *line;
                StyleFill *fill;

                // layerToSetActive = attrs.valueAsInt("ALAYER", 0); TODO: we have to read the current layer here... but there is no layer, yet! implement as soon as the layers reading has been, too (ale/20130906)
                // m_Doc->clearCheckerProfiles(); TODO: we have to read the current profile here... but there is no profile, yet! implement as soon as the profile reading has been, too (ale/20130906)
                // m_Doc->setCurCheckProfile(attrs.valueAsString("currentProfile"));

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
                colorManagement->setSoftProof(attributes.value("DPSo").toString());
                colorManagement->setSoftProofFull(attributes.value("DPSFo").toString());
                colorManagement->setInUse(attributes.value("DPuse").toString());
                colorManagement->setGamutCheck(attributes.value("DPgam").toString());
                colorManagement->setBlackPoint(attributes.value("DPbla").toString());
                colorManagement->setDefaultMonitorProfile(attributes.value("DPMo").toString());
                colorManagement->setDefaultPrinterProfile(attributes.value("DPpr").toString());
                colorManagement->setDefaultImageRGBProfile(attributes.value("DPIn").toString());
                colorManagement->setDefaultImageCMKYProfile(attributes.value("DPInCMYK").toString());
                colorManagement->setDefaultSolidColorRGBProfile(attributes.value("DPIn2").toString());
                colorManagement->setDefaultSolidColorCMYKProfile(attributes.value("DPIn3").toString());
                colorManagement->setDefaultIntentColors(attributes.value("DISc").toString());
                colorManagement->setDefaultIntentImages(attributes.value("DIIm").toString());

                information->setAuthor(attributes.value("AUTHOR").toString());
                information->setComments(attributes.value("COMMENTS").toString());
                information->setKeywords(attributes.value("KEYWORDS").toString());
                information->setTitle(attributes.value("TITLE").toString());
                information->setSubject(attributes.value("SUBJECT").toString());
                information->setPublisher(attributes.value("PUBLISHER").toString());
                information->setDate(attributes.value("DOCDATE").toString());
                information->setType(attributes.value("DOCTYPE").toString());
                information->setFormat(attributes.value("DOCFORMAT").toString());
                information->setIdent(attributes.value("DOCIDENT").toString());
                information->setSource(attributes.value("DOCSOURCE").toString());
                information->setLanguageInfo(attributes.value("DOCLANGINFO").toString());
                information->setRelation(attributes.value("DOCRELATION").toString());
                information->setCover(attributes.value("DOCCOVER").toString());
                information->setRights(attributes.value("DOCRIGHTS").toString());
                information->setContributor(attributes.value("DOCCONTRIB").toString());

                layout->setMinorGridSpacing(attributes.value("MINGRID").toString());
                layout->setMajorGridSpacing(attributes.value("MAJGRID").toString());
                layout->setGridVisible(attributes.value("SHOWGRID").toString());
                layout->setGuidesVisible(attributes.value("SHOWGUIDES").toString());
                layout->setColumnBordersVisible(attributes.value("showcolborders").toString());
                layout->setFrameVisible(attributes.value("SHOWFRAME").toString());
                layout->setLayerMarkerVisible(attributes.value("SHOWLAYERM").toString());
                layout->setMarginVisible(attributes.value("SHOWMARGIN").toString());
                layout->setBaselineGridVisible(attributes.value("SHOWBASE").toString());
                layout->setImageVisible(attributes.value("SHOWPICT").toString());
                layout->setTextFrameLinkVisible(attributes.value("SHOWLINK").toString());
                layout->setControlCharacterVisible(attributes.value("SHOWControl").toString());
                layout->setRulersVisible(attributes.value("showrulers").toString());
                layout->setRulerRelativeToPage(attributes.value("rulerMode").toString());
                layout->setBleedVisible(attributes.value("showBleed").toString());
                layout->setMarginColor(attributes.value("MARGC").toString());
                layout->setMinorGridColor(attributes.value("MINORC").toString());
                layout->setMajorGridColor(attributes.value("MAJORC").toString());
                layout->setGuideColor(attributes.value("GuideC").toString());
                layout->setBaselineGridColor(attributes.value("BaseC").toString());
                layout->setRenderStackOrder(attributes.value("renderStack").toString());
                layout->setGridType(attributes.value("GridType").toString());
                layout->setGuideGrabRadius(attributes.value("GuideRad").toString());
                layout->setHandleGrabRadius(attributes.value("GRAB").toString());

                // TODO: not sure yet, if Tool should be in settings, or if we should have tool/ directory (ale/20130903)
                StyleCharacter *styleCharacter = new StyleCharacter();
                StyleParagraph *styleParagraph = new StyleParagraph();
                StylePolygon *stylePolygon = new StylePolygon();
                StyleArc *styleArc = new StyleArc();
                StyleSpiral *styleSpiral = new StyleSpiral();
                StyleLine *styleLine = new StyleLine();
                StyleImage *styleImage = new StyleImage();
                StyleShape *styleShape = new StyleShape();
                StyleCalligraphicPen *styleCalligraphicPen = new StyleCalligraphicPen();
                SettingsDuplicateItem *settingsDuplicateItem = new SettingsDuplicateItem();
                SettingsRotation *settingsRotation = new SettingsRotation();

                styleCharacter->setFont(attributes.value("DFONT").toString());
                styleCharacter->setSize(attributes.value("DSIZE").toString());
                styleCharacter->setColumns(attributes.value("DCOL").toString());
                styleCharacter->setColumnGap(attributes.value("DGAP").toString());
                styleCharacter->setColor(attributes.value("PENTEXT").toString());
                styleCharacter->setStrokeColor(attributes.value("StrokeText").toString());
                styleCharacter->setFillColor(attributes.value("TextBackGround").toString());
                styleCharacter->setLineColor(attributes.value("TextLineColor").toString());
                styleCharacter->setFillColorShade(attributes.value("TextBackGroundShade").toString());
                styleCharacter->setLineColorShade(attributes.value("TextLineShade").toString());
                styleCharacter->setShade(attributes.value("TextPenShade").toString());
                styleCharacter->setStrokeShade(attributes.value("TextStrokeShade").toString());

                styleParagraph->setTabFillChar(attributes.value("TabFill").toString());
                styleParagraph->setTabWidth(attributes.value("TabWidth").toString());

                styleImage->setScaleX(attributes.value("PICTSCX").toString());
                styleImage->setScaleY(attributes.value("PICTSCY").toString());
                styleImage->setScaleType(attributes.value("PSCALE").toString());
                styleImage->setAspectRatio(attributes.value("PASPECT").toString());
                styleImage->setLowResType(attributes.value("HalfRes").toString());
                styleImage->setUseEmbeddedPath(attributes.value("EmbeddedPath").toString());
                fill = styleImage->getFill();
                fill->setColor(attributes.value("CPICT").toString());
                fill->setColorShading(attributes.value("PICTSHADE").toString());
                line = styleImage->getLine();
                line->setColor(attributes.value("CSPICT").toString());
                line->setColorShading(attributes.value("PICTSSHADE").toString());

                line = styleShape->getLine();
                line->setColor(attributes.value("PEN").toString());
                line->setStyle(attributes.value("STIL").toString());
                line->setWidth(attributes.value("WIDTH").toString());
                line->setColorShading(attributes.value("PENSHADE").toString());
                fill = styleShape->getFill();
                fill->setColor(attributes.value("BRUSH").toString());
                fill->setColorShading(attributes.value("BRUSHSHADE").toString());

                stylePolygon->setCorners(attributes.value("POLYC").toString());
                stylePolygon->setConvexityFactor(attributes.value("POLYF").toString());
                stylePolygon->setRotation(attributes.value("POLYR").toString());
                stylePolygon->setRotationInner(attributes.value("POLYIR").toString());
                stylePolygon->setCurvatureInner(attributes.value("POLYCUR").toString());
                stylePolygon->setCurvatureOuter(attributes.value("POLYOCUR").toString());
                stylePolygon->setFactorEnabled(attributes.value("POLYS").toString());

                styleLine->setArrowStart(attributes.value("StartArrow").toString());
                styleLine->setArrowEnd(attributes.value("EndArrow").toString());
                styleLine->setColor(attributes.value("PENLINE").toString());
                styleLine->setStyle(attributes.value("STILLINE").toString());
                styleLine->setWidth(attributes.value("WIDTHLINE").toString());
                styleLine->setColorShading(attributes.value("LINESHADE").toString());

                styleSpiral->setAngleStart(attributes.value("spiralStartAngle").toString());
                styleSpiral->setAngleEnd(attributes.value("spiralEndAngle").toString());
                styleSpiral->setFactor(attributes.value("spiralFactor").toString());

                styleArc->setAngleStart(attributes.value("arcStartAngle").toString());
                styleArc->setAngleEnd(attributes.value("arcSweepAngle").toString());

                line = styleCalligraphicPen->getLine();
                line->setColor(attributes.value("calligrapicPenLineColor").toString());
                line->setColorShading(attributes.value("calligrapicPenLineColorShade").toString());
                line->setWidth(attributes.value("calligrapicPenLineWidth").toString());
                line->setStyle(attributes.value("calligrapicPenStyle").toString());
                fill = styleCalligraphicPen->getFill();
                fill->setColor(attributes.value("calligrapicPenFillColor").toString());
                fill->setColorShading(attributes.value("calligrapicPenFillColorShade").toString());
                styleCalligraphicPen->setAngle(attributes.value("calligrapicPenAngle").toString());
                styleCalligraphicPen->setWidth(attributes.value("calligrapicPenWidth").toString());

                settingsDuplicateItem->setDisplacementX(attributes.value("dispX").toString());
                settingsDuplicateItem->setDisplacementY(attributes.value("dispY").toString());

                settingsRotation->setStepConstraint(attributes.value("constrain").toString());
                // TODO: check why it's missing the zoom (ale/20130903)

                settingsTypography->setSuperscriptDisplacement(attributes.value("VHOCH").toString());
                settingsTypography->setSuperscriptScaling(attributes.value("VHOCHSC").toString());
                settingsTypography->setSubscriptDisplacement(attributes.value("VTIEF").toString());
                settingsTypography->setSubscriptScaling(attributes.value("VTIEFSC").toString());
                settingsTypography->setSmallCaps(attributes.value("VKAPIT").toString());
                settingsTypography->setBaselineGrid(attributes.value("BASEGRID").toString());
                settingsTypography->setBaselineGridOffset(attributes.value("BASEO").toString());
                settingsTypography->setLineSpacingAuto(attributes.value("AUTOL").toString());
                settingsTypography->setUnderlineDisplacement(attributes.value("UnderlinePos").toString());
                settingsTypography->setUnderlineWidth(attributes.value("UnderlineWidth").toString());
                settingsTypography->setValueStrikeoutDisplacement(attributes.value("StrikeThruPos").toString());
                settingsTypography->setValueStrikeoutWidth(attributes.value("StrikeThruWidth").toString());

                settings->setLayout(layout);
                settings->setPage(page);
                settings->setTypography(typography);
                settings->setColorManagement(colorManagement);
                settings->setInformation(information);
                settings->setCharacter(styleCharacter);
                settings->setParagraph(styleParagraph);
                settings->setPolygon(stylePolygon);
                settings->setArc(styleArc);
                settings->setSpiral(styleSpiral);
                settings->setLine(styleLine);
                settings->setImage(styleImage);
                settings->setShape(styleShape);
                settings->setCalligraphicPen(styleCalligraphicPen);
                settings->setDuplicateItem(settingsDuplicateItem);
                settings->setRotation(settingsRotation);
                settings->setTypographySettings(settingsTypography);

                document->setSettings(settings);
                // qDebug() << "document" << document;
            }
         }
    }

    return true;
}

Q_EXPORT_PLUGIN2(loadSla15, LoadSla15)
