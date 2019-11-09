#include "Crash.h"
#include <QTimer>

Crash::Crash(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/crash.png"));
    QTimer * crashtimer =new QTimer();
    connect(crashtimer,SIGNAL(timeout()),this,SLOT(deletecrash()));
    crashtimer->start(1500);
}

void Crash::deletecrash()
{
    delete this;
}
