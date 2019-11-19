#include "Gametime.h"
#include <QFont>
#include "Game.h"
#include "GBlocks.h"
#include "Player.h"
#include "Zombie.h"
#include "Kolvo.h"
#include "Crash.h"
#include "Menu.h"
#include <QDebug>

extern Game *game;
extern Kolvo * kolvo;
extern Menu*menu;

GTime::GTime(QGraphicsItem *parent): QGraphicsTextItem(parent) {

    gtime=0;
    setPlainText(QString::number(gtime));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",30));

  blocksincrease=new QTimer();
  connect(blocksincrease,SIGNAL(timeout()),this,SLOT(increase()));
  connect(blocksincrease,SIGNAL(timeout()),this,SLOT(addblocks()));
    blocksincrease->start(1000);
    kvadr=15;
    line=0;
    schet=0;

    ugol=qrand() %4;

    if (qrand() % 2 ==0) {
        blocksnapr=false;
    } else {
        blocksnapr=true;
    }
    blocksnapr=true;
    if (ugol==0) {
        gbx=50;
        gby=50;
    } else if (ugol==1) {
        gbx=610;
        gby=50;
    } else if (ugol==3) {
        gbx=50;
        gby=610;
    } else {
        gbx=610;
        gby=610;
    }
}

void GTime::increase()
{
    gtime++;
    setPlainText(QString::number(gtime));
}

void GTime::addblocks() {
    bool checkzombie=false;
    if (kvadr>-1) {
        if (gtime>4) {

            QList<QGraphicsItem*> colliding_items=game->scene->items(gbx,gby,35,35,Qt::IntersectsItemShape,Qt::AscendingOrder,QTransform());
            for (int i=0,n=colliding_items.size(); i<n; ++i) {
                if(typeid (*(colliding_items[i]))==typeid(Player)) {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    return;
                } else if(typeid (*(colliding_items[i]))==typeid(Zombie)) {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    kolvo->decrease();
                    checkzombie=true; // При одновременном уничтожении 2, уничтожается 1 )) Поэтому kolvo decresde сюда
                } else {
                    game->scene->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                }
            }

            GBlocks* gblocks=new GBlocks();
            gblocks->setPos(gbx,gby);
            schet++;
            game->scene->addItem(gblocks);

            if(checkzombie==true) {
                //kolvo->decrease();
                Crash* crash=new Crash();
                crash->setPos(gbx-10,gby-10);
                game->scene->addItem(crash);
            }

            if (blocksnapr==false) {
                if (line==0) {

                    if (ugol==0) {
                        gby+=40;
                    } else if(ugol==1) {
                        gbx=gbx-40;
                    } else if(ugol==2) {
                        gby=gby-40;
                    } else if(ugol==3) {
                        gbx+=40;
                    }
                    if (schet==kvadr-1) {
                        line++;
                        schet=-1;
                        if (ugol==0) {
                            ugol=3;
                        } else ugol--;
                    }

                } else if(line==1) {
                    if (ugol==0) {
                        gby+=40;
                    } else if(ugol==1) {
                        gbx=gbx-40;
                    } else if(ugol==2) {
                        gby=gby-40;
                    } else if(ugol==3) {
                        gbx+=40;
                    }

                    if (schet==kvadr-2) {
                        line++;
                        schet=-1;
                        if (ugol==0) {
                            ugol=3;
                        } else ugol--;
                    }
                }
                else if(line==2) {
                    if (ugol==0) {
                        gby+=40;
                    } else if(ugol==1) {
                        gbx=gbx-40;
                    } else if(ugol==2) {
                        gby=gby-40;
                    } else if(ugol==3) {
                        gbx+=40;
                    }

                    if (schet==kvadr-2) {
                        line++;
                        schet=-1;
                        if (ugol==0) {
                            ugol=3;
                        } else ugol--;
                    }
                } else if(line==3) {
                    if (ugol==0) {
                        gby+=40;
                    } else if(ugol==1) {
                        gbx=gbx-40;
                    } else if(ugol==2) {
                        gby=gby-40;
                    } else if(ugol==3) {
                        gbx+=40;
                    }

                    if (schet==kvadr-3) {
                        line=0;
                        schet=-1;
                        if (ugol==0) {
                            ugol=3;
                        } else ugol--;
                        kvadr=kvadr-2;
                    }
                }


            } else {
                if (line==0) {

                    if (ugol==0) {
                        gbx+=40;
                    } else if(ugol==1) {
                        gby+=40;
                    } else if(ugol==2) {
                        gbx=gbx-40;
                    } else if(ugol==3) {
                        gby=gby-40;
                    }
                    if (schet==kvadr-1) {
                        line++;
                        schet=-1;
                        if (ugol==3) {
                            ugol=0;
                        } else ugol++;
                    }

                } else if(line==1) {
                    if (ugol==0) {
                        gbx+=40;
                    } else if(ugol==1) {
                        gby+=40;
                    } else if(ugol==2) {
                        gbx=gbx-40;
                    } else if(ugol==3) {
                        gby=gby-40;
                    }

                    if (schet==kvadr-2) {
                        line++;
                        schet=-1;
                        if (ugol==3) {
                            ugol=0;
                        } else ugol++;
                    }
                }
                else if(line==2) {
                    if (ugol==0) {
                        gbx+=40;
                    } else if(ugol==1) {
                        gby+=40;
                    } else if(ugol==2) {
                        gbx=gbx-40;
                    } else if(ugol==3) {
                        gby=gby-40;
                    }

                    if (schet==kvadr-2) {
                        line++;
                        schet=-1;
                        if (ugol==3) {
                            ugol=0;
                        } else ugol++;
                    }
                } else if(line==3) {
                    if (ugol==0) {
                        gbx+=40;
                    } else if(ugol==1) {
                        gby+=40;
                    } else if(ugol==2) {
                        gbx=gbx-40;
                    } else if(ugol==3) {
                        gby=gby-40;
                    }

                    if (schet==kvadr-3) {
                        line=0;
                        schet=-1;
                        if (ugol==3) {
                            ugol=0;
                        } else ugol++;
                        kvadr=kvadr-2;
                    }
                }

            }

        }
    }
}

GTime::~GTime(){
    blocksincrease->stop();
    disconnect(blocksincrease,SIGNAL(timeout()));
}
