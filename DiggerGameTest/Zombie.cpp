#include "Zombie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include "GBlocks.h"
#include "Dynamit.h"
#include "LavaBlocks.h"
#include "Player.h"
#include "Kolvo.h"

extern Game * game;
extern Kolvo* kolvo;

Zombie::Zombie(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
        setPixmap(QPixmap(":/images/Zombie2.png"));
        //zmove=qrand() %4;
        QTimer * timer =new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
 }

    void Zombie::move()
    {
schetchik=0;
int zposx=pos().x();
int zostx=(zposx-50) % 40;
int zposy=pos().y();
int zosty=(zposy-50) % 40;


if(pos().x()>89) {
    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y(),QTransform()))))))  {
       // if (zosty>0){if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
        if (zosty>0){if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
                if (!((typeid(Lava))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
            path[0]=true;
        schetchik++;
    }
                }
        else {
        path[0]=false;
        }
        }else {
            path[0]=true;
            schetchik++;
        }
    } else {path[0]=false;}
} else if (pos().x()>51) {
        path[0]=true;
        schetchik++;
    }
else {
    path[0]=false;
}

if(pos().y()>89) {
    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-2,QTransform())))))) {
       if (zostx>0){ if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()-2,QTransform()))))))  {
               if (!((typeid(Lava))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
        path[1]=true;
       schetchik++;
    }
         }  else {
           path[1]=false;
           }
       }else {
           path[1]=true;
           schetchik++;
       }
    } else {path[1]=false;}
}else if (pos().y() > 52){
    path[1]=true;
    schetchik++;
} else {
    path[1]=false;
}

if(pos().x()<571){
    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))) {
      if(zosty>0){  if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-zosty,QTransform()))))))  { // ТРАБЛЫ В ТОМ, ЧТО КОГДА ОСТАТОК 0, ПРОВЕРКА ЛАВЫ НЕ ПРОИСХОДИТ!!! исправь как вернешься домой!!!
              if (!((typeid(Lava))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
        path[2]=true;
        schetchik++;
    }
        }  else {
          path[2]=false;
          }
      }else {
          path[2]=true;
          schetchik++;
      }
    }else {path[2]=false;}
} else if (pos().x()<609){
    path[2]=true;
    schetchik++;
} else {
    path[2]=false;
}

if(pos().y()<571){
    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))) {
     if (zostx>0){  if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()+40,QTransform()))))))  {
             if (!((typeid(Lava))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {
       path[3]=true;
        schetchik++;
    }
         }
         else {
         path[3]=false;
         }
     }else {
         path[3]=true;
         schetchik++;
     }
    }else {path[3]=false;}
} else if(pos().y()<609){
    path[3]=true;
    schetchik++;
} else {
    path[3]=false;
}

     int k=0;
      int i=0;
     for(int z=0;z<4;z++) {if (path[z]==true) {
            // qDebug() <<"Napravleniye razresheno: "<<z;
         }
     }
   // qDebug() <<"SHETCHIK: " << schetchik;

    if (path[zadnapr]==true){
        int joke=qrand() % 1000;
        if (joke <1) {
            zmove=zadnapr;
            if (zadnapr<2){
                zadnapr=zadnapr+2;
            }else {zadnapr=zadnapr-2;}
        } else {
            if (schetchik>1){
            path[zadnapr]=false;
            schetchik--;
            }
                if (schetchik==0){
                    //qDebug() << "POSX: "<<pos().x() <<" POSY: "<<pos().y();
                } else {
             int randoooom=qrand()%(schetchik);
           //  qDebug() << "Random vybral: "<<randoooom+1;

                while (i < randoooom+1){
                       if (path[k]==true){ i++;}
                       k++;
                  }
              zmove=k-1;
              if (zmove<2) {
                  zadnapr=zmove+2;
              }else {
                  zadnapr=zmove-2;
              }
             // qDebug() <<"Zombie idet v napravlenii: "<<zmove;
      //  qDebug() <<"ZOMBIE POSX: " <<pos().x()<<" ZOMBIE POSY"<<pos().y();
            }
        }
   } else{
    if (schetchik==0){
        //qDebug() << "POSX: "<<pos().x() <<" POSY: "<<pos().y();
    } else {
     int randoooom=qrand()%(schetchik);
     //qDebug() << "Random vybral: "<<randoooom+1;

        while (i < randoooom+1){
               if (path[k]==true){ i++;}

               k++;
          }
      zmove=k-1;
      if (zmove<2) {
          zadnapr=zmove+2;
      }else {
          zadnapr=zmove-2;
      }
    //  qDebug() <<"Zombie idet v napravlenii: "<<zmove;
//qDebug() <<"ZOMBIE POSX: " <<pos().x()<<" ZOMBIE POSY"<<pos().y();
    }
    }
        if (zmove==0) {
            setPos(x()-2,y());
            bool checker=false;
            QList<QGraphicsItem*> colliding_items=collidingItems();
            for(int i =0,n=colliding_items.size();i<n;++i){

                if(typeid (*(colliding_items[i]))==typeid(Player)) {
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    return;
            } else

                if (typeid(*(colliding_items[i]))==typeid(Dynamit)){

                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();
                    //checker=true;

                    scene()->removeItem(this);
                    delete this;
                    kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                            qDebug() << "THIS ISSSSSSSSSSSSSSSSSSSSSSS:   " <<typeid(*(vzryv[z])).name();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                } else {
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                delete vzryv[z];
                            }
                    }
                    }

                    break;
                }
            }

        }
        else if(zmove==1){
             setPos(x(),y()-2);
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){

                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     scene()->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){

                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();
                    //checker=true;

                    scene()->removeItem(this);
                    delete this;
                    kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                            qDebug() << "THIS ISSSSSSSSSSSSSSSSSSSSSSS:   " <<typeid(*(vzryv[z])).name();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                } else {
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                delete vzryv[z];
                            }
                    }
                    }

                    break;
                }
            }

        }else if(zmove==2){
             setPos(x()+2,y());
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){

                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     scene()->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){

                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();
                    //checker=true;

                    scene()->removeItem(this);
                    delete this;
                    kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                            qDebug() << "THIS ISSSSSSSSSSSSSSSSSSSSSSS:   " <<typeid(*(vzryv[z])).name();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                } else {
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                delete vzryv[z];
                            }
                    }
                    }

                    break;
                }
            }

        }else if(zmove==3){
             setPos(x(),y()+2);
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){

                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     scene()->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){

                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();
                    //checker=true;

                    scene()->removeItem(this);
                    delete this;
                    kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                            qDebug() << "THIS ISSSSSSSSSSSSSSSSSSSSSSS:   " <<typeid(*(vzryv[z])).name();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                } else {
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                delete vzryv[z];
                            }
                    }
                    }

                    break;
                }
            }

        }
}
