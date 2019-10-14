#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Menu:public QGraphicsView{
//class Menu:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Menu(QWidget*parent=nullptr);    
    QGraphicsScene*mscene;
    char lvl='m';
public slots:
    void mousePressEvent(QMouseEvent * event);
};


#endif // MENU_H
