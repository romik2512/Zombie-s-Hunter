#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player(QGraphicsItem* parent=nullptr);
void keyPressEvent(QKeyEvent * event);
//private:
int w,h;

};

#endif // PLAYER_H
