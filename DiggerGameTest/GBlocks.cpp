#include "GBlocks.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

GBlocks::GBlocks(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
setPixmap(QPixmap(":/images/blackblock.png"));
}
