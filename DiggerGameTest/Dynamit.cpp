#include "Dynamit.h"

Dynamit::Dynamit(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/earthwithdynamite.png"));
}
