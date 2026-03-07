#include "gamescene.h"
#include <QGraphicsRectItem>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 800, 600);

    // приклад тестового об'єкта, щоб бачити сцену живою
    auto *box = new QGraphicsRectItem(0, 0, 50, 50);
    box->setPos(200, 200);
    addItem(box);

    // ігровий цикл
    connect(&m_timer, &QTimer::timeout, this, &GameScene::tick);
    m_timer.start(16); // ~60 FPS
}

void GameScene::tick()
{

        // Тут буде логіка гри:
        // - рух об'єктів
        // - колізії
        // - спавн
        // - перевірка меж сцени
}
