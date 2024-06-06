#include "../include/healthbar.h"

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
    applyDamage();
}

void HealthBar::applyDamage() {
    // Towers positions
    int tower1X = 630, tower1Y = 330;
    int tower2X = 1000, tower2Y = 540;

    // Distances to towers
    double distanceToTower1 = std::sqrt(std::pow(monsterPosX - tower1X, 2) + std::pow(monsterPosY - tower1Y, 2));
    double distanceToTower2 = std::sqrt(std::pow(monsterPosX - tower2X, 2) + std::pow(monsterPosY - tower2Y, 2));

    // Apply damage based on proximity to towers
    if (distanceToTower1 <= 200) {
        health -= 1; // Example damage value
    }
    if (distanceToTower2 <= 200) {
        health -= 1; // Example damage value
    }

    // Ensure health doesn't go below 0
    if (health < 0) {
        health = 0;
    }

    update(); // Request a repaint
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Blalck

    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

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


