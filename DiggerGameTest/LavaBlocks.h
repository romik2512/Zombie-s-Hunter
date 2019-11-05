#ifndef LAVABLOCKS_H
#define LAVABLOCKS_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Lava: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Lava(QGraphicsItem*parent=nullptr);

};

#endif // LAVABLOCKS_H
