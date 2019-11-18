QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AfterLoseScene.cpp \
    AfterWinScene.cpp \
    Bam.cpp \
    Buttons.cpp \
    Crash.cpp \
    Dynamit.cpp \
    EarthBlocks.cpp \
    FireBoost.cpp \
    GBlocks.cpp \
    Game.cpp \
    Gametime.cpp \
    Kolvo.cpp \
    LavaBlocks.cpp \
    Menu.cpp \
    NewDynamit.cpp \
    NewSpeed.cpp \
    Player.cpp \
    SecretBox.cpp \
    Zapas.cpp \
    Zombie.cpp \
    main.cpp

HEADERS += \
    AfterLoseScene.h \
    AfterWinScene.h \
    Bam.h \
    Buttons.h \
    Crash.h \
    Dynamit.h \
    EarthBlocks.h \
    FireBoost.h \
    GBlocks.h \
    Game.h \
    Gametime.h \
    Kolvo.h \
    LavaBlocks.h \
    Menu.h \
    NewDynamit.h \
    NewSpeed.h \
    Player.h \
    SecretBox.h \
    Zapas.h \
    Zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
