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

#ifndef CALENDAREVENT_H
#define CALENDAREVENT_H

#include <QDateTime>
#include <QObject>
#include <QString>

class CalendarEvent : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)

public:
    explicit CalendarEvent(QObject *parent = 0);

    QString description() const;
    void setDescription(const QString &description);

    QString date() const;
    void setDate(const QString &date);

    QString time() const;
    void setTime(const QString &time);

signals:
    void descriptionChanged(const QString &description);
    void dateChanged(const QString &date);
    void timeChanged(const QString &time);

private:
    QString mDescription;
    QString mDate;
    QString mTime;
};

#endif
