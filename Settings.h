#ifndef SETTINGS_H
#define SETTINGS_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Settings: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Settings(QGraphicsItem*parent=nullptr);
};


#endif // SETTINGS_H
