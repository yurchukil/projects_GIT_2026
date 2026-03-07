#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QMainWindow>

class GameScene : public QMainWindow
{
    Q_OBJECT

public:
    GameScene(QWidget *parent = nullptr);
    ~GameScene();
};
#endif // GAMESCENE_H
