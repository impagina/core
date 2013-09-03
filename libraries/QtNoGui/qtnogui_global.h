#ifndef QTNOGUI_GLOBAL_H
#define QTNOGUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTNOGUI_LIBRARY)
#  define QTNOGUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTNOGUISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTNOGUI_GLOBAL_H
