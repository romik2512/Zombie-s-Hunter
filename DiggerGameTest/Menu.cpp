#include "Menu.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "GBlocks.h"
#include "EarthBlocks.h"
#include "Zombie.h"
#include "Player.h"
#include <QDebug>
#include <QBrush>
#include "Gametime.h"
#include "Zapas.h"
#include "Kolvo.h"
#include "NG.h"

Menu::Menu(QWidget*parent){
mscene=new QGraphicsScene();
mscene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/testmenu2.png")));
setScene(mscene);

//connect(mscene,mousePressEvent(),this,mousePressEvent());

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

NG* ng=new NG();
ng->setPos(250,200);
mscene->addItem(ng);




}

/*void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

qDebug() <<"POSX: " << event->pos().x();

}*/
