#ifndef SECRETBOX_H
#define SECRETBOX_H

#include <QGraphicsPixmapItem>
#include <QObject>
class SecretBox: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        SecretBox(QGraphicsItem*parent=nullptr);

};


#endif // SECRETBOX_H
