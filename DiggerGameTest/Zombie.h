#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Zombie: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Zombie(QGraphicsItem*parent=nullptr);
        bool path[4]={false,false,false,false};
        int zmove=5;
        int schetchik=0;
        int zadnapr=5;
 public slots:
        void move();    
};

#endif // ZOMBIE_H
