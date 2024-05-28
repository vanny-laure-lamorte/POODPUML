// Tower.cpp

#include "tower.h"
#include <qdebug.h>

Tower::Tower(QWidget *parent, Player *player)
    : QWidget(parent), player(player)
{
    // ***  First tower
    towerButton1 = parent->findChild<QPushButton*>("towerButton1");
    tower1 = parent->findChild<QLabel*>("tower1");
    tower1->setPixmap(QPixmap(":/assets/img/Hammer1.png"));

    upgradeShop1 = parent->findChild<QLabel*>("upgradeShop1");
    towerUpgrade1_1 = parent->findChild<QPushButton*>("towerUpgrade1_1");
    towerUpgrade1_2 = parent->findChild<QPushButton*>("towerUpgrade1_2");
    towerUpgrade1_3 = parent->findChild<QPushButton*>("towerUpgrade1_3");

    // Initially hide the upgrade shop and buttons
    towerUpgrade1_1->setVisible(false); towerUpgrade1_2->setVisible(false); towerUpgrade1_3->setVisible(false); upgradeShop1->setVisible(false);

    // Connect button click to the slot
    connect(towerButton1, &QPushButton::clicked, this, &Tower::onTowerButton1Clicked);
    connect(towerUpgrade1_1, &QPushButton::clicked, this, &Tower::ontowerUpgrade1_1Clicked);
    connect(towerUpgrade1_2, &QPushButton::clicked, this, &Tower::ontowerUpgrade1_2Clicked);
    connect(towerUpgrade1_3, &QPushButton::clicked, this, &Tower::ontowerUpgrade1_3Clicked);

    // ***  Second tower
    towerButton2 = parent->findChild<QPushButton*>("towerButton2");
    tower2 = parent->findChild<QLabel*>("tower2");
    tower2->setPixmap(QPixmap(":/assets/img/Hammer1.png"));

    upgradeShop2 = parent->findChild<QLabel*>("upgradeShop2");
    towerUpgrade2_1 = parent->findChild<QPushButton*>("towerUpgrade2_1");
    towerUpgrade2_2 = parent->findChild<QPushButton*>("towerUpgrade2_2");
    towerUpgrade2_3 = parent->findChild<QPushButton*>("towerUpgrade2_3");
    towerUpgrade2_1->setVisible(false); towerUpgrade2_2->setVisible(false); towerUpgrade2_3->setVisible(false); upgradeShop2->setVisible(false);

    // Connect button click to the slot
    connect(towerButton2, &QPushButton::clicked, this, &Tower::onTowerButton2Clicked);
    connect(towerUpgrade2_1, &QPushButton::clicked, this, &Tower::ontowerUpgrade2_1Clicked);
    connect(towerUpgrade2_2, &QPushButton::clicked, this, &Tower::ontowerUpgrade2_2Clicked);
    connect(towerUpgrade2_3, &QPushButton::clicked, this, &Tower::ontowerUpgrade2_3Clicked);

    displayTower();

}

Tower::~Tower()
{
    // Clean up
}

// *** Base tower, display
void Tower::onTowerButton1Clicked()
{
    // Toggle visibility of the upgrade shop and buttons
    bool newVisibility = !upgradeShop1->isVisible();
    upgradeShop1->setVisible(newVisibility);
    upgradeShop2->setVisible(false);

}

void Tower::onTowerButton2Clicked()
{
    // Toggle visibility of the upgrade shop and buttons
    bool newVisibility = !upgradeShop2->isVisible();
    upgradeShop2->setVisible(newVisibility);
    upgradeShop1->setVisible(false);

}

void Tower::ontowerUpgrade1_1Clicked()
{

    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower1Level = 1;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::ontowerUpgrade1_2Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower1Level = 2;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::ontowerUpgrade1_3Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower1Level = 3;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::ontowerUpgrade2_1Clicked()
{

    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower2Level = 1;
        displayTower();
        upgradeShop2->setVisible(false);
    }
}

void Tower::ontowerUpgrade2_2Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower2Level = 2;
        displayTower();
        upgradeShop2->setVisible(false);
    }
}

void Tower::ontowerUpgrade2_3Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        tower2Level = 3;
        displayTower();
        upgradeShop2->setVisible(false);
    }
}

void Tower::displayTower()
{
    if (tower1Level == 0) {
        tower1->setPixmap(QPixmap(":/assets/img/Hammer1.png"));
    }
    else if (tower1Level == 1) {
        tower1->setPixmap(QPixmap(":/assets/img/Tower1.png"));
    } else if (tower1Level == 2) {
            tower1->setPixmap(QPixmap(":/assets/img/Tower2.png"));
    } else if (tower1Level == 3) {
            tower1->setPixmap(QPixmap(":/assets/img/Tower3.png"));
    }
    if (tower2Level == 0) {
        tower2->setPixmap(QPixmap(":/assets/img/Hammer1.png"));
    }
    else if (tower2Level == 1) {
        tower2->setPixmap(QPixmap(":/assets/img/Tower1.png"));
    } else if (tower2Level == 2) {
        tower2->setPixmap(QPixmap(":/assets/img/Tower2.png"));
    } else if (tower2Level == 3) {
        tower2->setPixmap(QPixmap(":/assets/img/Tower3.png"));
    }
}
