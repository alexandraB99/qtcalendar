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

#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QList>
#include <QObject>

#include "calendarevent.h"
#include "standardpaths.h"

class CalendarModel : public QObject
{
    Q_OBJECT

public:
    CalendarModel();

    Q_INVOKABLE QList<QObject*> getEvents(const QDate &date);
    Q_INVOKABLE void addEvent(QString id, QString desc, const QDate &date, QString time);
    Q_INVOKABLE void editEvent(QString id, QString desc);
    Q_INVOKABLE void deleteEvent(QString id);

private:
    static void connectToDatabase();
};

#endif
