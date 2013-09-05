#ifndef DOCUMENTCOLORMANAGEMENT_H
#define DOCUMENTCOLORMANAGEMENT_H

#include "document_global.h"

#include <QString>

#include "global/global.h"

class DOCUMENTSHARED_EXPORT DocumentColorManagement
{
public:
    DocumentColorManagement();
    void setSoftProof(QString softProof) {this->softProof = softProof.TOBOOL();}
    void setSoftProofFull(QString SoftProofFull) {this->SoftProofFull = SoftProofFull.TOBOOL();}
    void setInUse(QString inUse) {this->inUse = inUse.TOBOOL();}
    void setGamutCheck(QString gamutCheck) {this->gamutCheck = gamutCheck.TOBOOL();}
    void setBlackPoint(QString blackPoint) {this->blackPoint = blackPoint.TOBOOL();}
    void setDefaultMonitorProfile(QString defaultMonitorProfile) {this->defaultMonitorProfile = defaultMonitorProfile.toInt();}
    void setDefaultPrinterProfile(QString defaultPrinterProfile) {this->defaultPrinterProfile = defaultPrinterProfile;}
    void setDefaultImageRGBProfile(QString defaultImageRGBProfile) {this->defaultImageRGBProfile = defaultImageRGBProfile;}
    void setDefaultImageCMKYProfile(QString defaultImageCMKYProfile) {this->defaultImageCMKYProfile = defaultImageCMKYProfile;}
    void setDefaultSolidColorRGBProfile(QString defaultSolidColorRGBProfile) {this->defaultSolidColorRGBProfile = defaultSolidColorRGBProfile;}
    /* warning: getSolidColor should return defaultPrinterProfile if it's empty (ale/20130903)
    if (attrs.hasAttribute("DPIn3"))
        doc->cmsSettings().DefaultSolidColorCMYKProfile = attrs.valueAsString("DPIn3","");
    else
        doc->cmsSettings().DefaultSolidColorCMYKProfile = attrs.valueAsString("DPPr","");
    */
    void setDefaultSolidColorCMYKProfile(QString defaultSolidColorCMYKProfile) {this->defaultSolidColorCMYKProfile = defaultSolidColorCMYKProfile;}
    void setDefaultIntentColors(QString defaultIntentColors) {this->defaultIntentColors = defaultIntentColors.toInt();}
    void setDefaultIntentImages(QString defaultIntentImages) {this->defaultIntentImages = defaultIntentImages.toInt();}
protected:
    bool softProof;
    bool SoftProofFull;
    bool inUse;
    bool gamutCheck;
    bool blackPoint;
    bool defaultMonitorProfile;
    QString defaultPrinterProfile;
    QString defaultImageRGBProfile;
    QString defaultImageCMKYProfile;
    QString defaultSolidColorRGBProfile;
    QString defaultSolidColorCMYKProfile;
    int defaultIntentColors;
    int defaultIntentImages;
};

#endif // DOCUMENTCOLORMANAGEMENT_H
