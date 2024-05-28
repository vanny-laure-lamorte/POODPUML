#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QTimer> //speed monsters

class HealthBar;

class Monster: public QLabel {
    Q_OBJECT

public:
    Monster(const QString &imagePath, QWidget *parent = nullptr);
    void moveSpeed(int speed);
    void initialPosition(int x, int y);

    //health
    void setHealth(int health);
    void updatePosition();

public slots:
    void moveMonster();

private:
    int posX;
    int posY;
    int speed;
    QTimer *moveTimer;

    //health
    int health;
    HealthBar *healthBar;

};

#endif // MONSTER_H
