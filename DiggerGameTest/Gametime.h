#ifndef GAMETIME_H
#define GAMETIME_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QTimer>

class GTime:public QGraphicsTextItem{
Q_OBJECT
public:
    GTime(QGraphicsItem*parent=nullptr);
    QTimer *blocksincrease;
    ~GTime();
private:
    int gtime;
    int gbx;
    int gby;
    int ugol;
    bool blocksnapr;
    int kvadr;
    int line;
    int schet;
public slots:
    void increase();
    void addblocks();
};

#endif // GAMETIME_H
