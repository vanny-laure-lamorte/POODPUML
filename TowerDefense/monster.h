#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QTimer> //speed monsters

class Monster: public QLabel {
    Q_OBJECT

public:
    explicit Monster(const QString &imagePath, QWidget *parent = nullptr);
    void moveMonster();
    void moveSpeed(int speed);
    void initialPosition(int x, int y);

private:
    int posX;
    int posY;
    int speed;
    QTimer *moveTimer;
};

#endif // MONSTER_H
