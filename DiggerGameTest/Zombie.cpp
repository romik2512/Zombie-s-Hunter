#include "Zombie.h"
//#include "Game.h"
#include "GBlocks.h"
#include "Dynamit.h"
#include "LavaBlocks.h"
#include "Player.h"
#include "Kolvo.h"
#include "Bam.h"
#include "Crash.h"
#include "SecretBox.h"
#include "NewSpeed.h"
#include "NewDynamit.h"
#include "FireBoost.h"
#include <QDebug>
#include "Game.h"

extern Game * game;
extern Kolvo* kolvo;

Zombie::Zombie(bool napru,bool fairu,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
//Zombie::Zombie(Game*game,bool napru,bool fairu,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    if (napru==true) {
        if (fairu==false) {
            setPixmap(QPixmap(":/images/Zombie22.png"));
        } else {
            setPixmap(QPixmap(":/images/Zombie2fire2.png"));
        }
    } else if(fairu==false) {
        setPixmap(QPixmap(":/images/Zombie2.png"));
    } else {
        setPixmap(QPixmap(":/images/Zombie2fire.png"));
    }

//    QTimer * timer =new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
//    timer->start(25);
    zombiemove=new QTimer();
    connect(zombiemove,SIGNAL(timeout()),this,SLOT(move()));
    zombiemove->start(25);
}

void Zombie::move()
{
//    connect(game,SIGNAL(StopZombie()),this,SLOT(stoptimer()));
//    connect(game,SIGNAL(StartZombie()),this,SLOT(starttimer()));
    schetchik=0;
    int zposx=pos().x();
    int zostx=(zposx-50) % 40;
    int zposy=pos().y();
    int zosty=(zposy-50) % 40;


    if(pos().x()>89) {
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y(),QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y(),QTransform())))))))  {
            if (zosty>0) {
                if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-2,pos().y()+40-zosty,QTransform())))))))  {
                        path[0]=true;
                        schetchik++;
                }
                else {
                    path[0]=false;
                }
            } else {
                path[0]=true;
                schetchik++;
            }
        } else {
            path[0]=false;
        }
    } else if (pos().x()>51) {
        path[0]=true;
        schetchik++;
    }
    else {
        path[0]=false;
    }

    if(pos().y()>89) {
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-2,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-2,QTransform())))))))  {
            if (zostx>0) {
                if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()-2,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()-2,QTransform())))))))  {
                        path[1]=true;
                        schetchik++;
                }  else {
                    path[1]=false;
                }
            } else {
                path[1]=true;
                schetchik++;
            }
        } else {
            path[1]=false;
        }
    } else if (pos().y() > 51) {
        path[1]=true;
        schetchik++;
    } else {
        path[1]=false;
    }

    if(pos().x()<571) {
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))))  {
            if(zosty>0) {
                if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-zosty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-zosty,QTransform())))))))  {
                        path[2]=true;
                        schetchik++;
                }  else {
                    path[2]=false;
                }
            } else {
                path[2]=true;
                schetchik++;
            }
        } else {
            path[2]=false;
        }
    } else if (pos().x()<609) {
        path[2]=true;
        schetchik++;
    } else {
        path[2]=false;
    }

    if(pos().y()<571) {
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))))  {
            if (zostx>0) {
                if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()+40,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40-zostx,pos().y()+40,QTransform())))))))  {
                        path[3]=true;
                        schetchik++;
                }
                else {
                    path[3]=false;
                }
            } else {
                path[3]=true;
                schetchik++;
            }
        } else {
            path[3]=false;
        }
    } else if(pos().y()<609) {
        path[3]=true;
        schetchik++;
    } else {
        path[3]=false;
    }

    int k=0;
    int i=0;

    if (path[zadnapr]==true) {
        if (schetchik>1) {
            int joke=qrand() % 1000;
            if (joke <1) {
                zmove=zadnapr;
                if (zadnapr<2) {
                    zadnapr=zadnapr+2;
                } else {
                    zadnapr=zadnapr-2;
                }
            } else {
                path[zadnapr]=false;
                schetchik--;
                int randoooom=qrand()%(schetchik);
                while (i < randoooom+1) {
                    if (path[k]==true) {
                        i++;
                    }
                    k++;
                }
                zmove=k-1;
                if (zmove<2) {
                    zadnapr=zmove+2;
                } else {
                    zadnapr=zmove-2;
                }
            }
        } else {
            zmove=zadnapr;
            if (zadnapr<2) {
                zadnapr=zadnapr+2;
            } else {
                zadnapr=zadnapr-2;
            }
        }
    } else {
        if (schetchik==0) {
            zmove=5;
        } else {
            int randoooom=qrand()%(schetchik);

            while (i < randoooom+1) {
                if (path[k]==true) {
                    i++;
                }

                k++;
            }
            zmove=k-1;
            if (zmove<2) {
                zadnapr=zmove+2;
            } else {
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
        for(int i =0,n=colliding_items.size(); i<n; ++i) {
            if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))) {
                continue;
            }

            else if(typeid (*(colliding_items[i]))==typeid(Player)) {
                game->scene->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            } else

                if (typeid(*(colliding_items[i]))==typeid(Dynamit)) {
                    game->boom++;
                    int lposx=colliding_items[i]->pos().x();
                    int lposy=colliding_items[i]->pos().y();

                    game->scene->removeItem(this);
                    delete this;

                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size(); z<v; ++z) {
                        qDebug()<< typeid (*(vzryv[z])).name();
                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))) {
                                        if (!((typeid(*(vzryv[z]))==typeid(NewDynamit))||(typeid(*(vzryv[z]))==typeid(NewSpeed))||(typeid(*(vzryv[z]))==typeid(FireBoost)))){
                                            if(typeid(*(vzryv[z]))==typeid(SecretBox)){
                                                delete vzryv[z];
                                            }else {
                                            int lavx=vzryv[z]->pos().x();
                                            int lavy=vzryv[z]->pos().y();
                                            delete vzryv[z];
                                            Lava * lava=new Lava();
                                            lava->setPos(lavx,lavy);
                                            game->scene->addItem(lava);
                                            }
                                        }else{
                                         game->scene->removeItem(vzryv[z]);
                                         game->scene->addItem(vzryv[z]);
                                        }
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();
                                }
                            } else {
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
                } else if (typeid(*(colliding_items[i]))==typeid(Lava)) {
                    if (checker==false) {
                        if (lavakol!=(game->boom)) {
                            game->scene->removeItem(this);
                            game->scene->addItem(this);
                            setPixmap(QPixmap(":/images/Zombie2fire.png"));
                            fire=true;
                            lavakol=game->boom;
                            znapr=false;
                            checker=true;
                        }
                        else if(znapr==true) {
                            setPixmap(QPixmap(":/images/Zombie2fire.png"));
                            znapr=false;
                            checker=true;
                        }
                    }
                }
                else if((nope==false)&&(checker==false)) {
                    if (znapr==true) {
                        if (fire==true){
                        setPixmap(QPixmap(":/images/Zombie2fire.png"));
                        }else{
                        setPixmap(QPixmap(":/images/Zombie2.png"));
                        }
                        znapr=false;
                        nope=true;
                        checker=true;
                    }
                }
        }
    }

    else if(zmove==1) {

        bool checker=false;
        zposx=x();
        zposy=y()-2;
        setPos(x(),y()-2);
        QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i =0,n=colliding_items.size(); i<n; ++i) {
            if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))) {
                continue;
            } else

                if(typeid (*(colliding_items[i]))==typeid(Player)) {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    return;
                } else

                    if (typeid(*(colliding_items[i]))==typeid(Dynamit)) {
                        game->boom++;
                        int lposx=colliding_items[i]->pos().x();
                        int lposy=colliding_items[i]->pos().y();

                        game->scene->removeItem(this);
                        delete this;
                        QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                        for(int z =0,v=vzryv.size(); z<v; ++z) {
                            qDebug()<< typeid (*(vzryv[z])).name();

                            if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                    if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                        if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))) {
                                            if (!((typeid(*(vzryv[z]))==typeid(NewDynamit))||(typeid(*(vzryv[z]))==typeid(NewSpeed))||(typeid(*(vzryv[z]))==typeid(FireBoost)))){
                                                if(typeid(*(vzryv[z]))==typeid(SecretBox)){
                                                    delete vzryv[z];
                                                }else {
                                                int lavx=vzryv[z]->pos().x();
                                                int lavy=vzryv[z]->pos().y();
                                                delete vzryv[z];
                                                Lava * lava=new Lava();
                                                lava->setPos(lavx,lavy);
                                                game->scene->addItem(lava);
                                                }
                                            }else{
                                             game->scene->removeItem(vzryv[z]);
                                             game->scene->addItem(vzryv[z]);
                                            }
                                        }
                                    } else {
                                        game->scene->removeItem(vzryv[z]);
                                        delete vzryv[z];
                                        kolvo->decrease();
                                    }
                                } else {
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
                    } else if (typeid(*(colliding_items[i]))==typeid(Lava)) {
                        if (checker==false) {
                            if (lavakol!=(game->boom)) {
                                game->scene->removeItem(this);
                                if (znapr==false){
                                setPixmap(QPixmap(":/images/Zombie2fire.png"));
                                }else {
                                setPixmap(QPixmap(":/images/Zombie2fire2.png"));
                                }
                                fire=true;
                                lavakol=game->boom;
                                checker=true;
                                game->scene->addItem(this);
                            }
                        }
                    }
        }

    } else if(zmove==2) {
        bool nope=false;
        bool checker=false;
        zposx=x()+2;
        zposy=y();
        setPos(x()+2,y());
        QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i =0,n=colliding_items.size(); i<n; ++i) {
            if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))) {
                continue;
            } else if(typeid (*(colliding_items[i]))==typeid(Player)) {
                game->scene->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            } else

                if (typeid(*(colliding_items[i]))==typeid(Dynamit)) {
                    game->boom++;
                    int lposx=colliding_items[i]->pos().x();
                    int lposy=colliding_items[i]->pos().y();

                    game->scene->removeItem(this);
                    delete this;
                    QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                    for(int z =0,v=vzryv.size(); z<v; ++z) {
                        qDebug()<< typeid (*(vzryv[z])).name();

                        if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                            if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                    if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))) {
                                        if (!((typeid(*(vzryv[z]))==typeid(NewDynamit))||(typeid(*(vzryv[z]))==typeid(NewSpeed))||(typeid(*(vzryv[z]))==typeid(FireBoost)))){
                                            if(typeid(*(vzryv[z]))==typeid(SecretBox)){
                                                delete vzryv[z];
                                            }else {
                                            int lavx=vzryv[z]->pos().x();
                                            int lavy=vzryv[z]->pos().y();
                                            delete vzryv[z];
                                            Lava * lava=new Lava();
                                            lava->setPos(lavx,lavy);
                                            game->scene->addItem(lava);
                                            }
                                        }else{
                                         game->scene->removeItem(vzryv[z]);
                                         game->scene->addItem(vzryv[z]);
                                        }
                                    }
                                } else {
                                    game->scene->removeItem(vzryv[z]);
                                    delete vzryv[z];
                                    kolvo->decrease();

                                }
                            } else {
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
                }  else if (typeid(*(colliding_items[i]))==typeid(Lava)) {
                    if (checker==false) {
                        if(lavakol!=(game->boom)) {
                            game->scene->removeItem(this);
                            fire=true;
                            znapr=true;
                            lavakol=game->boom;
                            setPixmap(QPixmap(":/images/Zombie2fire2.png"));
                            game->scene->addItem(this);
                            checker=true;
                        }   else if(znapr==false) {
                            setPixmap(QPixmap(":/images/Zombie2fire2.png"));
                            znapr=true;
                            checker=true;
                        }
                    }
                } else if((nope==false)&&(checker==false)) {
                    if (znapr==false) {
                        if(fire==true){
                        setPixmap(QPixmap(":/images/Zombie2fire2.png"));
                        }else{
                        setPixmap(QPixmap(":/images/Zombie22.png"));
                        }
                        znapr=true;
                        nope=true;
                        checker=true;
                    }
                }
        }
    }

    else if(zmove==3) {
        bool checker=false;
        zposx=x();
        zposy=y()+2;
        setPos(x(),y()+2);
        QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i =0,n=colliding_items.size(); i<n; ++i) {
            if((typeid (*(colliding_items[i]))==typeid(Zombie))||(typeid (*(colliding_items[i]))==typeid(Bam))) {
                continue;
            } else

                if(typeid (*(colliding_items[i]))==typeid(Player)) {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    return;
                } else

                    if (typeid(*(colliding_items[i]))==typeid(Dynamit)) {
                        game->boom++;
                        int lposx=colliding_items[i]->pos().x();
                        int lposy=colliding_items[i]->pos().y();
                        game->scene->removeItem(this);
                        delete this;

                        QList<QGraphicsItem *> vzryv=game->scene->items(lposx-40,lposy-40,120,120,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());

                        for(int z =0,v=vzryv.size(); z<v; ++z) {
                            qDebug()<< typeid (*(vzryv[z])).name();

                            if(!(typeid(*(vzryv[z]))==typeid(GBlocks))) {
                                if(!(typeid(*(vzryv[z]))==typeid(Player))) {
                                    if(!(typeid(*(vzryv[z]))==typeid(Zombie))) {
                                        if(!((typeid(*(vzryv[z]))==typeid(Bam))||(typeid(*(vzryv[z]))==typeid(Crash)))) {
                                            if (!((typeid(*(vzryv[z]))==typeid(NewDynamit))||(typeid(*(vzryv[z]))==typeid(NewSpeed))||(typeid(*(vzryv[z]))==typeid(FireBoost)))){
                                                if(typeid(*(vzryv[z]))==typeid(SecretBox)){
                                                    delete vzryv[z];
                                                }else {
                                                int lavx=vzryv[z]->pos().x();
                                                int lavy=vzryv[z]->pos().y();
                                                delete vzryv[z];
                                                Lava * lava=new Lava();
                                                lava->setPos(lavx,lavy);
                                                game->scene->addItem(lava);
                                                }
                                            }else{
                                             game->scene->removeItem(vzryv[z]);
                                             game->scene->addItem(vzryv[z]);
                                            }
                                        }
                                    } else {
                                        game->scene->removeItem(vzryv[z]);
                                        delete vzryv[z];
                                        kolvo->decrease();
                                    }
                                } else {
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
                    } else if (typeid(*(colliding_items[i]))==typeid(Lava)) {
                        if (checker==false) {
                            if(lavakol!=(game->boom)) {
                                game->scene->removeItem(this);
                                if (znapr==false){
                                setPixmap(QPixmap(":/images/Zombie2fire.png"));
                                }else {
                                setPixmap(QPixmap(":/images/Zombie2fire2.png"));
                                }
                                fire=true;
                                lavakol=game->boom;
                                checker=true;
                                game->scene->addItem(this);
                            }
                        }
                    }
        }
    }
}

void Zombie::connectingtimer(){
    connect(game,SIGNAL(StopZombie()),this,SLOT(stoptimer()));
    connect(game,SIGNAL(StartZombie()),this,SLOT(starttimer()));
}

void Zombie::stoptimer(){
    zombiemove->stop();
}

void Zombie::starttimer(){
    zombiemove->start();
}
