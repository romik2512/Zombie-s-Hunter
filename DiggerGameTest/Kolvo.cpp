#include "Kolvo.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game *game;

Kolvo::Kolvo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    enemies=6;

    setPlainText(QString::number(enemies));
    setDefaultTextColor(QColor(242,160,7));
    setFont(QFont("times",34));

}

void Kolvo::decrease()
{
    enemies--;
    setPlainText(QString::number(enemies));
}
