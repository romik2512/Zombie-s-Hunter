#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Game.h"
#include "GBlocks.h"
#include "QList"
#include "Dynamit.h"
#include "Zombie.h"
#include "LavaBlocks.h"
#include "Zapas.h"
#include "Menu.h"
#include "Kolvo.h"
#include "Gametime.h"

extern Game * game;
extern Zapas * zapas;
extern Menu*menu;
extern Player *player;
//extern GTime *gametime;
//extern Kolvo *kolvo;

Player::Player(bool napro,QGraphicsItem*parent): QGraphicsPixmapItem(parent){
    if (napro==true) {
    setPixmap(QPixmap(":/images/player1right.png"));
    napr=true;
    } else {
        setPixmap(QPixmap(":/images/player1left.png"));
        napr=false;
    }
}

Player::~Player(){
    if (game->enemies>0){
    menu=new Menu('l',game->gamelevel);
    game->~Game();
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{

if   (event->key() ==Qt::Key_Space){
if(game->bomb>0) {

    int posx=pos().x();
    int ostx=(posx-50) % 40;
    int posy=pos().y();
    int osty=(posy-50) % 40;

    if (ostx>20) ostx=ostx-40;
    if (osty>20) osty=osty-40;

    if (!(typeid(Dynamit)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform()))))){
     QList<QGraphicsItem *> kopatel=game->scene->items(posx-ostx,posy-osty,40,40,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform()); // Перед сном здесь ковырялся, именнно проверку зомби добавил хз зачем )))
           for(int i =0,n=kopatel.size();i<n;++i){
               if(!((typeid(Zombie))==(typeid (*(kopatel[i]))))){
                      scene()->removeItem(kopatel[i]);
           }
           }



Dynamit* dynamit=new Dynamit();
dynamit->setPos(pos().x()-ostx,pos().y()-osty);
game->scene->addItem(dynamit);
zapas->decrease();

//Player* player=new Player(napr);
player=new Player(napr);
player->setPos(pos().x(),pos().y());
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
game->scene->addItem(player);
}
}
}

if (event->key() ==Qt::Key_Left){
    if(pos().x()>57){
        int posx=pos().x();
    int posy=pos().y();
    int osty=(posy-50)%40;
    if (osty<10){
        if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y()-osty,QTransform())))))){

             setPos(x()-8,y()-osty);           
             QList<QGraphicsItem*> collides=collidingItems();
             for(int i =0,n=collides.size();i<n;++i){

             if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                 scene()->removeItem(this);
                 delete this;                 
                 return;
             }
     }
             if (napr==true) {
                napr=false;                
                scene()->removeItem(this);

             //Player * player=new Player(napr);
             player=new Player(napr);
             player->setPos(posx-8,posy-osty);
             player->setFlag(QGraphicsItem::ItemIsFocusable);
             player->setFocus();
             game->scene->addItem(player);
             }
        }
    } else if (osty>30){            
            if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-8,pos().y()+40-osty,QTransform())))))){
                setPos(x()-8,y()+40-osty);

                QList<QGraphicsItem*> collides=collidingItems();
                for(int i =0,n=collides.size();i<n;++i){

               if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                    scene()->removeItem(this);
                    delete this;                  
                    return;
                }
        }
                if (napr==true) {
                   napr=false;
                   //delete this;
                   scene()->removeItem(this);

                //Player * player=new Player(napr);
                player=new Player(napr);
                player->setPos(posx-8,posy+40-osty);
                player->setFlag(QGraphicsItem::ItemIsFocusable);
                player->setFocus();
                game->scene->addItem(player);
                }
    }
    }
}
}else if(event->key()==Qt::Key_Right){

if(pos().x()+40<650){
    int posx=pos().x();
    int posy=pos().y();
    int osty=(posy-50)%40;

    if (osty<10){
        if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()-osty,QTransform())))))){

             setPos(x()+8,y()-osty);
             QList<QGraphicsItem*> collides=collidingItems();
             for(int i =0,n=collides.size();i<n;++i){

             if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                 scene()->removeItem(this);
                 delete this;
                 return;
             }
     }
             if (napr==false) {
                    napr=true;
                    scene()->removeItem(this);
                // delete this;
                // Player * player=new Player(napr);
                 player=new Player(napr);
                 player->setPos(posx+8,posy-osty);
                 player->setFlag(QGraphicsItem::ItemIsFocusable);
                 player->setFocus();
                 game->scene->addItem(player);
                 }
        }
    } else if (osty>30){            
            if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform())))))){
                setPos(x()+8,y()+40-osty);
                QList<QGraphicsItem*> collides=collidingItems();
                for(int i =0,n=collides.size();i<n;++i){

                if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
        }
                if (napr==false) {
                       napr=true;
                       scene()->removeItem(this);
                    //Player * player=new Player(napr);
                    player=new Player(napr);
                    player->setPos(posx+8,posy+40-osty);
                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                    player->setFocus();
                    game->scene->addItem(player);
                    }
            }
        }
    }


}else if(event->key()==Qt::Key_Up){
    if (pos().y()>57){

        int posx=pos().x();
        int ostx=(posx-50)%40;
        if (ostx < 10) {
            if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-8,QTransform()))))))){               
                 setPos(x()-ostx,y()-8);
                 QList<QGraphicsItem*> collides=collidingItems();
                 for(int i =0,n=collides.size();i<n;++i){

                 if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                     scene()->removeItem(this);
                     delete this;
                     return;
                 }
         }
            }
        }else if (ostx>30) {

            if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-8,QTransform())))))){       
         setPos(x()+40-ostx,y()-8);
         QList<QGraphicsItem*> collides=collidingItems();
         for(int i =0,n=collides.size();i<n;++i){

         if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
             scene()->removeItem(this);
             delete this;
             return;
         }
 }         
    }
 }
}
}else if(event->key()==Qt::Key_Down){
    if (pos().y()+40<650){
        int posx=pos().x();
        int ostx=(posx-50)%40;

        if (ostx < 10) {
            if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+40,QTransform()))))))){               
                 setPos(x()-ostx,y()+8);
                 QList<QGraphicsItem*> collides=collidingItems();
                 for(int i =0,n=collides.size();i<n;++i){

                 if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
                     scene()->removeItem(this);
                     delete this;
                     return;
                 }
         }                
            }
        }else if (ostx>30) {

            if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+40,QTransform())))))){
         setPos(x()+40-ostx,y()+8);
         QList<QGraphicsItem*> collides=collidingItems();
         for(int i =0,n=collides.size();i<n;++i){

         if ((typeid(*(collides[i]))==typeid(Zombie))||(typeid(*(collides[i]))==typeid(Lava))){
             scene()->removeItem(this);
             delete this;
             return;
         }
 }         
    }
 }
}
 }
}






