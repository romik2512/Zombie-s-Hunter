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
    Menu(char scenevalue='m',QWidget*parent=nullptr);
    QGraphicsScene*mscene;
    char lvl='m';
    QList<QGraphicsItem*> knopki;
};


#endif // MENU_H
