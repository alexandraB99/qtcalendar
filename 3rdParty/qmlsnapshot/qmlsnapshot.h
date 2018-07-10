#ifndef QMLSNAPSHOT_H
#define QMLSNAPSHOT_H

#include <QObject>
#include <QVariant>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPixmap>
#include <QImage>

class QMLSnapShot : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void captureWindow(QVariant data);
};

inline void QMLSnapShot::captureWindow(QVariant data) {
    QImage image = qvariant_cast<QImage>(data);
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer,0);
    if(dialog->exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        painter.drawImage(QPoint(0,0),image);
        painter.end();
    }
}
#endif // QMLSNAPSHOT_H
