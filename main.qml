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

import QtQml 2.2
import QtQuick 2.7
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 550
    height: 1300
    title: new Date().toLocaleDateString(Qt.locale("en_US"));

    Calendar {
        id: calendar
        width: parent.width
        height: 400
    }

    DaySchedule {
        id: daySchedule
        anchors.top: calendar.bottom
        width: parent.width
        height: (parent.height - calendar.height)
        selectedDate: calendar.selectedDate
    }
}
