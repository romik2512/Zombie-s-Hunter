#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Zombie: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Zombie(bool napru,bool fireu,QGraphicsItem*parent=nullptr);
        bool path[4]={false,false,false,false};
        int zmove=5;
        int schetchik=0;
        int zadnapr=5;
        bool znapr;
        bool fire;
        int forme=0;
        int lavakol=0;
        int nomerzombie;
 public slots:
        //void move(QTimer *timer);
        void move();
};

#endif // ZOMBIE_H
