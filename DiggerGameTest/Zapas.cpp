#include "Zapas.h"
#include "Game.h"

extern Game *game;

Zapas::Zapas(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString::number(game->bomb));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",34));
}

void Zapas::decrease()
{
    game->bomb--;
    setPlainText(QString::number(game->bomb));
}

void Zapas::increase()
{
    game->bomb++;
    setPlainText(QString::number(game->bomb));
}
