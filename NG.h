#ifndef NG_H
#define NG_H

#include <QGraphicsPixmapItem>
#include <QObject>
class NG: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        NG(QGraphicsItem*parent=nullptr);
};


#endif // NG_H
