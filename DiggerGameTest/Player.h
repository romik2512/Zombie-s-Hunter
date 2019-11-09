#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Menu.h"
#include <QTimer>

class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player(bool napro,bool massnapr[5],QGraphicsItem* parent=nullptr);
    ~Player();   
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *revent);
    bool napr;
    int ironmode=1;
    int playermovevalue;
    bool playermoves[5];
    bool usetimer;
    QTimer *firetimer;
public slots:
    void pmove();
    void checkfire();
};

#endif // PLAYER_H
