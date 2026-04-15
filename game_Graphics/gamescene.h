#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent = nullptr);

    QGraphicsTextItem *m_scoreText;
    int m_score = 0;

    QGraphicsTextItem *m_text;
    qreal m_scaleDir = 1.0;

private slots:
    void tick();          // логіка гри (оновлення стану)

private:
    QTimer m_timer;       // ігровий таймер
};
#endif // GAMESCENE_H
