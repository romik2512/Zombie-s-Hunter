#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "Buttons.h"
#include "Menu.h"
#include "Kolvo.h"
#include "Gametime.h"
#include "Game.h"
#include "Zapas.h"

extern Menu* menu;
Game *game;
Zapas * zapas;
Kolvo * kolvo;
GTime * gametime;

Buttons::Buttons(char button,QGraphicsItem*parent){
if (button=='w'){
    buttontype='r';
setPixmap(QPixmap(":/images/restartwingame.png"));
}
else if(button=='t'){
setPixmap(QPixmap(":/images/wintomenu.png"));
buttontype='t';
}
else if(button=='o'){
setPixmap(QPixmap(":/images/losetomenu.png"));
buttontype='t';
}
else if(button=='l'){
setPixmap(QPixmap(":/images/restartlosegame.png"));
buttontype='r';
}
else if(button=='s'){
setPixmap(QPixmap(":/images/selectsettings.png"));
buttontype='s';
}
else if(button=='n'){
setPixmap(QPixmap(":/images/newgame.png"));
buttontype='n';
}
else if(button=='e'){
setPixmap(QPixmap(":/images/easyselect.png"));
buttontype='e';
}
else if(button=='h'){
setPixmap(QPixmap(":/images/hardselect.png"));
buttontype='h';
}
else if(button=='m'){
setPixmap(QPixmap(":/images/mediumselect.png"));
buttontype='m';
}
else if(button=='2'){
setPixmap(QPixmap(":/images/activemediumselect.png"));
buttontype='2';
}
else if(button=='1'){
setPixmap(QPixmap(":/images/activeeasyselect.png"));
buttontype='1';
}
else if(button=='3'){
setPixmap(QPixmap(":/images/activehardselect.png"));
buttontype='3';
}

}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *eventer){
    if(buttontype=='r'){
       game=new Game();
       gametime=new GTime();
       gametime->setPos(770,85);
       game->scene->addItem(gametime);

       zapas=new Zapas();
       zapas->setPos(785,372);
       game->scene->addItem(zapas);

       kolvo=new Kolvo();
       if(game->enemies<10){
       kolvo->setPos(785,222);}
       else{kolvo->setPos(777,222);}
       game->scene->addItem(kolvo);
       game->show();
       delete this;
       delete menu;
}
    else if(buttontype=='t'){
        delete menu;
        menu=new Menu('m');
        menu->show();
    }
    else if(buttontype=='n'){
        game=new Game(menu->lvl);
        gametime=new GTime();
        gametime->setPos(770,85);
        game->scene->addItem(gametime);

        zapas=new Zapas();
        zapas->setPos(785,372);
        game->scene->addItem(zapas);

        kolvo=new Kolvo();
        if(game->enemies<10){
        kolvo->setPos(785,222);}
        else{kolvo->setPos(777,222);}
        game->scene->addItem(kolvo);
        game->show();
        delete this;
        delete menu;
    }
    else if(buttontype=='e'){
        if ((menu->lvl)!='e'){
            qDebug()<<typeid(*(menu->knopki[1])).name();
            delete menu->knopki[1];

            Buttons* easy=new Buttons('1');
            easy->setPos(265,350);
            menu->mscene->addItem(easy);
            menu->knopki[1]=easy;
            menu->lvl='e';
            delete menu->knopki[2];
            delete menu->knopki[3];

            Buttons* medium=new Buttons('m');
            medium->setPos(398,350);
            menu->mscene->addItem(medium);
            menu->knopki[2]=medium;

            Buttons* hard=new Buttons('h');
            hard->setPos(532,350);
            menu->mscene->addItem(hard);
            menu->knopki[3]=hard;

        }
    }
    else if(buttontype=='m'){
        if (menu->lvl!='m'){
                    delete menu->knopki[2];
                    Buttons* medium=new Buttons('2');
                    medium->setPos(398,350);
                    menu-> mscene->addItem(medium);
                    menu->knopki[2]=medium;
                    menu->lvl='m';
                    delete menu->knopki[1];
                    delete menu->knopki[3];

                    Buttons* easy=new Buttons('e');
                    easy->setPos(265,350);
                    menu->mscene->addItem(easy);
                    menu->knopki[1]=easy;

                    Buttons* hard=new Buttons('h');
                    hard->setPos(532,350);
                    menu->mscene->addItem(hard);
                    menu->knopki[3]=hard;
                }
    }
    else if(buttontype=='h'){
        if (menu->lvl!='h'){
                    delete menu->knopki[3];
                    Buttons* hard=new Buttons('3');
                    hard->setPos(532,350);
                    menu->mscene->addItem(hard);
                    menu->knopki[3]=hard;
                    menu->lvl='h';
                    delete menu->knopki[1];
                    delete menu->knopki[2];

                    Buttons* easy=new Buttons('e');
                    easy->setPos(265,350);
                    menu->mscene->addItem(easy);
                    menu->knopki[1]=easy;

                    Buttons* medium=new Buttons('m');
                    medium->setPos(398,350);
                    menu->mscene->addItem(medium);
                    menu->knopki[2]=medium;
                }
    }
}
