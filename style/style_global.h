#ifndef STYLE_GLOBAL_H
#define STYLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STYLE_LIBRARY)
#  define STYLESHARED_EXPORT Q_DECL_EXPORT
#else
#  define STYLESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // STYLE_GLOBAL_H
