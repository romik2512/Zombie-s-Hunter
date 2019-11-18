#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <Buttons.h>

class Menu:public QGraphicsView{
Q_OBJECT
public:
    Menu(char scenevalue='m',char scenelevel='m',QWidget*parent=nullptr);
    QGraphicsScene*mscene;
    char lvl;
    QList<QGraphicsPixmapItem*>knopki;
public slots:
    void MainNewGame();
    void FAQclicked();
    void BackToMenu();
    void SetEasyLevel();
    void SetMediumLevel();
    void SetHardLevel();
};


#endif // MENU_H
