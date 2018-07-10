TEMPLATE = lib
TARGET = qmlsnapshot

QT += quick printsupport

HEADERS += \
    qmlsnapshot.h \
    standardpaths.h

DEFINES += QMLSNAPSHOT

macos:QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/
