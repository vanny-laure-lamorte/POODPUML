#include "monster.h"
#include <QPixmap>
#include <QDebug>
#include "healthbar.h"

Monster::Monster(const QString &imagePath, QWidget *parent, Player *player, int x, int y, int speed, int laneNumber, bool attacking)
    : QLabel(parent), posX(x), posY(y), speed(1000), health(100), laneNumber(laneNumber), attacking(attacking), player(player) // Initialize attacking and player
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

    timeLabel1 = parent->findChild<QLabel*>("timeLabel1");
    waveCounterLabel = parent->findChild<QLabel*>("waveCounterLabel");


    // Button to start waves
    ButtonMonster1 = parent->findChild<QPushButton*>("ButtonMonster1");

    connect(ButtonMonster1, &QPushButton::clicked, this, &Monster::waveButton);

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

QList<Monster*> Monster::generateMonsters(QWidget *parent, Player *player) {
    QList<Monster*> monsters;

    // Generate monsters for lane 1
    monsters.append(new Monster(":/assets/img/monster1.png", parent, player, 100, 270, 980, 1));
    monsters.append(new Monster(":/assets/img/monster1.png", parent, player, 100, 305, 500, 1));
    monsters.append(new Monster(":/assets/img/monster1.png", parent, player, 50, 270, 500, 1));
    monsters.append(new Monster(":/assets/img/monster2.png", parent, player, 40, 300, 980,  1));
    monsters.append(new Monster(":/assets/img/monster2.png", parent, player, 70, 290, 500, 1));
    monsters.append(new Monster(":/assets/img/monster4.png", parent, player, 100, 270, 100, 1));
    monsters.append(new Monster(":/assets/img/monster4.png", parent, player, 100, 300, 80, 1));

    // Generate monsters for lane 2
    monsters.append(new Monster(":/assets/img/monster11.png", parent, player, 1140, 0, 100, 2));
    monsters.append(new Monster(":/assets/img/monster12.png", parent, player, 1150, 0, 70, 2));
    monsters.append(new Monster(":/assets/img/monster13.png", parent, player, 1170, 0, 50, 2));
    monsters.append(new Monster(":/assets/img/monster14.png", parent, player, 1150, 2, 50, 2));
    monsters.append(new Monster(":/assets/img/monster15.png", parent, player, 1165, 50, 50, 2));

    // Generate monsters for lane 3
    monsters.append(new Monster(":/assets/img/monster21.png", parent, player, 1485, 290, 70, 3));
    monsters.append(new Monster(":/assets/img/monster22.png", parent, player, 1495, 310, 60, 3));
    monsters.append(new Monster(":/assets/img/monster23.png", parent, player, 1510, 305, 70, 3));
    monsters.append(new Monster(":/assets/img/monster23.png", parent, player, 1510, 315, 70, 3));
    monsters.append(new Monster(":/assets/img/monster23.png", parent, player, 1480, 300, 70, 3));

    return monsters;
}

void Monster::moveMonster() {
    if (!player->gameOver) {
        // Lane 1
        if (laneNumber == 1 && wave1Move) {
            if (posX < 150) {
                posX += 10;
            } else if (posX < 197) {
                posY += 10;
                posX += 5;
            } else if (posX < 378) {
                posX += 10;
            } else if (posX < 420) {
                posY += 9;
                posX += 4;
            } else if (posX < 700) {
                posX += 10;
            } else {
                // reachedEnd = true;
                attacking = true;
            }
        }

        // Lane 2
        else if (laneNumber == 2 && wave2Move) {
            if (posY < 180) {
                posY += 2;
            } else if (posX > 795) {
                posX -= 2;
            } else if (posY < 350) {
                posY += 2;
            } else {
                // reachedEnd = true;
                attacking = true;
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
                // reachedEnd = true;
                attacking = true;
            }
        }

    move(posX, posY);

    // Update health bar position
    healthBar->move(posX, posY - 10);

    // Damage
    healthBar->updatePosition(posX, posY);

    }
}

void Monster::setHealth(int newHealth) {
    health = newHealth;
    healthBar->setHealth(newHealth);
}

void Monster::waveButton() {
    wave1Timer->start(0);
    wave2Timer->start(20000);
    wave3Timer->start(40000);
}

void Monster::startWaves() {
    wave1Timer->start(0);
    wave2Timer->start(20000);
    wave3Timer->start(40000);
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

void Monster::updateCountdown() {
    if (!player->gameOver){
        if (!wave1Move) {
            *time = time->addSecs(-1);
        } else if (!wave2Coutdown) {
            *time = QTime(0, 0, 20);
            wave2Coutdown = true;
            waveCounterLabel->setText("Wave 2 / 3");
        } else if (!wave2Move) {
            *time = time->addSecs(-1);
        } else if (!wave3Coutdown) {
            *time = QTime(0, 0, 20);
            wave3Coutdown = true;
            waveCounterLabel->setText("Wave 3 / 3");
        } else if (!wave3Move) {
            *time = time->addSecs(-1);
        } else {
            timeLabel1->setText(time->toString(""));
        }
        if (*time >= QTime(0, 0, 1)) {
            timeLabel1->setText(time->toString("m:ss"));
        } else {
            timeLabel1->setText(time->toString(""));
        }
    }
    else {
        waveCounterLabel->setText("");
        timeLabel1->setText(time->toString(""));
    }
}

void Monster::initializeTimers() {
    // Timer for wave control
    countdown = new QTimer(this);
    countdown->start(1000);
    connect(countdown, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    time = new QTime(0, 0, 20);

    waveTimer = new QTimer(this);
    connect(waveTimer, &QTimer::timeout, this, &Monster::startWaves);
    waveTimer->setSingleShot(true); // Only trigger once
    waveTimer->start(20000);
}
