#include "Hardlvl.h"
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Menu.h"
#include <QGraphicsSceneMouseEvent>

//extern Menu * menu;

Hard::Hard(QGraphicsItem *parent,bool active):QObject(),QGraphicsPixmapItem(parent)
{


    if (active==true){
    setPixmap(QPixmap(":/images/activehardselect.png"));
    }else{
     setPixmap(QPixmap(":/images/hardselect.png"));
    }

}
