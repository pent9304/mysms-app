/****************************************************************************
**
** mysms App - Send & receive all your SMS on your Notebook, PC or tablet – like on your smartphone
** Copyright (C) 2011 sms.at mobile internet services gmbh
** All rights reserved.
**
**
** This library is free software.  either version 2.1 of the License, or (at your option) any later version.
** you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation;
** either version 2.1 of the License, or (at your option) any later version.
**
**
** This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** Without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License along with this library;
** if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
**
****************************************************************************/

#include "jsinterface.h"

JsInterface::JsInterface(QSystemTrayIcon *trayIcon, QObject *parent)
    : QObject(parent), m_trayIcon(trayIcon)
{
}

void JsInterface::showNotification(const QString &imageUrl, const QString &title, const QString &body) {
    m_trayIcon->showMessage(title, body, QSystemTrayIcon::NoIcon, 15000);
}

void JsInterface::setBadgeCounter(const int badgeCounter) {
    QIcon *icon;
    if (badgeCounter > 9) {
        icon = new QIcon(":/resource/icon-9.png");
    } else if (badgeCounter == 0) {
        icon = new QIcon(":/resource/icon.png");
    } else {
        icon = new QIcon(QString(":/resource/icon-%1.png").arg(badgeCounter));
    }
    m_trayIcon->setIcon(*icon);
    delete icon;
}

void JsInterface::openExternalUrl(const QString &url) {
    QDesktopServices::openUrl(QUrl(url));
}
