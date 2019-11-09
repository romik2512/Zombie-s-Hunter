#include <QApplication>
#include "QTime"
#include "Menu.h"

Menu * menu;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    menu=new Menu();
    return a.exec();
}
