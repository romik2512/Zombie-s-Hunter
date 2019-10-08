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
    int gbx;
    int gby;
    int ugol;
    bool blocksnapr;
    int kolvo;
public slots:
    void increase();
    void addblocks();
};

#endif // GAMETIME_H
