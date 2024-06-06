#include "healthbar.h"
#include <QPainter>

HealthBar::HealthBar(QWidget *parent) : QWidget(parent), health(100) {
    setFixedSize(50, 6);
}

void HealthBar::setHealth(int newHealth) {
    health = newHealth;
    update();
}

void HealthBar::updatePosition(int x, int y) {
    monsterPosX = x;
    monsterPosY = y;
    update();
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Distance from tower
    int tower1X = 630, tower1Y = 330;
    int tower2X = 1000, tower2Y = 540;
    double distanceToTower1 = std::sqrt(std::pow(monsterPosX - tower1X, 2) + std::pow(monsterPosY - tower1Y, 2));
    double distanceToTower2 = std::sqrt(std::pow(monsterPosX - tower2X, 2) + std::pow(monsterPosY - tower2Y, 2));

    // From green to red
    if (distanceToTower1 <= 200 || distanceToTower2 <= 200) {
        painter.setBrush(Qt::red);
    } else {
        painter.setBrush(Qt::green);
    }

    int healthWidth = static_cast<int>((static_cast<float>(health) / 100.0f) * width());
    painter.drawRect(0, 0, healthWidth, height());
}
