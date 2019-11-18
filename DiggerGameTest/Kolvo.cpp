#include "Kolvo.h"
#include "Game.h"
#include "Menu.h"
#include "Player.h"
#include "AfterWinScene.h"

extern Game *game;
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
        AfterWinScene*afterwinscene=new AfterWinScene(game->gamelevel);
        game->~Game();
    }
}
