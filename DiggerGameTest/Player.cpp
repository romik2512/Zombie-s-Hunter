#include "Player.h"
#include <QKeyEvent>
#include "Game.h"
#include "GBlocks.h"
#include "Dynamit.h"
#include "Zombie.h"
#include "LavaBlocks.h"
#include "Zapas.h"
#include <QDebug>

extern Game * game;
extern Zapas * zapas;
extern Menu*menu;
extern Player *player;

Player::Player(bool napro,bool massnapr[5],QGraphicsItem*parent): QGraphicsPixmapItem(parent) {
    if (napro==true) {
        setPixmap(QPixmap(":/images/player1right.png"));
        napr=true;
    } else {
        setPixmap(QPixmap(":/images/player1left.png"));
        napr=false;
    }

    for(int m=0; m<5; m++) {
        playermoves[m]=massnapr[m];
    }
    playermovevalue=2;
    usetimer=false;
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(pmove()));
    timer->start(15);
}

Player::~Player() {
    if (game->enemies>0) {
        menu=new Menu('l',game->gamelevel);
        game->~Game();
    }
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() ==Qt::Key_Space) {
        playermoves[4]=true;
    }
    else if (event->key() ==Qt::Key_Left) {
        playermoves[0]=true;
    }
    else if (event->key() ==Qt::Key_Up) {
        playermoves[1]=true;
    }
    else if (event->key() ==Qt::Key_Right) {
        playermoves[2]=true;
    }
    else if (event->key() ==Qt::Key_Down) {
        playermoves[3]=true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *revent) {
    if (revent->key() ==Qt::Key_Space) {
        playermoves[4]=false;
    }
    else if (revent->key() ==Qt::Key_Left) {
        playermoves[0]=false;
    }
    else if (revent->key() ==Qt::Key_Up) {
        playermoves[1]=false;
    }
    else if (revent->key() ==Qt::Key_Right) {
        playermoves[2]=false;
    }
    else if (revent->key() ==Qt::Key_Down) {
        playermoves[3]=false;
    }
}

void Player::pmove() {

    if (playermoves[4]==true) {
        if(game->bomb>0) {

            int posx=pos().x();
            int ostx=(posx-50) % 40;
            int posy=pos().y();
            int osty=(posy-50) % 40;

            if (ostx>20) ostx=ostx-40;
            if (osty>20) osty=osty-40;

            if (!(typeid(Dynamit)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform()))))) {
                QList<QGraphicsItem *> kopatel=game->scene->items(posx-ostx,posy-osty,40,40,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());
                for(int i =0,n=kopatel.size(); i<n; ++i) {
                    if(!(((typeid(Zombie))==(typeid (*(kopatel[i]))))||((typeid(Player))==(typeid (*(kopatel[i])))))) {
                        scene()->removeItem(kopatel[i]);
                    }
                }

                Dynamit* dynamit=new Dynamit();
                dynamit->setPos(pos().x()-ostx,pos().y()-osty);
                game->scene->addItem(dynamit);
                zapas->decrease();

                scene()->removeItem(player);
                player->setPos(pos().x(),pos().y());
                player->setFlag(QGraphicsItem::ItemIsFocusable);
                player->setFocus();
                game->scene->addItem(player);
            }
        }
    }

    if (playermoves[0]==true) {
        if(playermoves[2]==false) {
            if(pos().x()>50+playermovevalue-1) {
                int posx=pos().x();
                int posy=pos().y();
                int osty=(posy-50)%40;
                if (osty<10) {
                    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()-osty,QTransform())))))) {

                        setPos(x()-playermovevalue,y()-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx-playermovevalue,posy-osty);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                        if (napr==true) {
                            napr=false;
                            if (usetimer==true) {
                                setPixmap(QPixmap(":/images/player1leftfire.png"));
                            } else {
                                setPixmap(QPixmap(":/images/player1left.png"));
                            }
                            player->setPos(posx-playermovevalue,posy-osty);
                            player->setFlag(QGraphicsItem::ItemIsFocusable);
                            player->setFocus();
                        }
                    }
                } else if (osty>40-playermovevalue-1) {
                    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()+40-osty,QTransform())))))) {
                        setPos(x()-playermovevalue,y()+40-osty);

                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx-playermovevalue,posy+40-osty);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                        if (napr==true) {
                            napr=false;
                            if (usetimer==true) {
                                setPixmap(QPixmap(":/images/player1leftfire.png"));
                            } else {
                                setPixmap(QPixmap(":/images/player1left.png"));
                            }
                            player->setPos(posx-playermovevalue,posy+40-osty);
                            player->setFlag(QGraphicsItem::ItemIsFocusable);
                            player->setFocus();
                        }
                    }
                }
            }
        }
    }
    if (playermoves[2]==true) {
        if(playermoves[0]==false) {
            if(pos().x()+40<650) {
                int posx=pos().x();
                int posy=pos().y();
                int osty=(posy-50)%40;

                if (osty<10) {
                    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()-osty,QTransform())))))) {

                        setPos(x()+playermovevalue,y()-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx+playermovevalue,posy-osty);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                        if (napr==false) {
                            napr=true;
                            if (usetimer==true) {
                                setPixmap(QPixmap(":/images/player1rightfire.png"));
                            } else {
                                setPixmap(QPixmap(":/images/player1right.png"));
                            }
                            player->setPos(posx+playermovevalue,posy-osty);
                            player->setFlag(QGraphicsItem::ItemIsFocusable);
                            player->setFocus();
                        }
                    }
                } else if (osty>40-playermovevalue-1) {
                    if (!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform())))))) {
                        setPos(x()+playermovevalue,y()+40-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx+playermovevalue,posy+40-osty);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                        if (napr==false) {
                            napr=true;
                            if (usetimer==true) {
                                setPixmap(QPixmap(":/images/player1rightfire.png"));
                            } else {
                                setPixmap(QPixmap(":/images/player1right.png"));
                            }
                            player->setPos(posx+playermovevalue,posy+40-osty);
                            player->setFlag(QGraphicsItem::ItemIsFocusable);
                            player->setFocus();
                        }
                    }
                }
            }

        }
    }
    if (playermoves[1]==true) {
        if(playermoves[3]==false) {
            if (pos().y()>50+playermovevalue-1) {

                int posx=pos().x();
                int posy=pos().y();
                int ostx=(posx-50)%40;
                if (ostx < playermovevalue+1) {
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-playermovevalue,QTransform()))))))) {
                        setPos(x()-ostx,y()-playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx-ostx,posy-playermovevalue);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                    }
                } else if (ostx>40-playermovevalue-1) {

                    if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-playermovevalue,QTransform())))))) {
                        setPos(x()+40-ostx,y()-playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx+40-ostx,posy-playermovevalue);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (playermoves[3]==true) {
        if(playermoves[1]==false) {
            if (pos().y()+40<650) {
                int posx=pos().x();
                int posy=pos().y();
                int ostx=(posx-50)%40;

                if (ostx < playermovevalue+1) {
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+40,QTransform()))))))) {
                        setPos(x()-ostx,y()+playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx-ostx,posy+playermovevalue);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                    }
                } else if (ostx>40-playermovevalue-1) {

                    if(!((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+40,QTransform())))))) {
                        setPos(x()+40-ostx,y()+playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }  else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                    }
                                    else {
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                    }
                                    scene()->removeItem(player);
                                    player->setPos(posx+40-ostx,posy+playermovevalue);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire()));
                                    firetimer->start(500*ironmode);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Player::checkfire() {
    usetimer=false;
    firetimer->stop();
    if(napr==true) {
        setPixmap(QPixmap(":/images/player1right.png"));
    }
    else {
        setPixmap(QPixmap(":/images/player1left.png"));
    }
    QList<QGraphicsItem*> collides=collidingItems();
    for(int i =0,n=collides.size(); i<n; ++i) {
        if (typeid(*(collides[i]))==typeid(Lava)) {
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}





