#ifndef LOSEGAME_H
#define LOSEGAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class LoseGame:public QGraphicsView{
Q_OBJECT
public:
    LoseGame(QWidget*parent=nullptr);
    QGraphicsScene*losescene;
    //char lvl='m';
    //QList<QGraphicsItem*> knopki;
public slots:
    void mousePressEvent(QMouseEvent * event);
};

#endif // LOSEGAME_H
