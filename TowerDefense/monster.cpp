#include "monster.h"
#include <QPixmap>
#include <QDebug>

#include "monster.h"

Monster::Monster(const QString &imagePath, QWidget *parent)
    : QLabel(parent), posX(0), posY(0), speed(1000), health(100)
{
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load monster image!";
    } else {
        setPixmap(pixmap);
    }
    setScaledContents(true);
    setFixedSize(50, 50); // Adjust size as needed

    //health bar
    healthBar = new QProgressBar(parent);
    healthBar->setRange(0, 100);
    healthBar->setValue(health);
    healthBar->setGeometry(this->x(), this->y() - 10, 50, 5);
    healthBar->show();

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Monster::moveMonster);
    moveTimer->start(speed);
}

void Monster::moveSpeed(int newSpeed) {
    speed = newSpeed;
    moveTimer->setInterval(speed);
}

void Monster::initialPosition(int x, int y) {
    posX = x;
    posY = y;
    move(posX, posY);

    //health bar
    healthBar->move(posX, posY - 10);
}

void Monster::moveMonster(){
    posX += 10; // Adjust movement increment as needed
    move(posX, posY);

    //health bar
    healthBar->move(posX, posY - 10);
}

void Monster::setHealth(int newHealth) {
    health = newHealth;
    healthBar->setValue(health);
}


void Monster::updatePosition() {
    // Move the monster
    posX += 10; // Adjust movement increment as needed
    move(posX, posY);

    // Move the health bar
    healthBar->move(posX, posY - 10);
}
