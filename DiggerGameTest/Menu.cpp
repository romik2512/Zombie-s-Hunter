#include "Menu.h"
#include <QBrush>
#include <QDebug>
#include "Kolvo.h"
#include "Gametime.h"
#include "Game.h"
#include "Zapas.h"
Game*game;
Zapas * zapas;
Kolvo * kolvo;
GTime * gametime;

Menu::Menu(char scenevalue,char sceneglevel,QWidget*parent) {
    if (scenevalue=='m') {
        mscene=new QGraphicsScene();
        mscene->setSceneRect(0,0,900,700);

        setBackgroundBrush(QBrush(QImage(":/images/testmenu2.png")));
        setScene(mscene);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(900,700);
        this->show();

        Buttons* newgame=new Buttons();
        newgame->setPos(250,200);
        mscene->addItem(newgame);
        knopki<<newgame;
        connect(newgame,SIGNAL(pressButton()),this,SLOT(MainNewGame()));

        Buttons*easy=new Buttons(EasyLevel);
        easy->setPos(265,350);
        mscene->addItem(easy);
        knopki<<easy;
        connect(easy,SIGNAL(pressButton()),this,SLOT(SetEasyLevel()));

        Buttons*medium=new Buttons(ActiveMediumLevel);
        medium->setPos(398,350);
        mscene->addItem(medium);
        lvl='m';
        knopki<<medium;
        connect(medium,SIGNAL(pressButton()),this,SLOT(SetMediumLevel()));

        Buttons*hard=new Buttons(HardLevel);
        hard->setPos(532,350);
        mscene->addItem(hard);
        knopki<<hard;
        connect(hard,SIGNAL(pressButton()),this,SLOT(SetHardLevel()));

        Buttons*settings=new Buttons(Settings);
        settings->setPos(250,275);
        mscene->addItem(settings);
        knopki<<settings;

        Buttons*faq=new Buttons(FAQButton);
        faq->setPos(375,425);
        mscene->addItem(faq);
        connect(faq,SIGNAL(pressButton()),this,SLOT(FAQclicked()));
        knopki<<faq;

        Buttons *backbutton=new Buttons(BackButton);
        backbutton->setPos(580,550);
        connect(backbutton,SIGNAL(pressButton()),this,SLOT(BackToMenu()));
        knopki<<backbutton;
    }
}

void Menu::FAQclicked(){
   setBackgroundBrush(QBrush(QImage(":/images/faqforgamewithoutbutton.png")));
   mscene->removeItem(knopki[0]);
   mscene->removeItem(knopki[1]);
   mscene->removeItem(knopki[2]);
   mscene->removeItem(knopki[3]);
   mscene->removeItem(knopki[4]);
   mscene->removeItem(knopki[5]);
   mscene->addItem(knopki[6]);
}

void Menu::BackToMenu(){
    mscene->removeItem(knopki[6]);
    setBackgroundBrush(QBrush(QImage(":/images/testmenu2.png")));
    mscene->addItem(knopki[0]);
    mscene->addItem(knopki[1]);
    mscene->addItem(knopki[2]);
    mscene->addItem(knopki[3]);
    mscene->addItem(knopki[4]);
    mscene->addItem(knopki[5]);
}

void Menu::MainNewGame(){
            game=new Game(lvl);
            for (int i=0,n=game->zombs.size();i<n;i++){
                game->zombs[i]->connectingtimer();
            }
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

void Menu::SetEasyLevel(){
    if ((lvl)!='e') {
                knopki[1]->setPixmap(QPixmap(":/images/activeeasyselect.png"));
                lvl='e';
                knopki[2]->setPixmap(QPixmap(":/images/mediumselect.png"));
                knopki[3]->setPixmap(QPixmap(":/images/hardselect.png"));
            }
}

void Menu::SetMediumLevel(){
    if (lvl!='m') {
                 lvl='m';
                 knopki[1]->setPixmap(QPixmap(":/images/easyselect.png"));
                 knopki[2]->setPixmap(QPixmap(":/images/activemediumselect.png"));
                 knopki[3]->setPixmap(QPixmap(":/images/hardselect.png"));
           }
}

void Menu::SetHardLevel(){
    if (lvl!='h') {
                 lvl='h';
                 knopki[1]->setPixmap(QPixmap(":/images/easyselect.png"));
                 knopki[2]->setPixmap(QPixmap(":/images/mediumselect.png"));
                 knopki[3]->setPixmap(QPixmap(":/images/activehardselect.png"));
           }
}
