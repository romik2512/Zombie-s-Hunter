#include "Menu.h"
#include <QBrush>
#include <QDebug>

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

        Buttons* newgame=new Buttons(NewGame);
        newgame->setPos(250,200);
        mscene->addItem(newgame);
        knopki<<newgame;

        Buttons*settings=new Buttons(Settings);
        settings->setPos(250,275);
        mscene->addItem(settings);

        Buttons*easy=new Buttons(EasyLevel);
        easy->setPos(265,350);
        mscene->addItem(easy);
        knopki<<easy;

        Buttons*medium=new Buttons(ActiveMediumLevel);
        medium->setPos(398,350);
        mscene->addItem(medium);
        lvl='m';
        knopki<<medium;

        Buttons*hard=new Buttons(HardLevel);
        hard->setPos(532,350);
        mscene->addItem(hard);
        knopki<<hard;
    }
    else if(scenevalue=='w') {
        mscene=new QGraphicsScene();
        mscene->setSceneRect(0,0,900,700);
        lvl=sceneglevel;
        setBackgroundBrush(QBrush(QImage(":/images/wingame.png")));
        setScene(mscene);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(900,700);
        this->show();

        Buttons*restartwingame=new Buttons(RestartWinGame);
        restartwingame->setPos(250,330);
        mscene->addItem(restartwingame);

        Buttons*fromwinscenetomenu=new Buttons(FromWinToMenu);
        fromwinscenetomenu->setPos(250,400);
        mscene->addItem(fromwinscenetomenu);
    }
    else if(scenevalue=='l') {
        mscene=new QGraphicsScene();
        mscene->setSceneRect(0,0,900,700);
        lvl=sceneglevel;
        setBackgroundBrush(QBrush(QImage(":/images/lostgame.png")));
        setScene(mscene);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(900,700);
        this->show();

        Buttons*restartlosegame=new Buttons(RestartLoseGame);
        restartlosegame->setPos(250,330);
        mscene->addItem(restartlosegame);

        Buttons*fromlosescenetomenu=new Buttons(FromLoseToMenu);
        fromlosescenetomenu->setPos(250,400);
        mscene->addItem(fromlosescenetomenu);
    }
}

