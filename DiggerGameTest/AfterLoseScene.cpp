#include "AfterLoseScene.h"
#include "Menu.h"
#include <QBrush>
#include "Kolvo.h"
#include "Gametime.h"
#include "Game.h"
#include "Zapas.h"
#include <QDebug>
extern Menu* menu;
extern Game *game;
extern Zapas * zapas;
extern Kolvo * kolvo;
extern GTime * gametime;

AfterLoseScene::AfterLoseScene(char sceneglevel,QWidget*parent) {
losescene=new QGraphicsScene();
losescene->setSceneRect(0,0,900,700);
lvl=sceneglevel;
setBackgroundBrush(QBrush(QImage(":/images/lostgame.png")));
setScene(losescene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);
this->show();

Buttons*restartlosegame=new Buttons(RestartLoseGame);
restartlosegame->setPos(250,330);
losescene->addItem(restartlosegame);
lknopki<<restartlosegame;
connect(restartlosegame,SIGNAL(pressButton()),this,SLOT(RestartGame()));

Buttons*fromlosescenetomenu=new Buttons(FromLoseToMenu);
fromlosescenetomenu->setPos(250,400);
losescene->addItem(fromlosescenetomenu);
lknopki<<fromlosescenetomenu;
connect(fromlosescenetomenu,SIGNAL(pressButton()),this,SLOT(GoToMenu()));

Buttons*lfaq=new Buttons(FAQButton);
lfaq->setPos(370,470);
losescene->addItem(lfaq);
lknopki<<lfaq;
connect(lfaq,SIGNAL(pressButton()),this,SLOT(LFAQclicked()));

Buttons *lbackbutton=new Buttons(BackButton);
lbackbutton->setPos(580,550);
connect(lbackbutton,SIGNAL(pressButton()),this,SLOT(BackToLoseGameScene()));
lknopki<<lbackbutton;
}

void AfterLoseScene::LFAQclicked(){
    setBackgroundBrush(QBrush(QImage(":/images/faqforgamewithoutbutton.png")));
    losescene->removeItem(lknopki[0]);
    losescene->removeItem(lknopki[1]);
    losescene->removeItem(lknopki[2]);
    losescene->addItem(lknopki[3]);
}

void AfterLoseScene::RestartGame(){
            game=new Game(lvl);
            gametime=new GTime();
            gametime->setPos(770,85);
            game->scene->addItem(gametime);

            zapas=new Zapas();
            zapas->setPos(785,372);
            game->scene->addItem(zapas);

            kolvo=new Kolvo();
            if(game->enemies<10) {
                kolvo->setPos(785,222);
            }
            else {
           kolvo->setPos(777,222);
       }
       game->scene->addItem(kolvo);
       game->show();
       delete this;
}

void AfterLoseScene::GoToMenu(){
delete this;
menu=new Menu();
}

void AfterLoseScene::BackToLoseGameScene(){
   losescene->removeItem(lknopki[3]);
   setBackgroundBrush(QBrush(QImage(":/images/lostgame.png")));
   losescene->addItem(lknopki[0]);
   losescene->addItem(lknopki[1]);
   losescene->addItem(lknopki[2]);
}
