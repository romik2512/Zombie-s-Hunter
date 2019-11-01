#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Menu:public QGraphicsView{
Q_OBJECT
public:
    Menu(char scenevalue='m',char scenelevel='m',QWidget*parent=nullptr);
    QGraphicsScene*mscene;
    char lvl;
    QList<QGraphicsItem*> knopki;
};


#endif // MENU_H
