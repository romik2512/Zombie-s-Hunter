#ifndef MEDIUMLVL_H
#define MEDIUMLVL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Medium: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Medium(QGraphicsItem*parent=nullptr,bool active=false);
};


#endif // MEDIUMLVL_H
