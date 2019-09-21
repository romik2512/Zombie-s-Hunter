#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Zombie: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Zombie(QGraphicsItem*parent=nullptr);
        void create();
};

#endif // ZOMBIE_H
