#include "Zombie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include "GBlocks.h"


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
    {   bool path[4];
        int chisto=0;
      /*  if(pos().x()>89) {if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-40,pos().y(),QTransform())))))) {path[0]=true; chisto++;} else path[0]=false;} else {path[0]=true; chisto++;}
        if(pos().y()>89) {if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-40,QTransform())))))) {path[1]=true; chisto++;} else path[1]=false;} else {path[1]=true; chisto++;}
        if(pos().x()<611){if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))) {path[2]=true; chisto++;} else path[2]=false;} else {path[2]=true; chisto++;}
        if(pos().y()<611){if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))) {path[3]=true; chisto++;} else path[3]=false;} else {path[3]=true; chisto++;}
*/
       // qDebug() << "CHISTO: "<<chisto;

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

