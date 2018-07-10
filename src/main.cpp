/*
 * MyQtCalendar - a simple Qt/QML calendar application
 * Copyright (C) 2018 Alexandra Betouni <alexandra.betouni@protonmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWebEngine/QtWebEngine>
#include "calendarmodel.h"
#include <qmlsnapshot.h>
#include <standardpaths.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QMLSnapShot qmlSnapShot;
    StandardPaths standardPaths;

    qmlRegisterType<CalendarModel>("com.calendar", 1, 0, "CalendarModel");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("QMLSnapShot", &qmlSnapShot);
    engine.rootContext()->setContextProperty("StandardPaths", &standardPaths);
    engine.load(QUrl(QLatin1String("main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
