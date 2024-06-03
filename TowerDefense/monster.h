#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>

#include "player.h"

class HealthBar;

class Monster : public QLabel {
    Q_OBJECT

public:
    explicit Monster(const QString &imagePath, QWidget *parent = nullptr, Player *player = nullptr, int posX = 0, int posY = 0, int speed = 0, int laneNumber = 0, bool attacking = false);
    static QList<Monster*> generateMonsters(QWidget *parent, Player *player);
    void moveSpeed(int speed);
    void initialPosition(int x, int y);
    void setHealth(int health);
    void startWaves();
    void initializeTimers();
    bool gameLaunched = false;
    bool attacking;

public slots:
    void moveMonster();
    void updateCountdown();

private slots:
    void waveButton();
    void startWave1();
    void startWave2();
    void startWave3();

private:
    Player *player;

    int posX;
    int posY;
    int speed;
    int health;
    int laneNumber;

    bool wave1Move = false;
    bool wave2Move = false;
    bool wave3Move = false;

    bool wave2Coutdown = false;
    bool wave3Coutdown = false;

    QTimer *moveTimer;
    QTimer *waveTimer;
    QTimer *wave1Timer;
    QTimer *wave2Timer;
    QTimer *wave3Timer;
    QPushButton *ButtonMonster1;
    QLabel *timeLabel1;

    QTime *time;
    QTimer *countdown;

    QList<Monster*> monsters;

    HealthBar *healthBar;
};
#endif
