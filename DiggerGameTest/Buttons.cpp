#include <QGraphicsSceneMouseEvent>
#include "Buttons.h"

Buttons::Buttons(ButtonAction buttonaction,QGraphicsItem*parent){
    if (buttonaction==RestartWinGame){
        buttonused=RestartWinGame;
        setPixmap(QPixmap(":/images/restartwingame.png"));
    }
    else if (buttonaction==FromWinToMenu){
        setPixmap(QPixmap(":/images/wintomenu.png"));
        buttonused=FromWinToMenu;
    }
    else if (buttonaction==FromLoseToMenu){
        setPixmap(QPixmap(":/images/losetomenu.png"));
        buttonused=FromWinToMenu;
    }
    else if (buttonaction==RestartLoseGame){
        setPixmap(QPixmap(":/images/restartlosegame.png"));
        buttonused=RestartWinGame;
    }
    else if (buttonaction==Settings){
        setPixmap(QPixmap(":/images/selectsettings.png"));
        buttonused=Settings;
    }
    else if (buttonaction==NewGame){
        setPixmap(QPixmap(":/images/newgame.png"));
        buttonused=NewGame;
    }
    else if (buttonaction==EasyLevel){
        setPixmap(QPixmap(":/images/easyselect.png"));
        buttonused=EasyLevel;
    }
    else if (buttonaction==HardLevel){
        setPixmap(QPixmap(":/images/hardselect.png"));
        buttonused=HardLevel;
    }
    else if (buttonaction==MediumLevel){
        setPixmap(QPixmap(":/images/mediumselect.png"));
        buttonused=MediumLevel;
    }
    else if (buttonaction==ActiveMediumLevel){
        setPixmap(QPixmap(":/images/activemediumselect.png"));
        buttonused=ActiveMediumLevel;
    }
    else if (buttonaction==ActiveEasyLevel){
        setPixmap(QPixmap(":/images/activeeasyselect.png"));
        buttonused=ActiveEasyLevel;
    }
    else if (buttonaction==ActiveHardLevel){
        setPixmap(QPixmap(":/images/activehardselect.png"));
        buttonused=ActiveHardLevel;
    }
    else if (buttonaction==FAQButton){
        setPixmap(QPixmap(":/images/faqbutton.png"));
        buttonused=FAQButton;
    }
    else if (buttonaction==BackButton){
        setPixmap(QPixmap(":/images/nazad.png"));
        buttonused=BackButton;
    }
    else if (buttonaction==BackToMenuButton){
        setPixmap(QPixmap(":/images/gamebacktomenu.png"));
        buttonused=BackToMenuButton;
    }
}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *eventer) {
    emit pressButton();
}


