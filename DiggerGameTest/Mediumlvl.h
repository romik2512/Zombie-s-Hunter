#ifndef MEDIUMLVL_H
#define MEDIUMLVL_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Medium: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Medium(QGraphicsItem*parent=nullptr,bool active=false);
};


#endif // MEDIUMLVL_H
