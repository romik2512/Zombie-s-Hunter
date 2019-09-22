#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Zombie: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Zombie(QGraphicsItem*parent=nullptr);
 public slots:
        void move();
private:
        int zmove;
};

#endif // ZOMBIE_H
