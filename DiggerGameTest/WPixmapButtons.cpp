#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "WinGame.h"
#include "WPixmapButtons.h"

WinGame * winscene;

Buttons::Buttons(char button,QGraphicsItem*parent){
if (button=='r'){
setPixmap(QPixmap(":/images/restartwingame.png"));
}
else{
setPixmap(QPixmap(":/images/wintomenu.png"));
}
}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *eventer){
    delete winscene;
    qDebug()<<"CHEEE&";
}
