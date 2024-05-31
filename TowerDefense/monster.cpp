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

        //health bar
        healthBar = new HealthBar(parent);
        healthBar->move(posX, posY - 10);
        healthBar->show();

        moveTimer = new QTimer(this);

        connect(moveTimer, &QTimer::timeout, this, &Monster::moveMonster);
        moveTimer->start(speed);

        timeLabel1 = parent->findChild<QLabel*>("timeLabel1");


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

    void Monster::updateCountdown() {

        if (!wave1Move){
            *time = time->addSecs(-1);
        }

        else if (!wave2Coutdown){
            *time = QTime(0, 0, 20);
            wave2Coutdown = true;
        }
        else if(!wave2Move){
            *time = time->addSecs(-1);
        }
        else if (!wave3Coutdown){
            *time = QTime(0, 0, 20);
            wave3Coutdown = true;
        }
        else if (!wave3Move){
            *time = time->addSecs(-1);
        }
        else{
            timeLabel1->setText(time->toString(""));
        }
        if (*time >= QTime(0,0,1)){
            timeLabel1->setText(time->toString("m:ss"));
        }
        else {
            timeLabel1->setText(time->toString(""));
        }
    }

    void Monster::initializeTimers(){
        qDebug() << "init";

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

    // test
