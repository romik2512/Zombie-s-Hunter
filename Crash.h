#ifndef CRASH_H
#define CRASH_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Crash: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Crash(QGraphicsItem*parent=nullptr);
public slots:
    void deletecrash();
};

#endif // CRASH_H
