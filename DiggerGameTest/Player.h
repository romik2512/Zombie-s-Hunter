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
    int ironmode=500;
    int playermovevalue;
    int boostspeed=0;
    bool playermoves[5];
    bool usetimer;
    bool useescape;
    int beonfiretime=0;
    int plavakol=0;
    QTimer *firetimer;
    QTimer *playerspeed;
public slots:
    void pmove();  
    void playeranimation();
signals:
    void UseEscape();
    void UseEscapeSecond();
};

#endif // PLAYER_H
