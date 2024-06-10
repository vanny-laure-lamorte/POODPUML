#include "../include/healthbar.h"
#include <QDebug>

// Initialize the static member
QList<HealthBar*> HealthBar::healthbarList;

HealthBar::HealthBar(QWidget *parent, Monster *monster, int health, int monsterPosX, int monsterPosY)
    : QWidget(parent), health(health), monsterPosX(monsterPosX), monsterPosY(monsterPosY), monster(monster) {
    setFixedSize(50, 6);
    healthbarList.append(this); // Add this instance to the list

    damageTimer = new QTimer(this);
    connect(damageTimer, &QTimer::timeout, this, &HealthBar::applyDamageToClosest);
    damageTimer->start(1000); // 1000 milliseconds = 1 second
}

void HealthBar::setHealth(int newHealth) {
    health = newHealth;
    update();

    if (health <= 0) {
        healthbarList.removeOne(this);
        this->deleteLater();
    }
}

tuple<int, int, int> HealthBar::updatePosition(int x, int y) {
    monsterPosX = x;
    monsterPosY = y;
    return {health, monsterPosX, monsterPosY};
}

void HealthBar::applyDamageToClosest() {
    // Towers positions
    const int tower1X = 670, tower1Y = 385;
    const int tower2X = 1040, tower2Y = 590;

    HealthBar* closestToTower1 = nullptr;
    HealthBar* closestToTower2 = nullptr;
    double minDistanceToTower1 = std::numeric_limits<double>::max();
    double minDistanceToTower2 = std::numeric_limits<double>::max();

    for (HealthBar* healthBar : healthbarList) {
        double distanceToTower1 = std::sqrt(std::pow(healthBar->monsterPosX - tower1X, 2) + std::pow(healthBar->monsterPosY - tower1Y, 2));
        if (distanceToTower1 < minDistanceToTower1) {
            minDistanceToTower1 = distanceToTower1;
            closestToTower1 = healthBar;
        }

        double distanceToTower2 = std::sqrt(std::pow(healthBar->monsterPosX - tower2X, 2) + std::pow(healthBar->monsterPosY - tower2Y, 2));
        if (distanceToTower2 < minDistanceToTower2) {
            minDistanceToTower2 = distanceToTower2;
            closestToTower2 = healthBar;
        }
    }

    if (closestToTower1 && minDistanceToTower1 <= 200) {
        closestToTower1->setHealth(closestToTower1->health - 1); // Example damage value
    }

    if (closestToTower2 && minDistanceToTower2 <= 200) {
        closestToTower2->setHealth(closestToTower2->health - 1); // Example damage value
    }
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

    if (health < 35) {
        painter.setBrush(Qt::red);
    } else if (health < 99) {
        painter.setBrush(QColor(255, 165, 0)); // Orange
    } else {
        painter.setBrush(Qt::green);
    }

    int healthWidth = static_cast<int>((static_cast<float>(health) / 100.0f) * width());
    painter.drawRect(0, 0, healthWidth, height());
}
