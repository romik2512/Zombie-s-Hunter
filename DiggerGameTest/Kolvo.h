#ifndef KOLVO_H
#define KOLVO_H

#include <QGraphicsTextItem>
class Kolvo: public QGraphicsTextItem{
public:
    Kolvo(QGraphicsItem*parent=nullptr);
    void decrease();
};


#endif // KOLVO_H
