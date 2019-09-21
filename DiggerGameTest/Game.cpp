#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "GBlocks.h"
#include "EarthBlocks.h"
#include "Zombie.h"
#include "Player.h"

//extern bool blocksarray;

Game::Game(QWidget*parent){
scene=new QGraphicsScene();
scene->setSceneRect(0,0,900,700);
setScene(scene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//setFixedSize(900,700);

for (int i=0;i<15;i++){
    for(int j=0;j<15;j++){
        if (blocksarray[i][j]==true) {
        GBlocks* gblocks=new GBlocks();
        gblocks->setPos(i*40+50,j*40+50);
        //gblocks->setFlag(QGraphicsItem::ItemIsFocusable);
       // gblocks->setFocus();
        scene->addItem(gblocks);
        } else {
            EBlocks* eblocks=new EBlocks();
            eblocks->setPos(i*40+50,j*40+50);
            //gblocks->setFlag(QGraphicsItem::ItemIsFocusable);
           // gblocks->setFocus();
            scene->addItem(eblocks);
        }
    }
}

Zombie * zombie=new Zombie();
Player * player=new Player();
player->setPos(50,50);
zombie->setPos(240,50);
scene->addItem(zombie);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();

scene->addItem(player);

show();
}
