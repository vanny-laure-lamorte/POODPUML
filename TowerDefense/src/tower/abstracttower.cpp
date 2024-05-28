#include "abstracttower.h"

AbstractTower::AbstractTower(QWidget *parent, Player *player)
    : QWidget(parent), player(player), towerLevel(0)
{
    // Accessing existing buttons and labels from the UI designer
    towerButton = parent->findChild<QPushButton*>("towerButton");
    towerLabel = parent->findChild<QLabel*>("towerLabel");

    upgradeShopLabel = parent->findChild<QLabel*>("upgradeShopLabel");
    towerUpgrade1 = parent->findChild<QPushButton*>("towerUpgrade1");
    towerUpgrade2 = parent->findChild<QPushButton*>("towerUpgrade2");
    towerUpgrade3 = parent->findChild<QPushButton*>("towerUpgrade3");

    // Initially hide the upgrade shop and buttons
    towerUpgrade1->setVisible(false);
    towerUpgrade2->setVisible(false);
    towerUpgrade3->setVisible(false);
    upgradeShopLabel->setVisible(false);

    // Connect button click to the slot
    connect(towerButton, &QPushButton::clicked, [this](){
        bool newVisibility = !upgradeShopLabel->isVisible();
        upgradeShopLabel->setVisible(newVisibility);
        towerUpgrade1->setVisible(newVisibility);
        towerUpgrade2->setVisible(newVisibility);
        towerUpgrade3->setVisible(newVisibility);
    });
    connect(towerUpgrade1, &QPushButton::clicked, this, &AbstractTower::onUpgrade1Clicked);
    connect(towerUpgrade2, &QPushButton::clicked, this, &AbstractTower::onUpgrade2Clicked);
    connect(towerUpgrade3, &QPushButton::clicked, this, &AbstractTower::onUpgrade3Clicked);
}

AbstractTower::~AbstractTower()
{
    // Clean up
}

void AbstractTower::onUpgrade1Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 1;
        displayTower();
        hideUpgradeShop();
    }
}

void AbstractTower::onUpgrade2Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 2;
        displayTower();
        hideUpgradeShop();
    }
}

void AbstractTower::onUpgrade3Clicked()
{
    if (player->getGold() >= 100) {
        player->setGold(player->getGold() - 100);
        towerLevel = 3;
        displayTower();
        hideUpgradeShop();
    }
}

void AbstractTower::showUpgradeShop()
{
    upgradeShopLabel->setVisible(true);
    towerUpgrade1->setVisible(true);
    towerUpgrade2->setVisible(true);
    towerUpgrade3->setVisible(true);
}

void AbstractTower::hideUpgradeShop()
{
    upgradeShopLabel->setVisible(false);
    towerUpgrade1->setVisible(false);
    towerUpgrade2->setVisible(false);
    towerUpgrade3->setVisible(false);
}
