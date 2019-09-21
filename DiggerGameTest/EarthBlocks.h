#ifndef EARTHBLOCKS_H
#define EARTHBLOCKS_H

#include <QGraphicsPixmapItem>
#include <QObject>
class EBlocks: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        EBlocks(QGraphicsItem*parent=nullptr);
        void create();
};

#endif // EARTHBLOCKS_H
