#include "Gametime.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game *game;

GTime::GTime(QGraphicsItem *parent): QGraphicsTextItem(parent){

    gtime=0;

    //setPlainText(QString("Time: ")+QString::number(gtime));
    setPlainText(QString::number(gtime));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",30));

    QTimer * gtimer =new QTimer();
    connect(gtimer,SIGNAL(timeout()),this,SLOT(increase()));

    gtimer->start(1000);

}

void GTime::increase()
{
    qDebug() <<"POGCHAMP!!!!!!!!!!!!!!!!!!!!";
    gtime++;
    //setPlainText(QString("Time: ")+QString::number(gtime));
    setPlainText(QString::number(gtime));
   // setDefaultTextColor(Qt::yellow);
    //setFont(QFont("times",30));
}
/*int GTime::getScore()
{
    return score;
}*/
