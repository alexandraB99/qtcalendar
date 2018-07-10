TEMPLATE = app
TARGET = myqtcalendar

macos:CONFIG -= app_bundle
CONFIG += c++11

QT += quick printsupport widgets sql core

QMAKE_RPATHDIR += $$OUT_PWD/../3rdParty/qmlsnapshot
INCLUDEPATH += $$PWD/../3rdParty/qmlsnapshot
LIBS += -L$$OUT_PWD/../3rdParty/qmlsnapshot -lqmlsnapshot

HEADERS += \
           calendarmodel.h \
           calendarevent.h

SOURCES += \
           main.cpp \
           calendarmodel.cpp \
           calendarevent.cpp

target.path = $$OUT_PWD/../bin
INSTALLS += target
