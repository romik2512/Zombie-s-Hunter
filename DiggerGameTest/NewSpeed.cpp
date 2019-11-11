#include "NewSpeed.h"

NewSpeed::NewSpeed(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/forspeed.png"));
}
