#include "monster.h"
#include <QPixmap>
#include <QDebug>

#include "monster.h"

Monster::Monster(QWidget *parent): QLabel(parent), posX(0), posY(0) {
    setPixmap(QPixmap(":assets/img/monster1.png"));
    setScaledContents(true);
    setFixedSize(100, 100);
}

void Monster::moveMonster(int x, int y){
    posX = x;
    posY = y;
    move(posX, posY);
}
