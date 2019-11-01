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
#include "Bam.h"
#include "Crash.h"

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
        forme=0;
        timer->start(25);
 }

    void Zombie::move()
    {
       // qDebug() <<"ZOMBIE POYAVILSYA PRI "<< lavakol<<" LAVE!!!";
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
}else if (pos().y() > 51){
    path[1]=true;
    schetchik++;
} else {
    path[1]=false;
}

if(pos().x()<571){
    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))) {
      if(zosty>0){  if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-zosty,QTransform()))))))  {
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
            zmove=zadnapr;
            if (zadnapr<2){
                zadnapr=zadnapr+2;
            }else {zadnapr=zadnapr-2;}
        } else {
            path[zadnapr]=false;
            schetchik--;
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
    }
    }
        if (zmove==0) {
            bool nope=false;
            bool checker=false;
            zposx=x()-2;
            zposy=y();
            setPos(x()-2,y());
            QList<QGraphicsItem*> colliding_items=collidingItems();
            for(int i =0,n=colliding_items.size();i<n;++i){
                qDebug() <<"VIZVANO IZ 0, PROVERYAETSYA OBJECT: "<<typeid(*(colliding_items[i])).name()<<" EGO NOMER V SPISKE: "<<i;
                if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))){
                    continue;
                }

                else if(typeid (*(colliding_items[i]))==typeid(Player)) {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    return;
            } else

                if (typeid(*(colliding_items[i]))==typeid(Dynamit)){
                        game->boom++;
                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();

                    game->scene->removeItem(this);
                   delete this;
                    //kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::DescendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){
qDebug()<<"VZRYVAETSA: "<<typeid(*(vzryv[z])).name()<<"  EGO NOMER: #"<<z;

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))){
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                               delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                game->scene->removeItem(vzryv[z]);
                                delete vzryv[z];
                                return;
                            }
                    }
                    }
                    Bam*bam=new Bam();
                    bam->setPos(lposx-5,lposy-20);
                    game->scene->addItem(bam);
                    kolvo->decrease();
                    break;
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                    //if (fire==false){
                    if (checker==false){
                    if (lavakol!=(game->boom)){
                        //if (checker==false){
                        qDebug() <<"lavakol menshe vzryvov!!!";
                    int zzadnapr=zadnapr;
                    forme++;
                    qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!!" ;
                    game->scene->removeItem(this);
                    delete this;
                    Zombie * zombie=new Zombie(false,true);
                    zombie->setPos(zposx,zposy);
                    game->scene->addItem(zombie);
                    zombie->fire=true;
                    zombie->znapr=false;
                    zombie->zadnapr=zzadnapr;
                    zombie->lavakol=game->boom;
                    checker=true;
                    }
                   //     }
                    else if(znapr==true){
                        int zzadnapr=zadnapr;
                        forme++;
                        qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!!" ;
                        game->scene->removeItem(this);
                        delete this;
                        Zombie * zombie=new Zombie(false,true);
                        zombie->setPos(zposx,zposy);
                        game->scene->addItem(zombie);
                        zombie->znapr=false;
                        zombie->fire=true;
                        zombie->zadnapr=zzadnapr;
                        zombie->lavakol=game->boom;
                        checker=true;               //Ошибка в участке кода else когда понимает что нет столкновения с лавой! Фишка в том, что при взрыве динамита когда какойто зомбак на лаве происходит ошибка ХОТЯ БЕЗ ЛАВЫ ВСЕ РАБОТАЕТ!!!1
                    }
                    }
}
                else if((nope==false)&&(checker==false)){
                if (znapr==true){
                    qDebug() <<"VYZVANO IZ 0, ZNAPR: "<<znapr<<" ZPOSX: "<<zposx<<" ZPOSY: "<<zposy;
                    bool sr=fire;
                    int joke=lavakol;
                    int zzadnapr=zadnapr;
                    game->scene->removeItem(this);
                    delete this;
                    Zombie * zombie=new Zombie(false,sr); //Можно сразу lavalol присвпивать новому зомбаку, просто delte this перенести в конец )
                    zombie->setPos(zposx,zposy);
                    game->scene->addItem(zombie);
                    zombie->znapr=false;
                    zombie->fire=sr;
                    zombie->zadnapr=zzadnapr;
                    zombie->lavakol=joke;
                    nope=true;
                    checker=true;
                 }
                }
            }
        }

        else if(zmove==1){

            bool checker=false;
            zposx=x();
            zposy=y()-2;
             setPos(x(),y()-2);
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){
                 if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))){
                     continue;
                 }else

                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     game->scene->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){
                     game->boom++;
                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();

                    game->scene->removeItem(this);
                    delete this;
                   // kolvo->decrease();
                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::DescendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){
                        qDebug()<<"VZRYVAETSA: "<<typeid(*(vzryv[z])).name()<<"  EGO NOMER: #"<<z;

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))){
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {
                                game->scene->removeItem(vzryv[z]);
                                delete vzryv[z];
                                return;
                            }
                    }
                    }
                    Bam*bam=new Bam();
                    bam->setPos(lposx-5,lposy-20);
                    game->scene->addItem(bam);
                    kolvo->decrease();
                    break;                    
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                      //if(fire==false){
                     if (checker==false){
                     if (lavakol!=(game->boom)){
                         qDebug() <<"lavakol menshe vzryvov!!!";
                     bool nnapr=znapr;
                         int zzadnapr=zadnapr;
                     forme++;
                     qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!!" ;
                     game->scene->removeItem(this);
                     delete this;
                     Zombie * zombie=new Zombie(nnapr,true);
                     zombie->setPos(zposx,zposy);
                     game->scene->addItem(zombie);
                     zombie->fire=true;
                     zombie->znapr=nnapr;
                     zombie->zadnapr=zzadnapr;
                     zombie->lavakol=game->boom;
                     checker=true;
                      }
}
                 }
            }

        }else if(zmove==2){
            bool nope=false;
           // int pogchamp=0;
            bool checker=false;
            zposx=x()+2;
            zposy=y();
            //bool lol=false;
             setPos(x()+2,y());
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){
                 qDebug() <<"VIZVANO IZ 2, PROVERYAETSYA OBJECT: "<<typeid(*(colliding_items[i])).name()<<" EGO NOMER V SPISKE: "<<i;
if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))){
    continue;
}else
                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     game->scene->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){
                     game->boom++;
                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();

                    game->scene->removeItem(this);
                    delete this;
                    //kolvo->decrease();
                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::DescendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){
                        qDebug()<<"VZRYVAETSA: "<<typeid(*(vzryv[z])).name()<<"  EGO NOMER: #"<<z;

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))){
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();

                                }
                            }else {                                
                                game->scene->removeItem(vzryv[z]);
                                delete vzryv[z];
                                return;
                            }
                    }
                    }
                    Bam*bam=new Bam();
                    bam->setPos(lposx-5,lposy-20);
                    game->scene->addItem(bam);
                    kolvo->decrease();
                    break;
                }  else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                     if (checker==false){
                     if(lavakol!=(game->boom)){
                         qDebug() <<"lavakol menshe vzryvov!!! VIZVANO IS ZMOVE 2!!!";
                         int zzadnapr=zadnapr;
                         forme++;
                         qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!! vizvano iz zmove 2!!! POSX: "<<zposx<<" ZPOSY: "<<zposy;
                         qDebug() << "IMYA OBJECTA S KOTORYM VSTUPAET V KONTANKT: "<<(typeid(*(colliding_items[i])).name());
                         game->scene->removeItem(this);
                         delete this;
                                         Zombie * zombie=new Zombie(true,true);
                                         zombie->setPos(zposx,zposy);
                                         game->scene->addItem(zombie);
                                         zombie->fire=true;
                                         zombie->znapr=true;
                                         zombie->zadnapr=zzadnapr;
                                         zombie->lavakol=game->boom;
                                         checker=true;
                                         qDebug() <<"ZOMBIE SOZDALSYA USPESHNO!!!V POSX: "<<zposx<<" POSY: "<<zposy;
                     }   else if(znapr==false){
                         int zzadnapr=zadnapr;
                         forme++;
                         qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!!vizvano iz zmove 2!!! POSX: "<<zposx<<" ZPOSY: "<<zposy<<" PRICHEM POPALO V ZNAPRS==FALSE!!";
                         qDebug() << "IMYA OBJECTA S KOTORYM VSTUPAET V KONTANKT: "<<(typeid(*(colliding_items[i])).name());
                         game->scene->removeItem(this);
                         delete this;
                         Zombie * zombie=new Zombie(true,true);
                         zombie->setPos(zposx,zposy);
                         game->scene->addItem(zombie);
                         zombie->znapr=true;
                         zombie->fire=true;
                         zombie->zadnapr=zzadnapr;
                         zombie->lavakol=game->boom;
                         checker=true;
                     }
                     }
           } else if((nope==false)&&(checker==false)){
                 if (znapr==false){
                     //pogchamp++;
                     qDebug() <<"VYZVANO IZ 2, ZNAPR: "<<znapr<<" ZPOSX: "<<zposx<<" ZPOSY: "<<zposy<<" ZASHEL V ELSE RAZ: ";
int zzadnapr=zadnapr;
bool sr=fire;
int joke=lavakol;
QGraphicsItem* chekogo=this;
qDebug() <<"PRODOLZHENIYE 2 VHODA PERED DELETE";
qDebug() << "IMYA OBJECTA S KOTORYM VSTUPAET V KONTANKT: "<<(typeid(*(colliding_items[i])).name());
qDebug() << "IMYA OBJECTA S KOTORYM VSTUPAET V KONTANKT: "<<(typeid(*(colliding_items[i])).name())<<"  UKAZATEL THIS: "<<chekogo;
game->scene->removeItem(this);
delete this;
qDebug() <<"ZOMBIE UDALILSYA!!!";
Zombie * zombie=new Zombie(true,sr);
zombie->setPos(zposx,zposy);
game->scene->addItem(zombie);
qDebug() <<"ZOMBIE SOZDALSYA USPESHNO!!!";
zombie->znapr=true;
zombie->zadnapr=zzadnapr;
zombie->fire=sr;
zombie->lavakol=joke;
nope=true;
checker=true;
qDebug() << "NOVOGO ZOMBIE SODAL POSLE ZAHODA V ELSE!!!";
                 }
             }
             }
}

        else if(zmove==3){
            bool checker=false;
            zposx=x();
            zposy=y()+2;
             setPos(x(),y()+2);
             QList<QGraphicsItem*> colliding_items=collidingItems();
             for(int i =0,n=colliding_items.size();i<n;++i){
                 if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))){
                     continue;
                 }else

                 if(typeid (*(colliding_items[i]))==typeid(Player)) {
                     game->scene->removeItem(colliding_items[i]);
                     delete colliding_items[i];
                     return;
             } else

                 if (typeid(*(colliding_items[i]))==typeid(Dynamit)){
                     game->boom++;
                     int lposx=colliding_items[i]->pos().x();
                     int lposy=colliding_items[i]->pos().y();
                    game->scene->removeItem(this);
                    delete this;
                    //kolvo->decrease();

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::DescendingOrder, QTransform());

                    for(int z =0,v=vzryv.size();z<v;++z){
                        qDebug()<<"VZRYVAETSA: "<<typeid(*(vzryv[z])).name()<<"  EGO NOMER: #"<<z;

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))){
                            int lavx=vzryv[z]->pos().x();
                            int lavy=vzryv[z]->pos().y();
                              delete vzryv[z];
                              Lava * lava=new Lava();
                               lava->setPos(lavx,lavy);
                               game->scene->addItem(lava);
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            }else {                                
                                game->scene->removeItem(vzryv[z]);
                                delete vzryv[z];
                                return;
                            }
                    }
                    }
                    Bam*bam=new Bam();
                    bam->setPos(lposx-5,lposy-20);
                    game->scene->addItem(bam);
                    kolvo->decrease();
                    break;
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)){
                        // if(fire==false){
                     if (checker==false){
                     if(lavakol!=(game->boom)){
                         qDebug() <<"lavakol menshe vzryvov!!!";
                     bool nnapr=znapr;
                         int zzadnapr=zadnapr;
                         forme++;
                         qDebug()<<"Zombie sodalos na Lave: "<<forme<<" RAZ!!" ;
                         game->scene->removeItem(this);
                         delete this;
                     Zombie * zombie=new Zombie(nnapr,true);
                     zombie->setPos(zposx,zposy);
                     game->scene->addItem(zombie);
                     zombie->fire=true;
                     zombie->znapr=nnapr;
                     zombie->zadnapr=zzadnapr;
                     zombie->lavakol=game->boom;
                     checker=true;
                         }
                 }
                     }
            }
        }
}
