#ifndef DYNAMIT_H
#define DYNAMIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Dynamit: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Dynamit(QGraphicsItem*parent=nullptr);

};

#endif // DYNAMIT_H
