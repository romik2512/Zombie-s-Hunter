#ifndef AFTERWINSCENE_H
#define AFTERWINSCENE_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <Buttons.h>

class AfterWinScene:public QGraphicsView{
Q_OBJECT
public:
    AfterWinScene(char scenelevel='m',QWidget*parent=nullptr);
    QGraphicsScene*winscene;
    char lvl;
    QList<QGraphicsPixmapItem*>wknopki;
public slots:
    void WFAQclicked();
    void GoToMenu();
    void RestartGame();
    void BackToWinGameScene();
};


#endif // AFTERWINSCENE_H
