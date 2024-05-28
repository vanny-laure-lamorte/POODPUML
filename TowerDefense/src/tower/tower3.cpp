#include "tower3.h"

Tower3::Tower3(QWidget *parent, Player *player)
    : AbstractTower(parent, player)
{
    // Customize initialization if needed
}

Tower3::~Tower3()
{
    // Clean up
}

void Tower3::displayTower()
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
