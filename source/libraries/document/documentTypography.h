#ifndef DOCUMENTTYPOGRAPHY_H
#define DOCUMENTTYPOGRAPHY_H

#include "document_global.h"
#include <QString>

#include "global/global.h"

class DOCUMENTSHARED_EXPORT DocumentTypography
{

public:
    DocumentTypography();
    void setHyphenationLanguage(QString language) {hyphenationLanguage = language;}
    void setHyphenationMinimumWordLength(QString length) {hyphenationMinimumWordLength = length.toInt();}
    void setHyphenationConsecutiveLines(QString count) {hyphenationConsecutiveLines = count.toInt();}
    void setHyphenationAutomatic(QString automatic) {hyphenationAutomatic = automatic.TOBOOL();}
protected:
    QString hyphenationLanguage; // TODO: not sure that the ISO code is the best thing to store... (cf. scribus: TypographyManager::instance()->langTableIndex(l); ale/20130831)
    int hyphenationMinimumWordLength /* = 3 */;
    int hyphenationConsecutiveLines /* = 2 */;
    bool hyphenationAutomatic;
};

#endif // DOCUMENTTYPOGRAPHY_H
