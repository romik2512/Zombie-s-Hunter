#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Game.h"

extern Game * game;
Player::Player(QGraphicsItem*parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/player1right.png"));
   // this->setPos(200,50);
}

void Player::keyPressEvent(QKeyEvent *event)
{

if (event->key() ==Qt::Key_Left){
 /*  h=pos().y();
   w=pos().x();
    if (game->blocksarray[w][h] ==true){*/
    if((pos().x()-8)>=50){
    setPos(x()-8,y());
    qDebug() <<"X:"<<x()<<"  Y"<<y();
    }
}else if(event->key()==Qt::Key_Right){
    if ((pos().x())+40<650){
    setPos(x()+8,y());
    qDebug() <<"X:"<<x()<<"  Y"<<y();
    }
}else if(event->key()==Qt::Key_Up){
    if ((pos().y()-8)>=50){
    setPos(x(),y()-8);
    qDebug() <<"X:"<<x()<<"  Y"<<y();
    }
}else if(event->key()==Qt::Key_Down){
    if ((pos().y()+40)<650){
    setPos(x(),y()+8);
    qDebug() <<"X:"<<x()<<"  Y"<<y();
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



