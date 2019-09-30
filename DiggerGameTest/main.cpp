#include <QApplication>
#include "Game.h"
#include "QTime"
#include "Zapas.h"
#include "Kolvo.h"
#include "Gametime.h"

Game *game;

Zapas * zapas;

Kolvo * kolvo;

GTime * gametime;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    game=new Game();
    game->show();

    gametime=new GTime();
    gametime->setPos(770,85);
    game->scene->addItem(gametime);

    zapas=new Zapas();
    zapas->setPos(785,372);
    game->scene->addItem(zapas);

    kolvo=new Kolvo();
    kolvo->setPos(785,222);
    game->scene->addItem(kolvo);




    return a.exec();
}
