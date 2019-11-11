#include "Game.h"
#include "GBlocks.h"
#include "EarthBlocks.h"
#include "Zombie.h"
#include "Player.h"
#include <QBrush>
#include "Gametime.h"
#include "Zapas.h"
#include "Kolvo.h"
#include "SecretBox.h"
#include "NewSpeed.h"
#include "NewDynamit.h"
#include "FireBoost.h"

extern Menu* menu;
extern Zapas * zapas;
extern GTime *gametime;
extern Kolvo *kolvo;
Player *player;

Game::Game(char sl,QWidget*parent) {
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,900,700);

    setBackgroundBrush(QBrush(QImage(":/images/bgcolorfordigger2.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,700);
    boom=0;
    gamelevel=sl;
    if(sl=='e') {
        enemies=6;
        bomb=5;
    } else if(sl=='m') {
        enemies=10;
        bomb=7;
    } else {
        enemies=12;
        bomb=8;
    }
    int gschetchik=0;
    int eschetchik=0;

    for (int i=0; i<15; i++) {
        for(int j=0; j<15; j++) {
            if (blocksarray[i][j]==true) {
                GBlocks* gblocks=new GBlocks();
                gblocks->setPos(i*40+50,j*40+50);
                scene->addItem(gblocks);
                gblocks->nomergblocka=gschetchik;
                gschetchik++;
            } else {
                EBlocks* eblocks=new EBlocks();
                eblocks->setPos(i*40+50,j*40+50);
                scene->addItem(eblocks);
                eblocks->nomereblocka=eschetchik;
                eschetchik++;
            }
        }
    }


    int random_posx=qrand() %15;
    int random_posy;
    do {
        random_posy=qrand() % 15;

    } while (blocksarray[random_posx][random_posy]==true);

    bool massforplayer[5]= {false,false,false,false,false};
    player=new Player(true,massforplayer);
    player->setPos(random_posx*40+50,random_posy*40+50);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->napr=true;
    blocksarray[random_posx][random_posy]=true;


    for(int i=0;i<5;i++){
        int secretbox_x;
        int secretbox_y;
        do {
            secretbox_x=qrand() %15;
            secretbox_y=qrand() %15;
        }while (blocksarray[secretbox_x][secretbox_y]==true);
        if (i==0){
            NewDynamit* newdynamit=new NewDynamit();
            newdynamit->setPos(secretbox_x*40+50,secretbox_y*40+50);
            scene->addItem(newdynamit);
        }else if(i==1){
            NewSpeed* newspeed=new NewSpeed();
            newspeed->setPos(secretbox_x*40+50,secretbox_y*40+50);
            scene->addItem(newspeed);
        }else if(i==3){
            FireBoost* fireboost=new FireBoost();
            fireboost->setPos(secretbox_x*40+50,secretbox_y*40+50);
            scene->addItem(fireboost);
        }
        SecretBox *secretbox=new SecretBox();
        secretbox->setPos(secretbox_x*40+50,secretbox_y*40+50);
        scene->addItem(secretbox);
        blocksarray[secretbox_x][secretbox_y]=true;
    }

    for (int i=0; i<enemies; i++) {
        int zrandom_posy;
        int zrandom_posx;
        do {
            zrandom_posx=qrand() % 15;
            zrandom_posy=qrand() % 15;
        } while ((blocksarray[zrandom_posx][zrandom_posy] ==true)||((!((zrandom_posy < random_posy-3)||(zrandom_posy>random_posy+3)))&&(!((zrandom_posx < random_posx-3)||(zrandom_posx>random_posx+3)))));

        Zombie * zombie=new Zombie(true,false);
        zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+50);
        scene->addItem(zombie);
        zombie->znapr=true;
        zombie->fire=false;

        blocksarray[zrandom_posx][zrandom_posy]=true;

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
        } else zombie->path[1]=false;


        if((zrandom_posx*40+50)<571) {
            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+90),(zrandom_posy*40+50),QTransform())))))) {
                zombie->  path[2]=true;
                zombie->  schetchik++;
            }
        } else zombie->path[2]=false;

        if((zrandom_posy*40+50)<571) {
            if (!((typeid(GBlocks))==(typeid(*(scene->itemAt((zrandom_posx*40+50),(zrandom_posy*40+90),QTransform())))))) {

                zombie->path[3]=true;
                zombie->schetchik++;
            }
        } else zombie->path[3]=false;

        int randomys=qrand()%zombie->schetchik;
        int lol=0;
        int zmove=0;
        while (lol<randomys+1) {
            if (zombie->path[zmove]==true) {
                lol++;
            }
            zmove++;
        }

        if ((zmove-1)>1) {
            zombie->zadnapr=zmove-3;
        } else {
            zombie->zadnapr=zmove+1;
        }


        if ((zmove-1)==0) {
            delete zombie;
            Zombie * zombie=new Zombie(false,false);
            zombie->setPos(zrandom_posx*40+48,zrandom_posy*40+50);
            scene->addItem(zombie);
            zombie->znapr=false;
            zombie->fire=false;
            zombie->zadnapr=2;
        }
        else if((zmove-1)==1) {
            bool nnapr=zombie->znapr;
            delete zombie;
            Zombie * zombie=new Zombie(nnapr,false);
            zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+48);
            scene->addItem(zombie);
            zombie->znapr=nnapr;
            zombie->zadnapr=3;
            zombie->fire=false;
        } else if((zmove-1)==2) {
            delete zombie;
            Zombie * zombie=new Zombie(true,false);
            zombie->setPos(zrandom_posx*40+52,zrandom_posy*40+50);
            scene->addItem(zombie);
            zombie->znapr=true;
            zombie->fire=false;
            zombie->zadnapr=0;
        } else if((zmove-1)==3) {
            bool nnapr=zombie->znapr;
            delete zombie;
            Zombie * zombie=new Zombie(nnapr,false);
            zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+52);
            scene->addItem(zombie);
            zombie->znapr=nnapr;
            zombie->zadnapr=1;
            zombie->fire=false;
        }
    }
}

Game::~Game() {
    delete gametime;
    delete zapas;
    delete kolvo;
    QList <QGraphicsItem*> vseob=scene->items();
    for(int z=0,k=vseob.size(); z<k; z++) {
        delete vseob[z];
    }

}

