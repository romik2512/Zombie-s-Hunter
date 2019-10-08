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

Zombie::Zombie(bool napru,bool fairu,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    if (napru==true){
        if (fairu==false){
        setPixmap(QPixmap(":/images/Zombie22.png"));
        } else {
            setPixmap(QPixmap(":/images/Zombie2fire2.png"));
        }
    }else if(fairu==false){
            setPixmap(QPixmap(":/images/Zombie2.png"));
        } else {
           setPixmap(QPixmap(":/images/Zombie2fire.png"));
        }

        QTimer * timer =new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(25);
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
               if (!((typeid(Lava))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform()))))))  {                   //здесь траббл
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
}else if (pos().y() > 51){
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

    if (path[zadnapr]==true){
        if (schetchik>1){
        int joke=qrand() % 1000;
        if (joke <1) {
  qDebug() << "ON RESHIL RAZEVRUTSYA LOOOOOL ";
            zmove=zadnapr;
            if (zadnapr<2){
                zadnapr=zadnapr+2;
            }else {zadnapr=zadnapr-2;}
        } else {           
            path[zadnapr]=false;
            schetchik--;                          
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
              qDebug() <<"PATH[ZADNAPR]: TRUE!! ZOMBIE POSX: " <<pos().x()<<" ZOMBIE POSY"<<pos().y();
              qDebug() <<"PATH[ZADNAPR]: TRUE!! Zombie idet v napravlenii: "<<zmove;
              qDebug() << "PATH[ZADNAPR]: TRUE!! Ego zadnee napravleniye: "<<zadnapr;                                   //ТРАБББЛ В ТОМ, ЧТО ЕСЛИ ЗОМБИ ИДЕТ ВНИЗ И ПОВОРАЧИВАЕТ НА ЛЕВО, ТО ЕГО ЗАДНЕЕ НАПРАВЛЕНИЕ АВТОМАТОМ СТАНОВИТСЯ ПРАВО,ХОТЯ ДОЛЖЕН БЫТЬ ВВЕРХ?
            }
        } else {
            zmove=zadnapr;
            if (zadnapr<2){
                zadnapr=zadnapr+2;
            }else {zadnapr=zadnapr-2;}
        }
   } else{
    if (schetchik==0){
        zmove=5;
    } else {
     int randoooom=qrand()%(schetchik);

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

qDebug() <<"PATH[ZADNAPR]: ELSE!! ZOMBIE POSX: " <<pos().x()<<" ZOMBIE POSY"<<pos().y();
qDebug() <<"PATH[ZADNAPR]: ELSE!! Zombie idet v napravlenii: "<<zmove;
qDebug() << "PATH[ZADNAPR]: ELSE!! Ego zadnee napravleniye: "<<zadnapr;
    }
    }
        if (zmove==0) {
            zposx=x()-2;
            zposy=y(); // МЕЙБИ ЗДЕСЬ ТРАББЛЫ!!
            setPos(x()-2,y());
            bool lol=false;
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
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
if (fire==false){
    int zzadnapr=zadnapr;
                    delete this;
                    Zombie * zombie=new Zombie(false,true);
                    zombie->setPos(zposx,zposy);
                    game->scene->addItem(zombie);
                    zombie->fire=true;
                    zombie->znapr=false;
                    zombie->zadnapr=zzadnapr;
}

                } else {
                    lol=true;
                   /* if (napr==true){
                       bool sr=fire;
                       delete this;
                       Zombie * zombie=new Zombie(false,sr);
                       zombie->setPos(zposx,zposy);
                       game->scene->addItem(zombie);
                       zombie->napr=false;
                       zombie->fire=sr;
                       break;
                    }*/
                }
            } if (lol==true){
                if (znapr==true){                                                    //ПРОБЛЕМА В ТОМ ЧТО Я ЗАДНЕЕ НАПРАВЛЕНИЕ НЕ СОХРАНЯЮ У ЗОМБАКА!!!!!!!!!!!!!!!!!!!!!!! гениально )))
                    bool sr=fire;
                    int zzadnapr=zadnapr;
                    delete this;
                    Zombie * zombie=new Zombie(false,sr);
                    zombie->setPos(zposx,zposy);
                    game->scene->addItem(zombie);
                    zombie->znapr=false;
                    zombie->fire=sr;
                    zombie->zadnapr=zzadnapr;
                 }
            }
        }
        else if(zmove==1){
            zposx=x();
            zposy=y()-2;
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
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                     if (fire==false){
                         bool nnapr=znapr;
                         int zzadnapr=zadnapr;
                     delete this;
                     Zombie * zombie=new Zombie(nnapr,true);
                     zombie->setPos(zposx,zposy);
                     game->scene->addItem(zombie);
                     zombie->fire=true;
                     zombie->znapr=nnapr;
                     zombie->zadnapr=zzadnapr;
                     }
                 }
            }

        }else if(zmove==2){
            zposx=x()+2;
            zposy=y();
            bool lol=false;
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
                }  else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                     if (fire==false){
                         int zzadnapr=zadnapr;
                                         delete this;
                                         Zombie * zombie=new Zombie(true,true);
                                         zombie->setPos(zposx,zposy);
                                         game->scene->addItem(zombie);
                                         zombie->fire=true;
                                         zombie->znapr=true;
                                         zombie->zadnapr=zzadnapr;
                     }

                                     } else {
                     lol=true;                                     
                                     }
            }
             if (lol==true){
                 if (znapr==false){
                     int zzadnapr=zadnapr;
                                                             bool sr=fire;
                                                             delete this;
                                                             Zombie * zombie=new Zombie(true,sr);
                                                             zombie->setPos(zposx,zposy);
                                                             game->scene->addItem(zombie);
                                                             zombie->znapr=true;
                                                             zombie->zadnapr=zzadnapr;
                                                             zombie->fire=sr;}
             }

        }else if(zmove==3){
            zposx=x();
            zposy=y()+2;
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
                    //checker=true;                                                                   /////ВЕРТЯТСЯ ОНИ ПОТОМУ ЧТО В МАССИВЕ ПРИ ДВУХ ЗЕМЛЯНЫХ БЛОКАХ БУДЕТ ДВА РАЗА ГЕРОЯ УБИВАТЬ И СОЗДАВАТЬ"!!!!!!!!!! ИЛИ ЖЕ ТРАББЛ В ТОМ, ЧТО МЫ С САМОГО НАЧАЛА ДЕЛАЕМ ИМ ПОЗИЦИЮ!!

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
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                     if (fire==false){
                         bool nnapr=znapr;
                         int zzadnapr=zadnapr;
                     delete this;
                     Zombie * zombie=new Zombie(nnapr,true);
                     zombie->setPos(zposx,zposy);
                     game->scene->addItem(zombie);
                     zombie->fire=true;
                     zombie->znapr=nnapr;
                     zombie->zadnapr=zzadnapr;
                     }
                 }
            }

        }
}
