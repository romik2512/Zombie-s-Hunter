#include "Player.h"
#include <QKeyEvent>
#include "Game.h"
#include "GBlocks.h"
#include "Dynamit.h"
#include "Zombie.h"
#include "LavaBlocks.h"
#include "Zapas.h"
#include "SecretBox.h"
#include "NewDynamit.h"
#include "NewSpeed.h"
#include "Bam.h"
#include "FireBoost.h"
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
    playerspeed=new QTimer();
    connect(playerspeed,SIGNAL(timeout()),this,SLOT(pmove()));
    playerspeed->start(15-boostspeed);
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

            bool candropbomb=true;

            int posx=pos().x();
            int ostx=(posx-50) % 40;
            int posy=pos().y();
            int osty=(posy-50) % 40;

            if (ostx>20) ostx=ostx-40;
            if (osty>20) osty=osty-40;

            //if (!((typeid(Dynamit)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform()))))||(typeid(Lava)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform()))))||(typeid(Bam)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform())))))) {
                if (!(typeid(Dynamit)==typeid(*(game->scene->itemAt(posx-ostx,posy-osty,QTransform()))))){
                QList<QGraphicsItem *> kopatel=game->scene->items(posx-ostx,posy-osty,40,40,Qt::IntersectsItemShape,Qt::AscendingOrder, QTransform());
                for(int i =0,n=kopatel.size(); i<n; ++i) {
                    if(!(((typeid(Zombie))==(typeid (*(kopatel[i]))))||((typeid(Player))==(typeid (*(kopatel[i])))))) {
                        if(!(((typeid(Lava))==(typeid (*(kopatel[i]))))||((typeid(Bam))==(typeid (*(kopatel[i]))))||((typeid(Dynamit))==(typeid (*(kopatel[i])))))) {
                        scene()->removeItem(kopatel[i]);
                       } else{
                           candropbomb=false;
                       }
                    }
                }
                if (candropbomb==true){
                Dynamit* dynamit=new Dynamit();
                dynamit->setPos(pos().x()-ostx,pos().y()-osty);
                game->scene->addItem(dynamit);
                zapas->decrease();
                }

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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()-osty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()-osty,QTransform())))))))  {

                        setPos(x()-playermovevalue,y()-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()+40-osty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-playermovevalue,pos().y()+40-osty,QTransform())))))))  {
                        setPos(x()-playermovevalue,y()+40-osty);

                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
                                if(usetimer==false) {
                                    if(napr==true) {
                                        setPixmap(QPixmap(":/images/player1rightfire.png"));
                                                   }
                                        else{
                                        setPixmap(QPixmap(":/images/player1leftfire.png"));
                                            }
                                    scene()->removeItem(player);
                                    player->setPos(posx-playermovevalue,posy+40-osty);
                                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                                    player->setFocus();
                                    game->scene->addItem(player);
                                    usetimer=true;
                                    firetimer =new QTimer();
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                        }
                                    } else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                     zapas->increase();
                                     delete collides[i];
                                    } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                     playerspeed->stop();
                                     boostspeed+=5;
                                     playerspeed->start(15-boostspeed);
                                     delete collides[i];
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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()-osty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()-osty,QTransform())))))))  {

                        setPos(x()+playermovevalue,y()-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40,pos().y()+40-osty,QTransform())))))))  {
                        setPos(x()+playermovevalue,y()+40-osty);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                   // connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-playermovevalue,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()-playermovevalue,QTransform())))))))  {
                        setPos(x()-ostx,y()-playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
                               }
                        }
                    }
                } else if (ostx>40-playermovevalue-1) {

                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-playermovevalue,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()-playermovevalue,QTransform())))))))  {
                        setPos(x()+40-ostx,y()-playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                } else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
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
                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+40,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()-ostx,pos().y()+40,QTransform())))))))  {
                        setPos(x()-ostx,y()+playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {
                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                                ironmode=5;
                                delete collides[i];
                                }else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
                               }
                        }
                    }
                } else if (ostx>40-playermovevalue-1) {

                    if (!(((typeid(GBlocks))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+40,QTransform())))))||((typeid(SecretBox))==(typeid(*(game->scene->itemAt(pos().x()+40-ostx,pos().y()+40,QTransform())))))))  {
                        setPos(x()+40-ostx,y()+playermovevalue);
                        QList<QGraphicsItem*> collides=collidingItems();
                        for(int i =0,n=collides.size(); i<n; ++i) {

                            if ((typeid(*(collides[i])))==(typeid(Zombie))) {
                                scene()->removeItem(this);
                                delete this;
                                return;
                            }else if ((typeid(*(collides[i])))==(typeid(FireBoost))) {
                            ironmode=5;
                            delete collides[i];
                            }else if ((typeid(*(collides[i])))==(typeid(Lava))) {
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
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    //connect(firetimer,SIGNAL(timeout()),this,SLOT(checkfire(ironmode)));
                                    forfiretimers=ironmode;
                                    connect(firetimer,  &QTimer::timeout, this, [this]{checkfire(forfiretimers);});
                                    firetimer->start(500*forfiretimers);
                                }
                            }else if ((typeid(*(collides[i])))==(typeid(NewDynamit))) {
                                zapas->increase();
                                delete collides[i];
                               } else if ((typeid(*(collides[i])))==(typeid(NewSpeed))) {
                                playerspeed->stop();
                                boostspeed+=5;
                                playerspeed->start(15-boostspeed);
                                delete collides[i];
                               }
                        }
                    }
                }
            }
        }
    }
}

void Player::checkfire(int howmany) {
    usetimer=false;
    firetimer->stop();
    if (howmany==ironmode){
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
}





