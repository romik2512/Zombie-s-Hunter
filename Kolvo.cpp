#include "Kolvo.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>
#include "Menu.h"
#include "Player.h" //??

extern Game *game;
extern Menu * menu;
extern Player *player;

Kolvo::Kolvo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString::number(game->enemies));
    setDefaultTextColor(QColor(242,160,7));
    setFont(QFont("times",34));

}

void Kolvo::decrease()
{
    game->enemies--;
    setPlainText(QString::number(game->enemies));
    if (game->enemies==0){
        scene()->removeItem(player);
        delete player;
        menu=new Menu('w');
        game->~Game();
    }
    //setPlainText(QString::number(game->enemies));
}
