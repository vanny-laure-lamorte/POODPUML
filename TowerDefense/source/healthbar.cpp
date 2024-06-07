#include "../include/healthbar.h"

// Initialize the static members
QList<HealthBar*> HealthBar::healthbarList;

HealthBar::HealthBar(QWidget *parent, int health, int monsterPosX, int monsterPosY)
    : QWidget(parent), health(health), monsterPosX(monsterPosX), monsterPosY(monsterPosY) {
    setFixedSize(50, 6);
    healthbarList.append(this); // Add this instance to the list

    damageTimer = new QTimer;
    connect(damageTimer, &QTimer::timeout, this, &HealthBar::applyDamageToClosest);
    damageTimer->start(1000); // 1000 milliseconds = 1 second

}

void HealthBar::setHealth(int newHealth) {
    health = newHealth;
    update();
}

void HealthBar::updatePosition(int x, int y) {
    monsterPosX = x;
    monsterPosY = y;
}

void HealthBar::applyDamageToClosest() {
    // Towers positions
    int tower1X = 630, tower1Y = 330;
    int tower2X = 1000, tower2Y = 540;

    // Variables to track the closest health bars
    HealthBar* closestToTower1 = nullptr;
    HealthBar* closestToTower2 = nullptr;
    double minDistanceToTower1 = std::numeric_limits<double>::max();
    double minDistanceToTower2 = std::numeric_limits<double>::max();

    // Iterate through all health bars to find the closest ones
    for (HealthBar* healthBar : healthbarList) {
        // Distance to tower 1
        double distanceToTower1 = std::sqrt(std::pow(healthBar->monsterPosX - tower1X, 2) + std::pow(healthBar->monsterPosY - tower1Y, 2));
        if (distanceToTower1 < minDistanceToTower1) {
            minDistanceToTower1 = distanceToTower1;
            closestToTower1 = healthBar;
        }

        // Distance to tower 2
        double distanceToTower2 = std::sqrt(std::pow(healthBar->monsterPosX - tower2X, 2) + std::pow(healthBar->monsterPosY - tower2Y, 2));
        if (distanceToTower2 < minDistanceToTower2) {
            minDistanceToTower2 = distanceToTower2;
            closestToTower2 = healthBar;
        }
    }

    // Apply damage to the closest health bars
    if (closestToTower1 && minDistanceToTower1 <= 200) {
        closestToTower1->health -= 1; // Example damage value
        closestToTower1->update(); // Request a repaint for the health bar
    }

    if (closestToTower2 && minDistanceToTower2 <= 200) {
        closestToTower2->health -= 1; // Example damage value
        closestToTower2->update(); // Request a repaint for the health bar
    }
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Black background
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

    if (health < 35) {
        painter.setBrush(Qt::red);
    } else if (health < 66) {
        painter.setBrush(QColor(255, 165, 0)); // Orange
    } else {
        painter.setBrush(Qt::green);
    }

    int healthWidth = static_cast<int>((static_cast<float>(health) / 100.0f) * width());
    painter.drawRect(0, 0, healthWidth, height());
}
