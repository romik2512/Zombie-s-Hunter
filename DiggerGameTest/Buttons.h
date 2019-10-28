#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Buttons: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        char buttontype;
        Buttons(char button='r',QGraphicsItem*parent=nullptr);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent * eventer);
};


#endif // BUTTONS_H
