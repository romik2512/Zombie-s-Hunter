#include "AfterWinScene.h"
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

AfterWinScene::AfterWinScene(char sceneglevel,QWidget*parent) {
winscene=new QGraphicsScene();
winscene->setSceneRect(0,0,900,700);
lvl=sceneglevel;
setBackgroundBrush(QBrush(QImage(":/images/wingame.png")));
setScene(winscene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);
this->show();

Buttons*restartwingame=new Buttons(RestartWinGame);
restartwingame->setPos(250,330);
winscene->addItem(restartwingame);
wknopki<<restartwingame;
connect(restartwingame,SIGNAL(pressButton()),this,SLOT(RestartGame()));

Buttons*fromwinscenetomenu=new Buttons(FromWinToMenu);
fromwinscenetomenu->setPos(250,400);
winscene->addItem(fromwinscenetomenu);
wknopki<<fromwinscenetomenu;
connect(fromwinscenetomenu,SIGNAL(pressButton()),this,SLOT(GoToMenu()));

Buttons*wfaq=new Buttons(FAQButton);
wfaq->setPos(370,470);
wknopki<<wfaq;
winscene->addItem(wfaq);
connect(wfaq,SIGNAL(pressButton()),this,SLOT(WFAQclicked()));

Buttons *wbackbutton=new Buttons(BackButton);
wbackbutton->setPos(580,550);
connect(wbackbutton,SIGNAL(pressButton()),this,SLOT(BackToWinGameScene()));
wknopki<<wbackbutton;
}

void AfterWinScene::WFAQclicked(){
    setBackgroundBrush(QBrush(QImage(":/images/faqforgamewithoutbutton.png")));
    winscene->removeItem(wknopki[0]);
    winscene->removeItem(wknopki[1]);
    winscene->removeItem(wknopki[2]);
    winscene->addItem(wknopki[3]);
}

void AfterWinScene::RestartGame(){
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

void AfterWinScene::GoToMenu(){
delete this;
menu=new Menu();
}

void AfterWinScene::BackToWinGameScene(){
   winscene->removeItem(wknopki[3]);
   setBackgroundBrush(QBrush(QImage(":/images/wingame.png")));
   winscene->addItem(wknopki[0]);
   winscene->addItem(wknopki[1]);
   winscene->addItem(wknopki[2]);
}

