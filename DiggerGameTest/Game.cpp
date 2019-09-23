#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "GBlocks.h"
#include "EarthBlocks.h"
#include "Zombie.h"
#include "Player.h"


Game::Game(QWidget*parent){
scene=new QGraphicsScene();
scene->setSceneRect(0,0,900,700);
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

Player * player=new Player();
player->setPos(random_posx*40+50,random_posy*40+50);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
scene->addItem(player);

for (int i=0;i<6;i++){
    int zrandom_posy;
    int zrandom_posx;
    do{
zrandom_posx=qrand() % 15;
zrandom_posy=qrand() % 15;
}while ((blocksarray[zrandom_posx][zrandom_posy] ==true)||((!(zrandom_posy < random_posy-3)||(zrandom_posy>random_posy+3))&&(!(zrandom_posx < random_posx-3)||(zrandom_posx>random_posx+3))));


Zombie * zombie=new Zombie();
zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+50);
scene->addItem(zombie);
}

show();
}
