#include <QDebug>
#include <QBrush>
#include "WinGame.h"
#include "WPixmapButtons.h"
#include <QMouseEvent>
#include "Game.h"
#include "Zapas.h"
#include "Kolvo.h"
#include "Gametime.h"
#include "Menu.h"

extern Menu* menu;
extern Game *game;
extern Zapas * zapas;
extern Kolvo * kolvo;
extern GTime * gametime;

WinGame::WinGame(QWidget*parent){
winscene=new QGraphicsScene();
winscene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/wingame.png")));
setScene(winscene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);

Buttons* restart=new Buttons();
restart->setPos(250,330);
winscene->addItem(restart);

Buttons* tomenu=new Buttons('m');
tomenu->setPos(250,400);
winscene->addItem(tomenu);
}

void WinGame::mousePressEvent(QMouseEvent *eventer)
{
if((eventer->pos().x() > 249)&&(eventer->pos().x()<651)&&(eventer->pos().y()>329)&&(eventer->pos().y()<381)){

   game=new Game();
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
   game->show();

}
else if((eventer->pos().x() > 249)&&(eventer->pos().x()<651)&&(eventer->pos().y()>399)&&(eventer->pos().y()<451)){
   menu=new Menu();
    menu->show();
    delete this;
}

}
