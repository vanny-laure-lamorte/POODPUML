#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class HealthBar;

class Monster : public QLabel {
    Q_OBJECT

public:
    explicit Monster(const QString &imagePath, QWidget *parent = nullptr, int posX = 0, int posY = 0, int laneNumber = 0);
    void moveSpeed(int speed);
    void initialPosition(int x, int y);
    void setHealth(int health);
    void startWaves();

public slots:
    void moveMonster();

private slots:
    void waveButton();
    void startWave1();
    void startWave2();
    void startWave3();

private:
    int posX;
    int posY;
    int speed;
    int health;
    int laneNumber;

    bool wave1Move = false;
    bool wave2Move = false;
    bool wave3Move = false;

    QTimer *moveTimer;
    QTimer *waveTimer;
    QTimer *wave1Timer;
    QTimer *wave2Timer;
    QTimer *wave3Timer;
    QPushButton *pushButtonMonster;

    HealthBar *healthBar;
    void ReduceHealth();
};

#endif // MONSTER_H
