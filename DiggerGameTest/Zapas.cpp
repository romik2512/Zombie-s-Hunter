#include "Zapas.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game *game;

Zapas::Zapas(QGraphicsItem *parent): QGraphicsTextItem(parent){

    bomb=6;



    //setPlainText(QString("Time: ")+QString::number(gtime));
    setPlainText(QString::number(bomb));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",34));

}

void Zapas::decrease()
{
    qDebug() <<"POGCHAMP!!!!!!!!!!!!!!!!!!!!";
    bomb--;
    //setPlainText(QString("Time: ")+QString::number(gtime));
    setPlainText(QString::number(bomb));
   // setDefaultTextColor(Qt::yellow);
    //setFont(QFont("times",30));
}
