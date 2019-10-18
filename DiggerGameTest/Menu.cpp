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

Settings* settings=new Settings();
settings->setPos(250,275);
mscene->addItem(settings);

Easy* easy=new Easy();
easy->setPos(265,350);
mscene->addItem(easy);

Medium* medium=new Medium(nullptr,true);
medium->setPos(398,350);
mscene->addItem(medium);
lvl='m';

Hard* hard=new Hard();
hard->setPos(532,350);
mscene->addItem(hard);
}

void Menu::mousePressEvent(QMouseEvent *event)
{

QList<QGraphicsItem*> clicked=mscene->items(event->pos().x(),event->pos().y(),1,1,Qt::IntersectsItemShape,Qt::AscendingOrder,QTransform());
for (int i=0,n=clicked.size();i<n;++i){
    if(typeid (*(clicked[i]))==typeid(NG)) {
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

} else if(typeid (*(clicked[i]))==typeid(Easy)){
if (lvl!='e'){
delete clicked[i];
    Easy* easy=new Easy(nullptr,true);
    easy->setPos(265,350);
    mscene->addItem(easy);
    lvl='e';
    mscene->removeItem(mscene->itemAt(399,351,QTransform()));
    mscene->removeItem(mscene->itemAt(533,351,QTransform()));

    Medium* medium=new Medium();
    medium->setPos(398,350);
    mscene->addItem(medium);

    Hard* hard=new Hard();
    hard->setPos(532,350);
    mscene->addItem(hard);

}
    }else if(typeid (*(clicked[i]))==typeid(Medium)){
        if (lvl!='m'){
        delete clicked[i];
            Medium* medium=new Medium(nullptr,true);
            medium->setPos(398,350);
            mscene->addItem(medium);
            lvl='m';
            mscene->removeItem(mscene->itemAt(266,351,QTransform()));
            mscene->removeItem(mscene->itemAt(533,351,QTransform()));

            Easy* easy=new Easy();
            easy->setPos(265,350);
            mscene->addItem(easy);

            Hard* hard=new Hard();
            hard->setPos(532,350);
            mscene->addItem(hard);

        }
    }else if(typeid (*(clicked[i]))==typeid(Hard)){
        if (lvl!='h'){
        delete clicked[i];
            Hard* hard=new Hard(nullptr,true);
            hard->setPos(532,350);
            mscene->addItem(hard);
            lvl='h';
            mscene->removeItem(mscene->itemAt(266,351,QTransform()));
            mscene->removeItem(mscene->itemAt(399,351,QTransform()));

            Easy* easy=new Easy();
            easy->setPos(265,350);
            mscene->addItem(easy);

            Medium* medium=new Medium();
            medium->setPos(398,350);
            mscene->addItem(medium);

        }
    }
}
}
