#include "FireBoost.h"

FireBoost::FireBoost(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/FireBoost.png"));
}
