#ifndef LOADGAME_H
#define LOADGAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Load:public QGraphicsView{
    Q_OBJECT
public:
        Load(QGraphicsItem*parent=nullptr);
        QGraphicsScene*loadscene;
};

#endif // LOADGAME_H
