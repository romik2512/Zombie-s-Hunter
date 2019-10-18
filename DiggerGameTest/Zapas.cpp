#include "Zapas.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game *game;

Zapas::Zapas(QGraphicsItem *parent): QGraphicsTextItem(parent){

    //bomb=6;
    setPlainText(QString::number(game->bomb));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",34));

}

void Zapas::decrease()
{
    game->bomb--;
    setPlainText(QString::number(game->bomb));
}
