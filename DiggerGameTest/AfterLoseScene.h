#ifndef AFTERLOSESCENE_H
#define AFTERLOSESCENE_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <Buttons.h>

class AfterLoseScene:public QGraphicsView{
Q_OBJECT
public:
    AfterLoseScene(char scenelevel='m',QWidget*parent=nullptr);
    QGraphicsScene*losescene;
    char lvl;
    QList<QGraphicsPixmapItem*>lknopki;
public slots:
    void LFAQclicked();
    void GoToMenu();
    void RestartGame();
    void BackToLoseGameScene();
};

#endif // AFTERLOSESCENE_H
