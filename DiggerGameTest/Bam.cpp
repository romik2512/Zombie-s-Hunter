#include "Bam.h"
#include <QTimer>
Bam::Bam(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
setPixmap(QPixmap(":/images/bam.png"));
QTimer * bamtimer =new QTimer();
connect(bamtimer,SIGNAL(timeout()),this,SLOT(deletebam()));
bamtimer->start(1500);
}

void Bam::deletebam()
{
delete this;
}


