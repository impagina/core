/****************************************************************************
**
** This file contains the parts of QColor_p relevant to this project.
** It's used in place of the original in order to avoid the dependence to QtGui
**
** This file is extracted from the the QtGui module of the Qt Toolkit.
** Copyright (C) LGPL 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
** Details: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/

#ifndef QCOLOR_P_H
#define QCOLOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtCore/qglobal.h"
#include "qrgb.h"
#include "QtCore/qstringlist.h"

uint qt_get_rgb_val(const char *name);
bool qt_get_named_rgb(const char *, QRgb*);
bool qt_get_named_rgb(const QChar *, int len, QRgb*);
bool qt_get_hex_rgb(const char *, QRgb *);
bool qt_get_hex_rgb(const QChar *, int len, QRgb *);
QStringList qt_get_colornames();

#endif // QCOLOR_P_H
