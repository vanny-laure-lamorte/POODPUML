#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QTimer> //speed monsters

class HealthBar;

class Monster: public QLabel {
    Q_OBJECT

public:
    explicit Monster(const QString &imagePath, QWidget *parent = nullptr, int posX = 0, int posY = 0);
    void moveSpeed(int speed);
    void initialPosition(int x, int y);
    int posX;
    int posY;

    //health
    void setHealth(int health);
public slots:
    void moveMonster();


private:

    int speed;
    QTimer *moveTimer;

    //health
    int health;
    HealthBar *healthBar;

};

#endif // MONSTER_H
