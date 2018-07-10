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

import QtQuick 2.0
import QtQuick.Controls 2.0
import com.calendar 1.0

Item {
    id: root

    property var selectedDate

    CalendarModel {
        id: calendarModel
    }

    function updateModel() {
        var model = calendarModel.getEvents(root.selectedDate);
        for (var j = 0; j < dayListModel.count; j++) {
            //clear model
            dayListModel.get(j).description =  "";
            if (model.length > 0) {
                for (var i = 0; i < model.length; i++) {
                    if (model[i].time === dayListModel.get(j).time) {
                        dayListModel.get(j).description = model[i].description;
                    }
                }
            }
        }
        listview.model = dayListModel;
    }

    onSelectedDateChanged: {
        updateModel();
    }

    Item {
        id: headerItem
        width: parent.width
        height: 60
        Rectangle {
            anchors.fill: parent
            color: "green"
            opacity: 0.3
            Button {
                id: button1
                width: 120
                height: 50
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
                text: "Screenshot"
                onClicked: {
                    var stat = root.grabToImage(function(result) {
                        var path = StandardPaths.getDesktopDir() + "/";
                        result.saveToFile(path + dateLabel.text +".png");
                        image.source = result.url;
                        QMLSnapShot.captureWindow(result.image); //result.image holds the QVariant
                    },
                    Qt.size(root.width, root.height));
                    console.log("Success: ", stat);
                }
            }
            Text {
                id: dateLabel
                anchors.right: parent.right
                anchors.rightMargin: 20
                font.pixelSize: 30
                anchors.verticalCenter: parent.verticalCenter
                text: root.selectedDate.toLocaleDateString(Qt.locale("en_US"))
            }
        }
    }

    ListModel {
        id: dayListModel
        ListElement { time: "07:00"; description: "" }
        ListElement { time: "08:00"; description: "" }
        ListElement { time: "09:00"; description: "" }
        ListElement { time: "10:00"; description: "" }
        ListElement { time: "11:00"; description: "" }
        ListElement { time: "12:00"; description: "" }
        ListElement { time: "13:00"; description: "" }
        ListElement { time: "14:00"; description: "" }
        ListElement { time: "15:00"; description: "" }
        ListElement { time: "16:00"; description: "" }
        ListElement { time: "17:00"; description: "" }
        ListElement { time: "18:00"; description: "" }
        ListElement { time: "19:00"; description: "" }
        ListElement { time: "20:00"; description: "" }
        ListElement { time: "21:00"; description: "" }
        ListElement { time: "22:00"; description: "" }
        ListElement { time: "23:00"; description: "" }
        ListElement { time: "24:00"; description: "" }
    }

    clip: true

    ListView {
        id: listview
        width: parent.width
        height: parent.height - 100
        anchors.top: parent.top
        anchors.topMargin: 80
        delegate: ItemDelegate {
            width: parent.width
            height: 60
            contentItem: Item {
                Text {
                    id: hour
                    text: time
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    color: "red"
                    font.pixelSize: 20
                }

                TextEdit {
                    id: textEdit
                    height: parent.height
                    width: parent.width - hour.contentWidth
                    anchors.left: hour.right
                    anchors.leftMargin: 10
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 25
                    text: description
                }
                Row {
                    width: 100
                    height: parent.height
                    anchors.right: parent.right
                    ToolButton {
                        width: 50
                        text: description !== "" ? "edit" : "add"
                        height: parent.height
                        onClicked: {
                            var id = root.selectedDate.toLocaleDateString(Qt.locale("en_US"), "yyyy-MM-dd") + "_" +hour.text;
                            if (text === "add") {
                                calendarModel.addEvent(id, textEdit.text, root.selectedDate, time);
                            } else {
                                calendarModel.editEvent(id, textEdit.text);
                            }
                            root.updateModel();
                        }
                    }
                    ToolButton {
                        width: 50
                        text: "del"
                        height: parent.height
                        onClicked: {
                            var id = root.selectedDate.toLocaleDateString(Qt.locale("en_US"), "yyyy-MM-dd") + "_" +hour.text;
                            calendarModel.deleteEvent(id);
                            root.updateModel();
                        }
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: "black"
                    anchors.bottom: parent.bottom
                }
            }
        }
    }
}
