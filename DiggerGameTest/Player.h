#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Menu.h"

class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player(bool napro,bool massnapr[5],QGraphicsItem* parent=nullptr);
    ~Player();   
void keyPressEvent(QKeyEvent * event);
void keyReleaseEvent(QKeyEvent *revent);
bool napr;
bool playermoves[5];//={false,false,false,false,false};
public slots:
       void pmove();
};

#endif // PLAYER_H
