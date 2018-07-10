#ifndef STANDARDPATHS_H
#define STANDARDPATHS_H

#include <QObject>
#include <QStandardPaths>

class StandardPaths : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QStringList getDesktopDir() {
        return QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    }
    Q_INVOKABLE QStringList getHomeDir() {
        return QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    }
};

#endif // STANDARDPATHS_H
