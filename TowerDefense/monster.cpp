#include "monster.h"
#include <QPixmap>
#include <QDebug>

#include "monster.h"

Monster::Monster(const QString &imagePath, QWidget *parent)
    : QLabel(parent), posX(0), posY(0), speed(1000) // Default speed 1000ms
{
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load monster image!";
    } else {
        setPixmap(pixmap);
    }
    setScaledContents(true);
    setFixedSize(50, 50); // Adjust size as needed

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
}

void Monster::moveMonster(){
    posX += 10; // Adjust movement increment as needed
    move(posX, posY);
}
