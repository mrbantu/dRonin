/**
******************************************************************************
*
* @file       accessmode.h
* @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
* @author     Tau Labs, http://taulabs.org, Copyright (C) 2013
* @brief      
* @see        The GNU Public License (GPL) Version 3
* @defgroup   TLMapWidget
* @{
* 
*****************************************************************************/
/* 
* This program is free software; you can redistribute it and/or modify 
* it under the terms of the GNU General Public License as published by 
* the Free Software Foundation; either version 3 of the License, or 
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful, but 
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
* for more details.
* 
* You should have received a copy of the GNU General Public License along 
* with this program; if not, see <http://www.gnu.org/licenses/>
*/
#ifndef ACCESSMODE_H
#define ACCESSMODE_H

#include "debugheader.h"
#include <QObject>
#include <QMetaObject>
#include <QMetaEnum>
#include <QStringList>
#include "corecommon.h"

namespace core {
    class TLMAPWIDGET_EXPORT AccessMode:public QObject
    {
        Q_OBJECT
        Q_ENUMS(Types)
    public:
        enum Types
        {
            /// <summary>
            /// access only server
            /// </summary>
            ServerOnly,

            /// <summary>
            /// access first server and caches localy
            /// </summary>
            ServerAndCache,

            /// <summary>
            /// access only cache
            /// </summary>
            CacheOnly
        };
        static QString StrByType(Types const& value)
        {
            QMetaObject metaObject = AccessMode().staticMetaObject;
            QMetaEnum metaEnum= metaObject.enumerator( metaObject.indexOfEnumerator("Types"));
            QString s=metaEnum.valueToKey(value);
            return s;
        }
        static Types TypeByStr(QString const& value)
        {
            QMetaObject metaObject = AccessMode().staticMetaObject;
            QMetaEnum metaEnum= metaObject.enumerator( metaObject.indexOfEnumerator("Types"));
            Types s=(Types)metaEnum.keyToValue(value.toLatin1());
            return s;
        }
        static QStringList TypesList()
        {
            QStringList ret;
            QMetaObject metaObject = AccessMode().staticMetaObject;
            QMetaEnum metaEnum= metaObject.enumerator( metaObject.indexOfEnumerator("Types"));
            for(int x=0;x<metaEnum.keyCount();++x)
            {
                ret.append(metaEnum.key(x));
            }
            return ret;
        }

    };
}
#endif // ACCESSMODE_H
