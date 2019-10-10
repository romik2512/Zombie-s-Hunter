#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView{
public:
    bool blocksarray[15][15]={
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
    };
    Game(QWidget*parent=nullptr);
    QGraphicsScene*scene;
int enemies;
};



#endif // GAME_H
