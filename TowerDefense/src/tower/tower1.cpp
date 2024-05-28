#include "tower1.h"

Tower1::Tower1(QWidget *parent, Player *player)
    : AbstractTower(parent, player)
{
    // Customize initialization if needed
}

Tower1::~Tower1()
{
    // Clean up
}

void Tower1::displayTower()
{
    if (towerLevel == 0) {
        towerLabel->setPixmap(QPixmap(":/assets/img/Hammer1.png"));
    }
    else if (towerLevel == 1) {
        towerLabel->setPixmap(QPixmap(":/assets/img/Tower1.png"));
    } else if (towerLevel == 2) {
        towerLabel->setPixmap(QPixmap(":/assets/img/Tower2.png"));
    } else if (towerLevel == 3) {
        towerLabel->setPixmap(QPixmap(":/assets/img/Tower3.png"));
    }
}

// Repeat similar structure for Tower2 and Tower3
