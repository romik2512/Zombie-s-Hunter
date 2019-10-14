#ifndef EASYLVL_H
#define EASYLVL_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Easy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Easy(QGraphicsItem*parent=nullptr,bool active=false);
};


#endif // EASYLVL_H
