#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include "Zombie.h"

class Game:public QGraphicsView{
Q_OBJECT
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

    Game(char sl='m',QWidget*parent=nullptr);
    ~Game();
    QGraphicsScene*scene;
    QList<QGraphicsPixmapItem*> gknopki;
    char gamelevel;
    int enemies;
    int bomb;
    int boom;
    QList <Zombie*> zombs;
public slots:
    void GameFAQ();
    void BackToGame();
    void GBackToMenu();
signals:
    void StopZombie();
    void StartZombie();
};
#endif // GAME_H
