#ifndef DYNAMIT_H
#define DYNAMIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Zombie.h"
class Dynamit: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Dynamit(QGraphicsItem*parent=nullptr);

};

#endif // DYNAMIT_H
