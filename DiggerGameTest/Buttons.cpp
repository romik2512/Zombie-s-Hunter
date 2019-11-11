#include <QGraphicsSceneMouseEvent>
#include "Buttons.h"
#include "Menu.h"
#include "Kolvo.h"
#include "Gametime.h"
#include "Game.h"
#include "Zapas.h"
#include "SecretBox.h"

extern Menu* menu;
Game *game;
Zapas * zapas;
Kolvo * kolvo;
GTime * gametime;

Buttons::Buttons(ButtonAction buttonaction,QGraphicsItem*parent){
    if (buttonaction==RestartWinGame){
        buttonused=RestartWinGame;
        setPixmap(QPixmap(":/images/restartwingame.png"));
    }
    else if (buttonaction==FromWinToMenu){
        setPixmap(QPixmap(":/images/wintomenu.png"));
        buttonused=FromWinToMenu;
    }
    else if (buttonaction==FromLoseToMenu){
        setPixmap(QPixmap(":/images/losetomenu.png"));
        buttonused=FromWinToMenu;
    }
    else if (buttonaction==RestartLoseGame){
        setPixmap(QPixmap(":/images/restartlosegame.png"));
        buttonused=RestartWinGame;
    }
    else if (buttonaction==Settings){
        setPixmap(QPixmap(":/images/selectsettings.png"));
        buttonused=Settings;
    }
    else if (buttonaction==NewGame){
        setPixmap(QPixmap(":/images/newgame.png"));
        buttonused=NewGame;
    }
    else if (buttonaction==EasyLevel){
        setPixmap(QPixmap(":/images/easyselect.png"));
        buttonused=EasyLevel;
    }
    else if (buttonaction==HardLevel){
        setPixmap(QPixmap(":/images/hardselect.png"));
        buttonused=HardLevel;
    }
    else if (buttonaction==MediumLevel){
        setPixmap(QPixmap(":/images/mediumselect.png"));
        buttonused=MediumLevel;
    }
    else if (buttonaction==ActiveMediumLevel){
        setPixmap(QPixmap(":/images/activemediumselect.png"));
        buttonused=ActiveMediumLevel;
    }
    else if (buttonaction==ActiveEasyLevel){
        setPixmap(QPixmap(":/images/activeeasyselect.png"));
        buttonused=ActiveEasyLevel;
    }
    else if (buttonaction==ActiveHardLevel){
        setPixmap(QPixmap(":/images/activehardselect.png"));
        buttonused=ActiveHardLevel;
    }
}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *eventer) {
    if(buttonused==RestartWinGame){
        game=new Game(menu->lvl);
        gametime=new GTime();
        gametime->setPos(770,85);
        game->scene->addItem(gametime);

        zapas=new Zapas();
        zapas->setPos(785,372);
        game->scene->addItem(zapas);

        kolvo=new Kolvo();
        if(game->enemies<10) {
            kolvo->setPos(785,222);
        }
        else {
            kolvo->setPos(777,222);
        }
        game->scene->addItem(kolvo);
        game->show();
        delete this;
        delete menu;
    }
    else if(buttonused==FromWinToMenu){
        delete menu;
        menu=new Menu('m');
        menu->show();
    }
    else if(buttonused==NewGame){
        game=new Game(menu->lvl);
        gametime=new GTime();
        gametime->setPos(770,85);
        game->scene->addItem(gametime);

        zapas=new Zapas();
        zapas->setPos(785,372);
        game->scene->addItem(zapas);

        kolvo=new Kolvo();
        if(game->enemies<10) {
            kolvo->setPos(785,222);
        }
        else {
            kolvo->setPos(777,222);
        }
        game->scene->addItem(kolvo);
        game->show();
        delete this;
        delete menu;
    }
    else if(buttonused==EasyLevel){
        if ((menu->lvl)!='e') {
            menu->knopki[1]->setPixmap(QPixmap(":/images/activeeasyselect.png"));
            menu->lvl='e';
            menu->knopki[2]->setPixmap(QPixmap(":/images/mediumselect.png"));
            menu->knopki[3]->setPixmap(QPixmap(":/images/hardselect.png"));
        }
    }
    else if(buttonused==ActiveMediumLevel){  //Именно с Active,поскольку изначально при создании сцены используется именно ActiveMediumLevel..
        if (menu->lvl!='m') {
              menu->lvl='m';
              menu->knopki[1]->setPixmap(QPixmap(":/images/easyselect.png"));
              menu->knopki[2]->setPixmap(QPixmap(":/images/activemediumselect.png"));
              menu->knopki[3]->setPixmap(QPixmap(":/images/hardselect.png"));
        }
    }
    else if(buttonused==HardLevel){
        if (menu->lvl!='h') {
              menu->lvl='h';
              menu->knopki[1]->setPixmap(QPixmap(":/images/easyselect.png"));
              menu->knopki[2]->setPixmap(QPixmap(":/images/mediumselect.png"));
              menu->knopki[3]->setPixmap(QPixmap(":/images/activehardselect.png"));
        }
    }
}


