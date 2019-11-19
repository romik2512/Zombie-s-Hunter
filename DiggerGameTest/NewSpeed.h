#ifndef NEWSPEED_H
#define NEWSPEED_H

#include <QGraphicsPixmapItem>
#include <QObject>
class NewSpeed: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        NewSpeed(QGraphicsItem*parent=nullptr);
};

#endif // NEWSPEED_H
