#include <QApplication>
#include <QGraphicsView>
#include <QPainter>
#include "gamescene.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto *scene = new GameScene();      // наш "світ"
    QGraphicsView view(scene);        // наше "вікно/камера"

    view.setFixedSize(800, 600);
    view.setRenderHint(QPainter::Antialiasing);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view.show();
    return app.exec();
}

