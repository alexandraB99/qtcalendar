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

#include "calendarmodel.h"

#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

CalendarModel::CalendarModel()
{
    connectToDatabase();
}

void CalendarModel::addEvent(QString id, QString desc, const QDate &date, QString time)
{
    QSqlQuery query;
    query.prepare("INSERT INTO events (id, description, date, time) "
                      "VALUES (:id, :desc, :date, :time)");
    query.bindValue(":id", id);
    query.bindValue(":desc", desc);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":time", time);

    if (!query.exec()) {
        qDebug () << "Query failed" << query.lastError();
    }
}

void CalendarModel::editEvent(QString id, QString desc)
{
    QSqlQuery query;
    query.prepare("UPDATE events SET description=:desc WHERE id=:id");
    query.bindValue(":desc",desc);
    query.bindValue(":id",id);

    if (!query.exec()) {
        qDebug () << "Query failed" << query.lastError();
    }
}

void CalendarModel::deleteEvent(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM events WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug () << "Query failed" << query.lastError();
    }
}

QList<QObject*> CalendarModel::getEvents(const QDate &date)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM events WHERE date=:date");
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug () << "Query failed" << query.lastError();
    }

    QList<QObject*> events;
    while (query.next()) {
        CalendarEvent *event = new CalendarEvent(this);

        event->setDescription(query.value("description").toString());
        event->setDate(query.value("date").toString());
        event->setTime(query.value("time").toString());

        events.append(event);
    }

    return events;
}

void CalendarModel::connectToDatabase()
{
    StandardPaths standardPaths;
    QString path = standardPaths.getHomeDir().join("") +"/calendar.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (!db.open()) {
        qWarning("Cannot open database");
        return;
    }

    QSqlQuery query;
    query.exec("create table events (id TEXT, description TEXT, date DATE, time TEXT)");

    return;
}
