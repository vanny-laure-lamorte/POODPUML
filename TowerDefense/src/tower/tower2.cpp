#include "tower2.h"

Tower2::Tower2(QWidget *parent, Player *player)
    : AbstractTower(parent, player)
{
    // Customize initialization if needed
}

Tower2::~Tower2()
{
    // Clean up
}

void Tower2::displayTower()
{
    if (towerLevel == 0) {
        towerLabel->setPixmap(QPixmap(":/assets/img/Hammer1.png"));
    }
    else if (towerLevel == 1) {
        towerLabel->setPixmap(QPixmap(":/assets/img/tower1.png"));
    } else if (towerLevel == 2) {
        towerLabel->setPixmap(QPixmap(":/assets/img/tower2.png"));
    } else if (towerLevel == 3) {
        towerLabel->setPixmap(QPixmap(":/assets/img/tower3.png"));
    }
}
