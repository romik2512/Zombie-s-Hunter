#include "Game.h"
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

Game::Game(QWidget*parent){
scene=new QGraphicsScene();
scene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/bgcolorfordigger2.png")));
setScene(scene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

for (int i=0;i<15;i++){
    for(int j=0;j<15;j++){
        if (blocksarray[i][j]==true) {
        GBlocks* gblocks=new GBlocks();
        gblocks->setPos(i*40+50,j*40+50);
        scene->addItem(gblocks);
        } else {
            EBlocks* eblocks=new EBlocks();
            eblocks->setPos(i*40+50,j*40+50);
            scene->addItem(eblocks);
        }
    }
}


int random_posx=qrand() %15;
int random_posy;
do{
    random_posy=qrand() % 15;

}while (blocksarray[random_posx][random_posy] ==true);

Player * player=new Player(true);
player->setPos(random_posx*40+50,random_posy*40+50);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
scene->addItem(player);
player->napr=true;

for (int i=0;i<6;i++){
    int zrandom_posy;
    int zrandom_posx;
    do{
zrandom_posx=qrand() % 15;
zrandom_posy=qrand() % 15;
}while ((blocksarray[zrandom_posx][zrandom_posy] ==true)||((!(zrandom_posy < random_posy-3)||(zrandom_posy>random_posy+3))&&(!(zrandom_posx < random_posx-3)||(zrandom_posx>random_posx+3))));


Zombie * zombie=new Zombie(true,false);
zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+50);
scene->addItem(zombie);
zombie->znapr=true;
zombie->fire=false;

        if((zrandom_posx*40+50)>89) {

            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+10),zrandom_posy*40+50,QTransform()))))))  {
                    zombie->path[0]=true;
                   zombie-> schetchik++;

                }
            } else zombie->path[0]=false;

        if((zrandom_posy*40+50)>89) {

            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+50),zrandom_posy*40+10,QTransform())))))) {
                 zombie->  path[1]=true;
                  zombie-> schetchik++;

               }
            }else zombie->path[1]=false;


        if((zrandom_posx*40+50)<571){
            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+90),(zrandom_posy*40+50),QTransform())))))) {
                zombie->  path[2]=true;
                zombie->  schetchik++;
              }
            }else zombie->path[2]=false;

        if((zrandom_posy*40+50)<571){
            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+50),(zrandom_posy*40+90),QTransform())))))) {

               zombie->path[3]=true;
               zombie->schetchik++;
             }
            }else zombie->path[3]=false;

        qDebug() <<"SCHETCHIK: "<<zombie->schetchik;

int randomys=qrand()%zombie->schetchik;
int lol=0;
int zmove=0;
while (lol<randomys+1){
if (zombie->path[zmove]==true){
    lol++;
}
zmove++;
}

if ((zmove-1)>1) {
zombie->zadnapr=zmove-3;
} else {
zombie->zadnapr=zmove+1;
}


qDebug() <<"napravleniye zombie: "<<zmove-1<<"zadneenapravleniye: "<<zombie->zadnapr;

if ((zmove-1)==0) {
         // zombie->setPos(zrandom_posx*40+48,zrandom_posy*40+50);
          delete zombie;
          Zombie * zombie=new Zombie(false,false);
          zombie->setPos(zrandom_posx*40+48,zrandom_posy*40+50);
          scene->addItem(zombie);
          zombie->znapr=false;
          zombie->fire=false;
         // qDebug() << "POSX: "<<zrandom_posx*40+48<<" POSY: "<<zrandom_posy*40+50;
        }
        else if((zmove-1)==1){
             zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+48);
            // qDebug() << "POSX: "<<zrandom_posx*40+50<<" POSY: "<<zrandom_posy*40+48;
        }else if((zmove-1)==2){
             zombie->setPos(zrandom_posx*40+52,zrandom_posy*40+50);
            // qDebug() << "POSX: "<<zrandom_posx*40+52<<" POSY: "<<zrandom_posy*40+50;
        }else if((zmove-1)==3){
             zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+52);
            // qDebug() << "POSX: "<<zrandom_posx*40+50<<" POSY: "<<zrandom_posy*40+52;
        }

       /* for (int i=0;i<=zombie->schetchik;i++){

        }*/

}

show();
}
