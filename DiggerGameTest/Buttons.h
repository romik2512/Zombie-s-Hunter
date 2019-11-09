#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGraphicsPixmapItem>
#include <QObject>

enum ButtonAction{
    NewGame,
    RestartWinGame,
    RestartLoseGame,
    FromLoseToMenu,
    FromWinToMenu,
    Settings,
    EasyLevel,
    MediumLevel,
    HardLevel,
    ActiveEasyLevel,
    ActiveMediumLevel,
    ActiveHardLevel
};

class Buttons: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    char buttontype;
    ButtonAction buttonused;
    Buttons(ButtonAction buttonaction=NewGame,QGraphicsItem*parent=nullptr);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent * eventer);
};


#endif // BUTTONS_H
