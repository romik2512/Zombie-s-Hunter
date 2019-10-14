#include "NG.h"
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Menu.h"
#include <QGraphicsSceneMouseEvent>

extern Menu * menu;

NG::NG(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{    
setPixmap(QPixmap(":/images/newgame.png"));   
}

