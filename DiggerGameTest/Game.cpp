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

Game::Game(char sl,QWidget*parent){
scene=new QGraphicsScene();
scene->setSceneRect(0,0,900,700);

setBackgroundBrush(QBrush(QImage(":/images/bgcolorfordigger2.png")));
setScene(scene);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(900,700);
boom=0;

if(sl=='e'){
    enemies=6;
    bomb=5;
}else if(sl=='m'){
enemies=10;
bomb=7;
}else {
    enemies=12;
    bomb=8;
}
int gschetchik=0;
int eschetchik=0;

for (int i=0;i<15;i++){
    for(int j=0;j<15;j++){
        if (blocksarray[i][j]==true) {
        GBlocks* gblocks=new GBlocks();
        gblocks->setPos(i*40+50,j*40+50);
        scene->addItem(gblocks);
        gblist<<gblocks;
        //gblist[gschetchik]=gblocks;
        gblocks->nomergblocka=gschetchik;
        gschetchik++;
        } else {            
            EBlocks* eblocks=new EBlocks();
            eblocks->setPos(i*40+50,j*40+50);
            scene->addItem(eblocks);
            qDebug() <<"LOL";
            eblist<<eblocks;
           // eblist[eschetchik]=eblocks;
            eblocks->nomereblocka=eschetchik;
            eschetchik++;
        }
    }
}

qDebug() << "EBLOCS AND GBLOCKS WAS CREATED!!!";

int random_posx=qrand() %15;
int random_posy;
do{
    random_posy=qrand() % 15;

}while (blocksarray[random_posx][random_posy]==true);

qDebug() << "WHILE1 ZAVERSHEN!!!";

Player * player=new Player(true);
player->setPos(random_posx*40+50,random_posy*40+50);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
scene->addItem(player);
player->napr=true;

for (int i=0;i<enemies;i++){
    int zrandom_posy;
    int zrandom_posx;

    qDebug() <<"SUDA MOZNBO DOBAVIT OBJECT KARTINKI ZAGRUZKI KOTORIY UNIZTOZHITSA POSLE ETOGO WHILE!";


    do{
zrandom_posx=qrand() % 15;
zrandom_posy=qrand() % 15;
}while ((blocksarray[zrandom_posx][zrandom_posy] ==true)||((!((zrandom_posy < random_posy-3)||(zrandom_posy>random_posy+3)))&&(!((zrandom_posx < random_posx-3)||(zrandom_posx>random_posx+3)))));
qDebug() << "SDES UNOZTHOZHAYETSA KARTINKA I IGRA PRORISOVIVAETSYA!!";


Zombie * zombie=new Zombie(true,false);
zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+50);
scene->addItem(zombie);
zombielist<<zombie;
//zombielist[i]=zombie;
zombie->nomerzombie=i;
zombie->znapr=true;
zombie->fire=false;
//zombie->lavakol=0;
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


if ((zmove-1)==0) {
          int index=zombie->nomerzombie;
          //delete zombie;
          delete zombielist[index];
          Zombie * zombie=new Zombie(false,false);
          zombie->setPos(zrandom_posx*40+48,zrandom_posy*40+50);
          scene->addItem(zombie);
          zombielist[index]=zombie;
          zombie->nomerzombie=index;
          zombie->znapr=false;
          zombie->fire=false;
          zombie->zadnapr=2;
        }
        else if((zmove-1)==1){
              bool nnapr=zombie->znapr;
             int index=zombie->nomerzombie;
             //delete zombie;
             delete zombielist[index];
             Zombie * zombie=new Zombie(nnapr,false);
             zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+48);
             scene->addItem(zombie);
             zombielist[index]=zombie;
             zombie->nomerzombie=index;
             zombie->znapr=nnapr;
             zombie->zadnapr=3;
             zombie->fire=false;
        }else if((zmove-1)==2){             
             int index=zombie->nomerzombie;
             //delete zombie;
             delete zombielist[index];
             Zombie * zombie=new Zombie(true,false);
             zombie->setPos(zrandom_posx*40+52,zrandom_posy*40+50);
             scene->addItem(zombie);
             zombielist[index]=zombie;
             zombie->nomerzombie=index;
             zombie->znapr=true;
             zombie->fire=false;
             zombie->zadnapr=0;
        }else if((zmove-1)==3){
             bool nnapr=zombie->znapr;
             int index=zombie->nomerzombie;
             //delete zombie;
             delete zombielist[index];
             Zombie * zombie=new Zombie(nnapr,false);
             zombie->setPos(zrandom_posx*40+50,zrandom_posy*40+52);
             scene->addItem(zombie);
             zombielist[index]=zombie;
             zombie->nomerzombie=index;
             zombie->znapr=nnapr;
             zombie->zadnapr=1;
             zombie->fire=false;
        }
}

//show();
}

Game::~Game(){
//    for(int i =0,n=eblist.size();i<n;++i){
//        if(eblist[i]){
//        qDebug()<<"UDALENIYE: "<<eblist[i];
//    delete eblist[i];
//        } else continue;
//    }

//    for(int i =0,n=gblist.size();i<n;++i){
//        qDebug()<<"UDALENIYE: "<<gblist[i];
//    delete gblist[i];
//    }

    //вместо листсайз сделай лучше enemy ))
//    for(int i =0,n=zombielist.size();i<n;++i){
//        qDebug()<<"nomer zombie: "<<zombielist[i]->nomerzombie;
//    //delete zombielist[i];
//    }
//    //delete zombielist[2];
//        for(int ll=2;ll<5;ll++){
//            //zombielist[ll+1]->nomerzombie=zombielist[ll]->nomerzombie;
//            zombielist[ll]=zombielist[ll+1];
//            zombielist[ll]->nomerzombie--;
//        }
//         zombielist[5]=nullptr;
//         delete zombielist[5];

//QList<Zombie*> lolche;
//lolche<<zombielist[1];
//qDebug() <<"ZOMBIE NOMER: "<<zombielist[1]->nomerzombie;
//qDebug() <<"ZOMBIE NOMER: "<<lolche[0]->nomerzombie;
//lolche[0]=nullptr;
//qDebug() <<"ZOMBIE NOMER: "<<lolche[0]->nomerzombie;

//zombielist[2]=nullptr;
//    for(int i =0,n=enemies;i<n;++i){
//        if (zombielist[i]==nullptr){
//        qDebug() <<"UVIDEL NULLPTR V SPISKE!!!";
//        //qDebug() <<"ZOMBIE NOMER: "<<zombielist[i]->nomerzombie;
//        delete zombielist[i];
//        }
//        else {
//            qDebug() <<"ZOMBIE NOMER: "<<zombielist[i]->nomerzombie;
//        }
//        //qDebug()<<"UDALENIYE: "<<zombielist[i]->nomerzombie;
//    //delete zombielist[i];
//         //qDebug()<<"UDALENIYE: "<<zombielist[i] <<"  ETO ZOMBIE #"<<i;
//    }
   // qDebug()<<"NOMER OSTAVSHEGOSYA: "<<zombielist[enemies]->nomerzombie;
   // qDebug()<<zombielist[0]->nomerzombie;

//    for (int i=0,n=zombielist.size();i<n;++i){
//        if (zombielist[i]==nullptr){
//        qDebug()<<"NULLPTR NA INDEXE: "<<i;
//        }
//    delete zombielist[i];
//    }

    QList <QGraphicsItem*> vseob=scene->items();
    for(int z=0,k=vseob.size();z<k;z++){
        qDebug()<<"UDALYAYETSYA: "<<typeid(*(vseob[z])).name()<<"  EGO NOMER NA SCENE: #"<<z;
        delete vseob[z];
    }

}

