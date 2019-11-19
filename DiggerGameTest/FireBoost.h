#ifndef FIREBOOST_H
#define FIREBOOST_H

#include <QGraphicsPixmapItem>
#include <QObject>
class FireBoost: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        FireBoost(QGraphicsItem*parent=nullptr);
};

#endif // FIREBOOST_H
