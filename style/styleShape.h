#ifndef STYLESHAPE_H
#define STYLESHAPE_H

#include "style_global.h"

#include <QString>

#include "style/styleLine.h"
#include "style/styleFill.h"

class STYLESHARED_EXPORT StyleShape
{
public:
    StyleShape();
    StyleLine *getLine() {return this->line;}
    StyleFill *getFill() {return this->fill;}
protected:
    StyleLine *line;
    StyleFill *fill;
};

#endif // STYLESHAPE_H
