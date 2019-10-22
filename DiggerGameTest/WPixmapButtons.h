#ifndef WPIXMAPBUTTONS_H
#define WPIXMAPBUTTONS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "WinGame.h"
class Buttons: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        char buttontype;
        Buttons(char button='r',QGraphicsItem*parent=nullptr);
        //friend void WinGame::backtomenu(char sign);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent * eventer);
};


#endif // WPIXMAPBUTTONS_H
