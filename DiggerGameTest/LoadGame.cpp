#include "LoadGame.h"
#include <QBrush>
Load::Load(QGraphicsItem *parent)
{
    loadscene=new QGraphicsScene();
    loadscene->setSceneRect(0,0,900,700);

    setBackgroundBrush(QBrush(QImage(":/images/loadgame.png")));
    setScene(loadscene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,700);
    this->show();
}

