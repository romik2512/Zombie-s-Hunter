#include <QApplication>
#include "Game.h"
#include "QTime"

Game *game;

/*bool blocksarray[15][15]={
    {false,false,false,false,false,false,false,true,false,false,false,false,false,false,false},
    {false,true,true,true,false,true,false,true,false,true,false,true,true,true,false},
    {false,true,false,false,false,false,false,true,false,false,false,false,false,true,false},
    {false,true,false,true,true,true,false,false,false,true,true,true,false,true,false},
    {false,true,false,false,false,false,false,true,false,false,false,false,false,true,false},
    {false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
    {false,true,false,true,true,false,false,true,false,false,true,true,false,true,false},
    {false,false,false,false,false,false,true,true,true,false,false,false,false,false,false},
    {false,true,false,true,true,false,false,true,false,false,true,true,false,true,false},
    {false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
    {false,true,false,false,false,false,false,true,false,false,false,false,false,true,false},
    {false,true,false,true,true,true,false,false,false,true,true,true,false,true,false},
    {false,true,false,false,false,false,false,true,false,false,false,false,false,true,false},
    {false,true,true,true,false,true,false,true,false,true,false,true,true,true,false},
    {false,false,false,false,false,false,false,true,false,false,false,false,false,false,false},
};*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    game=new Game();
    game->show();

    return a.exec();
}
