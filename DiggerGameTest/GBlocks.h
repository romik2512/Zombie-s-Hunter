#ifndef GBLOCKS_H
#define GBLOCKS_H

#include <QGraphicsPixmapItem>
#include <QObject>
class GBlocks: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        GBlocks(QGraphicsItem*parent=nullptr);
        void create();
};

#endif // GBLOCKS_H
