#include "NewDynamit.h"

NewDynamit::NewDynamit(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Dynamit.png"));
}
