#ifndef GAMETIME_H
#define GAMETIME_H

#include <QGraphicsTextItem>
#include <QObject>


class GTime: public QGraphicsTextItem{
    Q_OBJECT
 public:
    GTime(QGraphicsItem*parent=nullptr);
private:
    int gtime;
public slots:
    void increase();
};

#endif // GAMETIME_H
