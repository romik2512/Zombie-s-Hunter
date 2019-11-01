#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Menu.h"

class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player(bool napro,QGraphicsItem* parent=nullptr);
    ~Player();   
void keyPressEvent(QKeyEvent * event);
bool napr;
};

#endif // PLAYER_H
