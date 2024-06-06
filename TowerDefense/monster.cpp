#include "monster.h"
#include <QPixmap>
#include <QDebug>
#include "healthbar.h"

    Monster::Monster(const QString &imagePath, QWidget *parent, int x, int y, int laneNumber)
    : QLabel(parent), posX(0), posY(0), speed(1000), health(100), laneNumber(laneNumber)
{
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load monster image!";
    } else {
        setPixmap(pixmap);
    }
    setScaledContents(true);
    setFixedSize(50, 50); // Adjust size as needed

    // Health bar
    healthBar = new HealthBar(parent);
    healthBar->move(posX, posY - 10);
    healthBar->show();

    moveTimer = new QTimer(this);

    connect(moveTimer, &QTimer::timeout, this, &Monster::moveMonster);
    moveTimer->start(speed);

    // Timer for wave control
    waveTimer = new QTimer(this);
    connect(waveTimer, &QTimer::timeout, this, &Monster::startWaves);
    waveTimer->setSingleShot(true); // Only trigger once
    waveTimer->start(20000);

    // Button to start waves
    pushButtonMonster = parent->findChild<QPushButton*>("pushButtonMonster");

    connect(pushButtonMonster, &QPushButton::clicked, this, &Monster::waveButton);

    // Timers for individual waves
    wave1Timer = new QTimer(this);
    wave1Timer->setSingleShot(true);
    connect(wave1Timer, &QTimer::timeout, this, &Monster::startWave1);

    wave2Timer = new QTimer(this);
    wave2Timer->setSingleShot(true);
    connect(wave2Timer, &QTimer::timeout, this, &Monster::startWave2);

    wave3Timer = new QTimer(this);
    wave3Timer->setSingleShot(true);
    connect(wave3Timer, &QTimer::timeout, this, &Monster::startWave3);

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

    // Lane1
    if (laneNumber == 1 && wave1Move) {
        if (posX < 150) {
            posX += 10;
        } else if (posX < 197) {
            posY += 10;
            posX += 5;
        } else if (posX < 378) {
            posX += 10;
        } else if (posX < 420){
            posY += 9;
            posX += 4;
        } else if (posX < 700){
            posX += 10;
        } else {
            posX += 0;
            posY += 0;
        }
    }

    //Lane 2
    else if (laneNumber == 2 && wave2Move) {
        if (posY < 180) {
            posY += 2;
        } else if (posX> 795) {
            posX -= 2;
        } else if (posY < 350) {
            posY += 2;
        } else {
            posX += 0;
            posY += 0;
        }
    }

    // Lane 3
    else if (laneNumber == 3 && wave3Move) {
        if (posX > 1300) {
            posX -= 5;
        } else if (posY < 465) {
            posY += 5;
        } else if (posX > 890) {
            posX -= 5;
        } else {
            posX += 0;
            posY += 0;
        }
    }
    move(posX, posY);

    // Update health bar position
    healthBar->move(posX, posY - 10);

    // Damage
    healthBar->updatePosition(posX, posY);
}

void Monster::setHealth(int newHealth) {
    health = newHealth;
    healthBar->setHealth(newHealth);
}

void Monster::waveButton() {
    wave1Timer->start(0);
    wave2Timer->start(5000);
    wave3Timer->start(10000);
}

void Monster::startWaves() {
    wave1Timer->start(0);
    wave2Timer->start(5000);
    wave3Timer->start(10000);
}

void Monster::startWave1() {
    wave1Move = true;
}

void Monster::startWave2() {
    wave2Move = true;
}

void Monster::startWave3() {
    wave3Move = true;
}



void Monster::ReduceHealth() {
    const int proximityThreshold = 50; // Distance seuil pour la proximité
    const QPoint proximityPoint1(630, 330);
    const QPoint proximityPoint2(1000, 540);

    QPoint currentPosition(posX, posY);

    if ((currentPosition - proximityPoint1).manhattanLength() < proximityThreshold ||
        (currentPosition - proximityPoint2).manhattanLength() < proximityThreshold) {
        int newHealth = health - 1; // Réduit la santé de 1
        if (newHealth < 0) newHealth = 0; // Évite d'avoir une santé négative
        setHealth(newHealth);
    }
}
