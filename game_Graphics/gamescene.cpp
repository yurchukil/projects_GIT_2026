#include "gamescene.h"
#include <QGraphicsRectItem>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 800, 600);

    // приклад тестового об'єкта, щоб бачити сцену живою
    QGraphicsRectItem *box = new QGraphicsRectItem(0, 0, 50, 50);
    box->setPos(0, 0);
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





    QPainterPath shield;

    // 🔹 1. Основа "щита"
    shield.moveTo(150, 120);
    shield.lineTo(250, 120);
    shield.quadTo(280, 170, 250, 240);
    shield.lineTo(200, 280);
    shield.lineTo(150, 240);
    shield.quadTo(120, 170, 150, 120);
    shield.closeSubpath();


    // 🔹 2. Внутрішнє коло
    QPainterPath circle;
    circle.addEllipse(175, 150, 50, 50);


    // 🔹 3. Дуга
    QPainterPath arc;
    arc.moveTo(170, 200);
    arc.arcTo(170, 180, 60, 60, 180, 180);


    // 🔹 4. Зірка
    QPainterPath star;
    star.moveTo(200, 160);
    star.lineTo(205, 180);
    star.lineTo(225, 180);
    star.lineTo(210, 190);
    star.lineTo(215, 210);
    star.lineTo(200, 198);
    star.lineTo(185, 210);
    star.lineTo(190, 190);
    star.lineTo(175, 180);
    star.lineTo(195, 180);
    star.closeSubpath();


    // 🔹 5. Об’єднання
    QPainterPath result = shield;
    result.addPath(circle);
    result.addPath(arc);

    // 🔹 6. Вирізати зірку
    result = result.subtracted(star);


    // 🔹 7. Відображення
    QGraphicsPathItem *item = new QGraphicsPathItem(result);
    item->setPen(QPen(Qt::black, 2));
    item->setBrush(QBrush(Qt::yellow));

    addItem(item);


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
