// Tower.cpp

#include "tower.h"

Tower::Tower(QWidget *parent, Player *player)
    : QWidget(parent), player(player)
{
    // Accessing existing buttons and labels from the UI designer
    towerButton1 = parent->findChild<QPushButton*>("towerButton1");
    tower1 = parent->findChild<QLabel*>("tower1");

    upgradeShop1 = parent->findChild<QLabel*>("upgradeShop1");
    towerUpgrade1 = parent->findChild<QPushButton*>("towerUpgrade1");
    towerUpgrade2 = parent->findChild<QPushButton*>("towerUpgrade2");
    towerUpgrade3 = parent->findChild<QPushButton*>("towerUpgrade3");

    // Initially hide the upgrade shop and buttons
    towerUpgrade1->setVisible(false);
    towerUpgrade2->setVisible(false);
    towerUpgrade3->setVisible(false);
    upgradeShop1->setVisible(false);

    // Connect button click to the slot
    connect(towerButton1, &QPushButton::clicked, this, &Tower::onTowerButton1Clicked);
    connect(towerUpgrade1, &QPushButton::clicked, this, &Tower::ontowerUpgrade1Clicked);
    connect(towerUpgrade2, &QPushButton::clicked, this, &Tower::ontowerUpgrade2Clicked);
    connect(towerUpgrade3, &QPushButton::clicked, this, &Tower::ontowerUpgrade3Clicked);
    displayTower();
}

Tower::~Tower()
{
    // Clean up
}

void Tower::onTowerButton1Clicked()
{
    // Toggle visibility of the upgrade shop and buttons
    bool newVisibility = !upgradeShop1->isVisible();
    upgradeShop1->setVisible(newVisibility);
    towerUpgrade1->setVisible(newVisibility);
    towerUpgrade2->setVisible(newVisibility);
    towerUpgrade3->setVisible(newVisibility);

    // Optional: add animation for showing/hiding
}

void Tower::ontowerUpgrade1Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 1;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::ontowerUpgrade2Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 2;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::ontowerUpgrade3Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 3;
        displayTower();
        upgradeShop1->setVisible(false);
    }
}

void Tower::displayTower()
{
    if (towerLevel == 0) {
        tower1->setPixmap(QPixmap(":/assets/img/Hammer1.png"));
    }
    else if (towerLevel == 1) {
        tower1->setPixmap(QPixmap(":/assets/img/Tower1.png"));
    } else if (towerLevel == 2) {
            tower1->setPixmap(QPixmap(":/assets/img/Tower2.png"));
    } else if (towerLevel == 3) {
            tower1->setPixmap(QPixmap(":/assets/img/Tower3.png"));
    }
}
