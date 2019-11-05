#include "LavaBlocks.h"

Lava::Lava(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
setPixmap(QPixmap(":/images/lavablock.png"));
}
