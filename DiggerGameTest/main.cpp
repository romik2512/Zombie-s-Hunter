#include <QApplication>
#include "Game.h"
#include "QTime"
#include "Zapas.h"
#include "Kolvo.h"
#include "Gametime.h"
#include "Menu.h"

//Game *game;

//Zapas * zapas;

//Kolvo * kolvo;

//GTime * gametime;

Menu * menu;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

     menu=new Menu();
     menu->show();

    return a.exec();
}
