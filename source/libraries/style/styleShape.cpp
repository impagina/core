#include "style/styleShape.h"
#include "style/styleLine.h"
#include "style/styleFill.h"

StyleShape::StyleShape()
{
    line = new StyleLine();
    fill = new StyleFill();
}
