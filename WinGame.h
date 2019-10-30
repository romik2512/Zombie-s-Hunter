#ifndef WINGAME_H
#define WINGAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "WPixmapButtons.h"


class WinGame:public QGraphicsView{
Q_OBJECT
public:
    WinGame(QWidget*parent=nullptr);
    QGraphicsScene*winscene;
    void backtomenu(char sign);
public slots:
    void mousePressEvent(QMouseEvent * eventer);
};

#endif // WINGAME_H
