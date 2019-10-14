#ifndef HARDLVL_H
#define HARDLVL_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Hard: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Hard(QGraphicsItem*parent=nullptr,bool active=false);
};


#endif // HARDLVL_H
