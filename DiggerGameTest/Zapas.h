#ifndef ZAPAS_H
#define ZAPAS_H

#include <QGraphicsTextItem>
class Zapas: public QGraphicsTextItem{
public:
    Zapas(QGraphicsItem*parent=nullptr);
    void decrease();
    void increase();
};

#endif // ZAPAS_H
