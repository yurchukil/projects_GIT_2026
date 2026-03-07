#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent = nullptr);

private slots:
    void tick();          // логіка гри (оновлення стану)

private:
    QTimer m_timer;       // ігровий таймер
};
#endif // GAMESCENE_H
