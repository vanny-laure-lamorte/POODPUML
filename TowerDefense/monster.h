#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QTimer> //speed monsters
#include <QProgressBar> // health bar

class Monster: public QLabel {
    Q_OBJECT

public:
    explicit Monster(const QString &imagePath, QWidget *parent = nullptr);
    void moveMonster();
    void moveSpeed(int speed);
    void initialPosition(int x, int y);

    //health
    void setHealth(int health);

private:
    int posX;
    int posY;
    int speed;
    QTimer *moveTimer;

    //health bar
    QProgressBar *healthBar;
    int health;

public slots:
    void updatePosition();
};

#endif // MONSTER_H
