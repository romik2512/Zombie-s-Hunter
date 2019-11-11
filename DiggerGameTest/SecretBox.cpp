#include "SecretBox.h"

SecretBox::SecretBox(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
   setPixmap(QPixmap(":/images/secretbox.png"));
}

