#include "Menu.h"
#include <QBrush>
#include "Buttons.h"

Menu::Menu(char scenevalue,char sceneglevel,QWidget*parent){
    if (scenevalue=='m'){
mscene=new QGraphicsScene();
mscene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/testmenu2.png")));
setScene(mscene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);
this->show();

Buttons* ng=new Buttons('n');
ng->setPos(250,200);
mscene->addItem(ng);
knopki<<ng;

Buttons* settings=new Buttons('s');
settings->setPos(250,275);
mscene->addItem(settings);

Buttons* easy=new Buttons('e');
easy->setPos(265,350);
mscene->addItem(easy);
knopki<<easy;

Buttons* medium=new Buttons('2');
medium->setPos(398,350);
mscene->addItem(medium);
lvl='m';
knopki<<medium;

Buttons* hard=new Buttons('h');
hard->setPos(532,350);
mscene->addItem(hard);
knopki<<hard;
}
    else if(scenevalue=='w'){
        mscene=new QGraphicsScene();
        mscene->setSceneRect(0,0,900,700);
        lvl=sceneglevel;
        setBackgroundBrush(QBrush(QImage(":/images/wingame.png")));
        setScene(mscene);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(900,700);
        this->show();

        Buttons* restart=new Buttons('w');
        restart->setPos(250,330);
        mscene->addItem(restart);

        Buttons* tomenu=new Buttons('t');
        tomenu->setPos(250,400);
        mscene->addItem(tomenu);
    }
    else if(scenevalue=='l'){
        mscene=new QGraphicsScene();
        mscene->setSceneRect(0,0,900,700);
        lvl=sceneglevel;
        setBackgroundBrush(QBrush(QImage(":/images/lostgame.png")));
        setScene(mscene);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(900,700);
        this->show();

        Buttons* restart=new Buttons('l');
        restart->setPos(250,330);
        mscene->addItem(restart);

        Buttons* tomenu=new Buttons('o');
        tomenu->setPos(250,400);
        mscene->addItem(tomenu);
    }
}

