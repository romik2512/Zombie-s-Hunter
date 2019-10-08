#include "Gametime.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game *game;

GTime::GTime(QGraphicsItem *parent): QGraphicsTextItem(parent){

    gtime=0;
    setPlainText(QString::number(gtime));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",30));

    QTimer * gtimer =new QTimer();
    connect(gtimer,SIGNAL(timeout()),this,SLOT(increase()));
    connect(gtimer,SIGNAL(timeout()),this,SLOT(addblocks()));
    gtimer->start(1000);
    kolvo=15;
    ugol=qrand() %4;
    if (qrand() % 2 ==0){
        blocksnapr=false;
    }else {
        blocksnapr=true;
    }
    if (ugol==0){
        gbx=50;
        gby=50;
    }else if (ugol==1){
        gbx=610;
        gby=50;
    }else if (ugol==2){
        gbx=50;
        gby=610;
    }else {
        gbx=610;
        gby=610;
    }
}

void GTime::increase()
{
    gtime++;   
    setPlainText(QString::number(gtime));
}

void GTime::addblocks(){                                  // Можно добавить переменную, которая будет считать сколько уже построил, нализировать и поворачивать когда уже все ) это допустим schectchik , while (schetchik<=i*4 -4 ); где i это сколько нужно ставить блоков в линии и будем идти по квадрату как раз
    if (kolvo>-1){
    if (gtime>9){




    }
}else {} // Тут конец игры сделать )
}
