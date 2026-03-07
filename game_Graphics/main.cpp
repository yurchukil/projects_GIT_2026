#include "gamescene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameScene w;
    w.show();
    return a.exec();
}
