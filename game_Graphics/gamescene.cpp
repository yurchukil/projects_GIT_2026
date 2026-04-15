#include "gamescene.h"
#include <QGraphicsRectItem>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 800, 600);

    // приклад тестового об'єкта, щоб бачити сцену живою
    QGraphicsRectItem *box = new QGraphicsRectItem(0, 0, 50, 50);
    box->setPos(200, 200);
    addItem(box);  box->setBrush(Qt::green);

    QPen pen(Qt::black); // колір
    pen.setWidth(2); // товщина
    pen.setStyle(Qt::DashLine); // стиль лінії
    box->setPen(pen);

    m_scoreText = new QGraphicsTextItem("Score: 0");
    m_scoreText->setPos(100, 10);
    addItem(m_scoreText);

    m_text = new QGraphicsTextItem("START");
    m_text->setDefaultTextColor(Qt::black);
    m_text->setFont(QFont("Arial", 30, QFont::Bold));
    addItem(m_text);
    QRectF r = m_text->boundingRect();
    m_text->setTransformOriginPoint(r.center());
    m_text->setPos(400, 300);


    //зображення
    QPixmap pix(":/img/IMG/smile.png");
    QGraphicsPixmapItem *player = new QGraphicsPixmapItem(pix);

    player->setPos(200,250);
QPointF p = player->pos(); qreal x = player->x(); qreal y = player->y();


player->setVisible(false); // сховати
player->setVisible(true);  // показати
player->hide();            // те саме що setVisible(false)
player->show();            // те саме що setVisible(true)

bool v = player->isVisible();

// Можна переміщати мишею
player->setFlag(QGraphicsItem::ItemIsMovable);

// Можна виділяти
player->setFlag(QGraphicsItem::ItemIsSelectable);

// Елемент реагує на фокус клавіатури
player->setFlag(QGraphicsItem::ItemIsFocusable);

// Повідомляти про зміну позиції
player->setFlag(QGraphicsItem::ItemSendsGeometryChanges);

// Кілька прапорців одразу
player->setFlags(QGraphicsItem::ItemIsMovable |
               QGraphicsItem::ItemIsSelectable);


player->setData(0, "enemy");
player->setData(1, 100); // здоров'я

// Отримати
QString type = player->data(0).toString();
int hp = player->data(1).toInt();




    player->setScale(0.1); player->setRotation(45);
    addItem(player);  player->setOffset(15,15);
    // ігровий цикл
    connect(&m_timer, &QTimer::timeout, this, &GameScene::tick);
    m_timer.start(16); // ~60 FPS
}

void GameScene::tick()
{
    m_score++;
    m_scoreText->setPlainText(QString("Score: %1").arg(m_score));

    qreal s = m_text->scale();

    if (s > 1.2) m_scaleDir = -1;
    if (s < 0.8) m_scaleDir = 1;

    m_text->setScale(s + 0.01 * m_scaleDir);


        // Тут буде логіка гри:
        // - рух об'єктів
        // - колізії
        // - спавн
        // - перевірка меж сцени
}
