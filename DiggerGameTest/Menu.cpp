#include "Menu.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "GBlocks.h"
#include "EarthBlocks.h"
#include "Zombie.h"
#include "Player.h"
#include <QDebug>
#include <QBrush>
#include "Gametime.h"
#include "Zapas.h"
#include "Kolvo.h"
#include "NG.h"
#include <QMouseEvent>
#include "Game.h"
#include "Settings.h"
#include "Easylvl.h"
#include "Hardlvl.h"
#include "Mediumlvl.h"

Game *game;

Zapas * zapas;
Kolvo * kolvo;

GTime * gametime;

//Medium*medium;
//Easy*easy;
//Hard *hard;

Menu::Menu(QWidget*parent){
mscene=new QGraphicsScene();
mscene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/testmenu2.png")));
setScene(mscene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);

NG* ng=new NG();
ng->setPos(250,200);
mscene->addItem(ng);
knopki<<ng;

Settings* settings=new Settings();
settings->setPos(250,275);
mscene->addItem(settings);

Easy* easy=new Easy();
//easy=new Easy();
easy->setPos(265,350);
mscene->addItem(easy);
knopki<<easy;

Medium* medium=new Medium(nullptr,true);
medium->setPos(398,350);
mscene->addItem(medium);
lvl='m';
knopki<<medium;

Hard* hard=new Hard();
hard->setPos(532,350);
mscene->addItem(hard);
knopki<<hard;
}

void Menu::mousePressEvent(QMouseEvent *event)
{

//QList<QGraphicsItem*> clicked=mscene->items(event->pos().x(),event->pos().y(),1,1,Qt::IntersectsItemShape,Qt::AscendingOrder,QTransform());
//for (int i=0,n=clicked.size();i<n;++i){
    //if(typeid (*(clicked[i]))==typeid(NG)) {
    if((event->pos().x() > 249)&&(event->pos().x()<651)&&(event->pos().y()>199)&&(event->pos().y()<251)){
        //delete knopki[0];
    game=new Game(lvl);
   game->show();
  delete this;

   gametime=new GTime();
   gametime->setPos(770,85);
   game->scene->addItem(gametime);

   zapas=new Zapas();
   zapas->setPos(785,372);
   game->scene->addItem(zapas);

   kolvo=new Kolvo();
   if(game->enemies<10){
   kolvo->setPos(785,222);}
   else{kolvo->setPos(777,222);}
   game->scene->addItem(kolvo);
   /*game->show();
   delete this;*/

}
    //else if(typeid (*(clicked[i]))==typeid(Easy)){
    else if((event->pos().x() > 264)&&(event->pos().x()<367)&&(event->pos().y()>349)&&(event->pos().y()<451)){
if (lvl!='e'){
//delete clicked[i];
    qDebug()<<typeid(*(knopki[1])).name();
    delete knopki[1];

    Easy* easy=new Easy(nullptr,true);
    easy->setPos(265,350);
    mscene->addItem(easy);
    knopki[1]=easy;

    //qDebug()<<typeid(*(knopki[1])).name();
    //delete knopki[1];
    //qDebug()<<typeid(*(knopki[1])).name();

    lvl='e';
    delete knopki[2];
    delete knopki[3];

   // mscene->removeItem(mscene->itemAt(399,351,QTransform()));
    //mscene->removeItem(mscene->itemAt(533,351,QTransform()));

    Medium* medium=new Medium();
    medium->setPos(398,350);
    mscene->addItem(medium);
    knopki[2]=medium;

    Hard* hard=new Hard();
    hard->setPos(532,350);
    mscene->addItem(hard);
    knopki[3]=hard;

}
    } //else if(typeid (*(clicked[i]))==typeid(Medium)){
    else if((event->pos().x() > 397)&&(event->pos().x()<500)&&(event->pos().y()>349)&&(event->pos().y()<451)){
        if (lvl!='m'){
        //delete clicked[i];
            delete knopki[2];
            Medium* medium=new Medium(nullptr,true);
            medium->setPos(398,350);
            mscene->addItem(medium);
            knopki[2]=medium;
            lvl='m';
           // mscene->removeItem(mscene->itemAt(266,351,QTransform()));
           //mscene->removeItem(mscene->itemAt(533,351,QTransform()));
            delete knopki[1];
            delete knopki[3];

            Easy* easy=new Easy();
            easy->setPos(265,350);
            mscene->addItem(easy);
            knopki[1]=easy;

            Hard* hard=new Hard();
            hard->setPos(532,350);
            mscene->addItem(hard);
            knopki[3]=hard;

        }
    } //else if(typeid (*(clicked[i]))==typeid(Hard)){
    else if((event->pos().x() > 531)&&(event->pos().x()<634)&&(event->pos().y()>349)&&(event->pos().y()<451)){
        if (lvl!='h'){
        //delete clicked[i];
            delete knopki[3];
            Hard* hard=new Hard(nullptr,true);
            hard->setPos(532,350);
            mscene->addItem(hard);
            knopki[3]=hard;
            lvl='h';
            //mscene->removeItem(mscene->itemAt(266,351,QTransform()));
           // mscene->removeItem(mscene->itemAt(399,351,QTransform()));
            delete knopki[1];
            delete knopki[2];

            Easy* easy=new Easy();
            easy->setPos(265,350);
            mscene->addItem(easy);
            knopki[1]=easy;

            Medium* medium=new Medium();
            medium->setPos(398,350);
            mscene->addItem(medium);
            knopki[2]=medium;
        }
    }
//}
}
