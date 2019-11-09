#include "EarthBlocks.h"

EBlocks::EBlocks(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    int random_number=qrand() % 5;
    if (random_number==0){
        setPixmap(QPixmap(":/images/earth3.png"));
        }else if (random_number==1){
            setPixmap(QPixmap(":/images/earth.png"));
        }else if (random_number==2){
            setPixmap(QPixmap(":/images/earth5.png"));
        }else if (random_number==3){
            setPixmap(QPixmap(":/images/earth6.png"));
        }else if (random_number==4){
            setPixmap(QPixmap(":/images/earth.png"));
        }
}

