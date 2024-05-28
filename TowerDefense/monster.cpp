#include "monster.h"
#include <QPixmap>
#include <QDebug>

Monster::Monster(const QString &imagePath, QWidget *parent, int x, int y)
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

void Monster::moveMonster() {
    // Update monster's position based on your logic
    if (posX < 150) {
        posX += 10; // Adjust movement increment as needed
    } else if (posX < 197) {
        posY += 10; // Adjust movement increment as needed
        posX += 5; // Adjust movement increment as needed
    } else if (posX < 378) {
        posX += 10; // Adjust movement increment as needed
    } else if (posX < 420){
        posY += 9; // Adjust movement increment as needed
        posX += 4; // Adjust movement increment as needed
    } else if (posX < 700){
        posX += 10; // Adjust movement increment as needed
    } else {
        posX += 0;
        posY += 0;
    }
    move(posX, posY);
    // Update health bar position
    healthBar->move(posX, posY - 10);
}


void Monster::setHealth(int newHealth) {
    health = newHealth;
    healthBar->setValue(health);
}
