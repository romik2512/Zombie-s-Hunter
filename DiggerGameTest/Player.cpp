#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Game.h"
#include "GBlocks.h"
#include "QList"
#include "Dynamit.h"


extern Game * game;
Player::Player(QGraphicsItem*parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/player1right.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{


   /* if((event->key()==Qt::Key_Space)&&(event->key()==Qt::Key_Left)){
        qDebug()<< "YEEES";
    }*/

if   (event->key() ==Qt::Key_Space){

    int posx=pos().x();
    int ostx=(posx-50) % 40;
    int posy=pos().y();
    int osty=(posy-50) % 40;


   qDebug() << "ostX: " << ostx<<"ostY: " <<osty;
    qDebug() << "X: " << posx-ostx<<"Y: " << posy-osty;

    if (ostx>20) ostx=ostx-40;
    if (osty>20) osty=osty-40;

     QList<QGraphicsItem *> kopatel=game->scene->items(posx-ostx,posy-osty,40,40,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());
           for(int i =0,n=kopatel.size();i<n;++i){
                      scene()->removeItem(kopatel[i]);
           }

Dynamit* dynamit=new Dynamit();
dynamit->setPos(pos().x()-ostx,pos().y()-osty);
game->scene->addItem(dynamit);

Player* player=new Player();
player->setPos(pos().x(),pos().y());
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
game->scene->addItem(player);

}

if (event->key() ==Qt::Key_Left){
    if(pos().x()>57){
    int posy=pos().y();
    int osty=(posy-50)%40;
    qDebug()<<"OSTY: "<<osty;

    if (osty<10){
        if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y()-osty,QTransform())))))){

             setPos(x()-8,y()-osty);
        }
    } else if (osty>30){
            qDebug()<<typeid(*(game->scene->itemAt(pos().x()-8,pos().y()+40-osty,QTransform()))).name();
            if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y()+40-osty,QTransform())))))){
                qDebug() <<"YES";
                setPos(x()-8,y()+40-osty);
            }
        }
    }

}else if(event->key()==Qt::Key_Right){

if(pos().x()+40<650){

    int posy=pos().y();
    int osty=(posy-50)%40;
    qDebug()<<"OSTY: "<<osty;



    if (osty<10){
        if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()-osty,QTransform())))))){

             setPos(x()+8,y()-osty);
        }
    } else if (osty>30){
            qDebug()<<typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform()))).name();
            if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform())))))){
                qDebug() <<"YES";
                setPos(x()+8,y()+40-osty);
            }
        }
    }


}else if(event->key()==Qt::Key_Up){
    if (pos().y()>57){

        int posx=pos().x();
        int ostx=(posx-50)%40;
        qDebug() << "OSTX: "<<ostx;
        if (ostx < 10) {
            if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-8,QTransform()))))))){
                qDebug() << typeid (GBlocks).name();
                qDebug() << typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-8,QTransform()))).name();
                 setPos(x()-ostx,y()-8);
                 qDebug() <<"X:"<<x()<<"  Y"<<y();
            }
        }else if (ostx>30) {

            if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-8,QTransform())))))){
        qDebug() << typeid (GBlocks).name();
        qDebug() << typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-8,QTransform()))).name();
         setPos(x()+40-ostx,y()-8);
         qDebug() <<"X:"<<x()<<"  Y"<<y();
    }else qDebug() <<"X:"<<game->scene->itemAt(pos().x(),pos().y()-8,QTransform())<<"  Y"<<y();
 }
}
}else if(event->key()==Qt::Key_Down){
    if (pos().y()+40<650){
        int posx=pos().x();
        int ostx=(posx-50)%40;

        if (ostx < 10) {
            if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+40,QTransform()))))))){
                qDebug() << typeid (GBlocks).name();
                qDebug() << typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+8,QTransform()))).name();
                 setPos(x()-ostx,y()+8);
                 qDebug() <<"X:"<<x()<<"  Y"<<y();
            }
        }else if (ostx>30) {

            if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+40,QTransform())))))){
        qDebug() << typeid (GBlocks).name();
        qDebug() << typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+8,QTransform()))).name();
         setPos(x()+40-ostx,y()+8);
         qDebug() <<"X:"<<x()<<"  Y"<<y();
    }else qDebug() <<"X:"<<game->scene->itemAt(pos().x()+40-ostx,pos().y()+8,QTransform())<<"  Y"<<y();
 }
}
 }
}




