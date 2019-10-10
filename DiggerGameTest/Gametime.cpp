#include "Gametime.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>
#include "GBlocks.h"
#include "Player.h"
#include "Zombie.h"
#include "Kolvo.h"

extern Game *game;
extern Kolvo * kolvo;

GTime::GTime(QGraphicsItem *parent): QGraphicsTextItem(parent){

    gtime=0;
    setPlainText(QString::number(gtime));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",30));

    QTimer * gtimer =new QTimer();
    connect(gtimer,SIGNAL(timeout()),this,SLOT(increase()));
    connect(gtimer,SIGNAL(timeout()),this,SLOT(addblocks()));
    gtimer->start(1000);
    kvadr=15;
    line=0;
    schet=0;
    ugol=qrand() %4;
    if (qrand() % 2 ==0){
        blocksnapr=false;
    }else {
        blocksnapr=true;
    }
    blocksnapr=true;
    if (ugol==0){
        gbx=50;
        gby=50;
    }else if (ugol==1){
        gbx=610;
        gby=50;
    }else if (ugol==3){
        gbx=50;
        gby=610;
    }else {
        gbx=610;
        gby=610;
    }
}

void GTime::increase()
{
    gtime++;   
    setPlainText(QString::number(gtime));
}

void GTime::addblocks(){                                  // Можно добавить переменную, которая будет считать сколько уже построил, нализировать и поворачивать когда уже все ) это допустим schectchik , while (schetchik<=i*4 -4 ); где i это сколько нужно ставить блоков в линии и будем идти по квадрату как раз
    if (kvadr>-1){
    if (gtime>9){
       // QList<QGraphicsItem*> colliding_items=collidingItems();
       // for(int i =0,n=colliding_items.size();i<n;++i){
QList<QGraphicsItem*> colliding_items=game->scene->items(gbx,gby,40,40,Qt::IntersectsItemShape,Qt::AscendingOrder,QTransform());
for (int i=0,n=colliding_items.size();i<n;++i){
    if(typeid (*(colliding_items[i]))==typeid(Player)) {

        // ТУТ КОНЕЦ ИГРЫ ЛУЗ.
}if(typeid (*(colliding_items[i]))==typeid(Zombie)) {
        kolvo->decrease();
}
    scene()->removeItem(colliding_items[i]);
    delete colliding_items[i];
}
        //game->scene->removeItem(game->scene->itemAt(gbx,gby,QTransform()));  Здесь может быть траббл если будет зомби и еще что-то удалит верхний элемент же )
         GBlocks* gblocks=new GBlocks();
         gblocks->setPos(gbx,gby);
         schet++;
         game->scene->addItem(gblocks);
        if (blocksnapr==false){
            if (line==0){

if (ugol==0){
gby+=40;
}else if(ugol==1){
gbx=gbx-40;
}else if(ugol==2){
   gby=gby-40;
}else if(ugol==3){
    gbx+=40;
}
                if (schet==kvadr-1) {
                    line++;
                    schet=-1;
                    if (ugol==0){
                        ugol=3;
                    }else ugol--;
                }

            }else if(line==1){
                if (ugol==0){
                gby+=40;
                }else if(ugol==1){
                gbx=gbx-40;
                }else if(ugol==2){
                   gby=gby-40;
                }else if(ugol==3){
                    gbx+=40;
                }

                if (schet==kvadr-2) {
                    line++;
                    schet=-1;
                    if (ugol==0){
                        ugol=3;
                    }else ugol--;
                }
            }
            else if(line==2){
                if (ugol==0){
                gby+=40;
                }else if(ugol==1){
                gbx=gbx-40;
                }else if(ugol==2){
                   gby=gby-40;
                }else if(ugol==3){
                    gbx+=40;
                }

                if (schet==kvadr-2) {
                    line++;
                    schet=-1;
                    if (ugol==0){
                        ugol=3;
                    }else ugol--;
                }
            }else if(line==3){
                if (ugol==0){
                gby+=40;
                }else if(ugol==1){
                gbx=gbx-40;
                }else if(ugol==2){
                   gby=gby-40;
                }else if(ugol==3){
                    gbx+=40;
                }

                if (schet==kvadr-3) {
                    line=0;
                    schet=-1;
                    if (ugol==0){
                        ugol=3;
                    }else ugol--;
                    kvadr=kvadr-2;
                }
            }


        }else {
            if (line==0){

if (ugol==0){
gbx+=40;
}else if(ugol==1){
gby+=40;
}else if(ugol==2){
   gbx=gbx-40;
}else if(ugol==3){
    gby=gby-40;
}
                if (schet==kvadr-1) {
                    line++;
                    schet=-1;
                    if (ugol==3){
                        ugol=0;
                    }else ugol++;
                }

            }else if(line==1){
                if (ugol==0){
                gbx+=40;
                }else if(ugol==1){
                gby+=40;
                }else if(ugol==2){
                   gbx=gbx-40;
                }else if(ugol==3){
                    gby=gby-40;
                }

                if (schet==kvadr-2) {
                    line++;
                    schet=-1;
                    if (ugol==3){
                        ugol=0;
                    }else ugol++;
                }
            }
            else if(line==2){
                if (ugol==0){
                gbx+=40;
                }else if(ugol==1){
                gby+=40;
                }else if(ugol==2){
                   gbx=gbx-40;
                }else if(ugol==3){
                    gby=gby-40;
                }

                if (schet==kvadr-2) {
                    line++;
                    schet=-1;
                    if (ugol==3){
                        ugol=0;
                    }else ugol++;
                }
            }else if(line==3){
                if (ugol==0){
                gbx+=40;
                }else if(ugol==1){
                gby+=40;
                }else if(ugol==2){
                   gbx=gbx-40;
                }else if(ugol==3){
                    gby=gby-40;
                }

                if (schet==kvadr-3) {
                    line=0;
                    schet=-1;
                    if (ugol==3){
                        ugol=0;
                    }else ugol++;
                    kvadr=kvadr-2;
                }
            }

}

}
}
}
