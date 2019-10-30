#include "Mediumlvl.h"
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Menu.h"
#include <QGraphicsSceneMouseEvent>

extern Menu * menu;

Medium::Medium(QGraphicsItem *parent,bool active):QObject(),QGraphicsPixmapItem(parent)
{


    if (active==true){
    setPixmap(QPixmap(":/images/activemediumselect.png"));
    }else{
     setPixmap(QPixmap(":/images/mediumselect.png"));
    }

}
