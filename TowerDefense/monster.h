#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>


class Monster: public QLabel {
    Q_OBJECT

public:
    explicit Monster(QWidget *parent = nullptr);
    void moveMonster(int x, int y);

private:
    int posX;
    int posY;
};

#endif // MONSTER_H
