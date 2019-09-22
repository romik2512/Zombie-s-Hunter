#include "Zombie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "Game.h"


extern Game * game;

Zombie::Zombie(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{

        setPixmap(QPixmap(":/images/Zombie2.png"));
        zmove=qrand() %4;
        QTimer * timer =new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
 }

    void Zombie::move()
    {
        int ver=qrand() %100;
        if (ver > 90)  zmove=qrand() % 4;
        if (zmove==0){
        setPos(x(),y()-2);
        }else if (zmove==1){
        setPos(x()+2,y());
        }else if (zmove==2){
        setPos(x(),y()+2);
        }else if (zmove==3){
        setPos(x()-2,y());
        }
   }

