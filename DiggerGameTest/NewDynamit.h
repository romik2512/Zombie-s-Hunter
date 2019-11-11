#ifndef NEWDYNAMIT_H
#define NEWDYNAMIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
class NewDynamit: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        NewDynamit(QGraphicsItem*parent=nullptr);

};

#endif // NEWDYNAMIT_H
