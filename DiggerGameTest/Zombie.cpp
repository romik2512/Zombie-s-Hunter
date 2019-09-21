#include "Zombie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "Game.h"


extern Game * game;

Zombie::Zombie(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{

        setPixmap(QPixmap(":/images/player1right.png"));

}
void Zombie::create()
{

}
