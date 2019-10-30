#include "Easylvl.h"
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Menu.h"
#include <QGraphicsSceneMouseEvent>

extern Menu * menu;

Easy::Easy(QGraphicsItem *parent,bool active):QObject(),QGraphicsPixmapItem(parent)
{
    if (active==true){
    setPixmap(QPixmap(":/images/activeeasyselect.png"));
    }else{
     setPixmap(QPixmap(":/images/easyselect.png"));
    }

}
