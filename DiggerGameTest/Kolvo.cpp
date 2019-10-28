#include "Kolvo.h"
#include <QFont>
#include <QTimer>
#include "Game.h"
#include <QDebug>
#include "Menu.h"

extern Game *game;
extern Menu * menu;

Kolvo::Kolvo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString::number(game->enemies));
    setDefaultTextColor(QColor(242,160,7));
    setFont(QFont("times",34));

}

void Kolvo::decrease()
{
    game->enemies--;
    if (game->enemies==0){
        menu=new Menu('w');
        delete game;
    }
    setPlainText(QString::number(game->enemies));
}
