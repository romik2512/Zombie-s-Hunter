#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Game.h"
#include "GBlocks.h"
#include "QList"
#include "QRectF"

extern Game * game;
Player::Player(QGraphicsItem*parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/player1right.png"));
   // this->setPos(200,50);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //QGraphicsItem *item=scene->itemAt(60,60,QTransform());

if (event->key() ==Qt::Key_Left){
    if(pos().x()>57){

       /* QList<QGraphicsItem *> Gitems=game->scene->items(pos().x()-8,pos().y(),40,40,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());
        for(int i =0,n=Gitems.size();i<n;++i){
                   if((typeid(GBlocks))==(typeid(*(Gitems[i])))) break;

                qDebug() << typeid (*(Gitems[i])).name();*/

               // qDebug() << typeid(Enemy).name();

       if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y(),QTransform())))))||((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y()+32,QTransform()))))))){
           qDebug() << typeid (GBlocks).name();
           qDebug() << typeid(*(game->scene->itemAt(pos().x()-8,pos().y(),QTransform()))).name();
            setPos(x()-8,y());
            qDebug() <<"X:"<<x()<<"  Y"<<y();
       }else qDebug() <<"X:"<<game->scene->itemAt(pos().x()-8,pos().y(),QTransform())<<"  Y"<<y();

    }
}else if(event->key()==Qt::Key_Right){

if(pos().x()+40<650){
   //if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))){
    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform())))))||((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+32,QTransform()))))))){
       qDebug() << typeid (GBlocks).name();
       qDebug() << typeid(*(game->scene->itemAt(pos().x()+40,pos().y(),QTransform()))).name();
        setPos(x()+8,y());
        qDebug() <<"X:"<<x()<<"  Y"<<y();   
   }else qDebug() <<"X:"<<game->scene->itemAt(pos().x()+40,pos().y(),QTransform())<<"  Y"<<y();
}
}else if(event->key()==Qt::Key_Up){
    if (pos().y()>57){
    //if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-8,QTransform())))))){
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()-8,QTransform())))))||((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+32,pos().y()-8,QTransform()))))))){
        qDebug() << typeid (GBlocks).name();
        qDebug() << typeid(*(game->scene->itemAt(pos().x(),pos().y()-8,QTransform()))).name();
         setPos(x(),y()-8);
         qDebug() <<"X:"<<x()<<"  Y"<<y();
    }else qDebug() <<"X:"<<game->scene->itemAt(pos().x(),pos().y()-8,QTransform())<<"  Y"<<y();
 }

}else if(event->key()==Qt::Key_Down){
    if (pos().y()+40<650){
    // if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))){
        if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform())))))||((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+32,pos().y()+40,QTransform()))))))){
            qDebug() << typeid (GBlocks).name();
            qDebug() << typeid(*(game->scene->itemAt(pos().x(),pos().y()+40,QTransform()))).name();
             setPos(x(),y()+8);
             qDebug() <<"X:"<<x()<<"  Y"<<y();
        }else qDebug() <<"X:"<<game->scene->itemAt(pos().x(),pos().y()+40,QTransform())<<"  Y"<<y();
    }
}
}



/*else if (event->key()==Qt::Key_Space){
    Bullet * bullet =new Bullet();
    bullet->setPos(x(),y());
    scene()->addItem(bullet);

     if (bulletsound->state()==QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
    else if (bulletsound->state()==QMediaPlayer::StoppedState){
      bulletsound->play();
     }

    qDebug() <<"Bullet created!";
}*/



