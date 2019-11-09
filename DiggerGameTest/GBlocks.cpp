#include "GBlocks.h"

GBlocks::GBlocks(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/blackblock.png"));
}
