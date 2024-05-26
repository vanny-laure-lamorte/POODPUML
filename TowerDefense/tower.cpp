#include "tower.h"
#include <QPropertyAnimation>

Tower::Tower(QWidget *parent)
    : QWidget(parent)
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

}

void Tower::onTowerButton1Clicked()
{
    // Toggle visibility of the upgrade shop and buttons
    bool newVisibility = !upgradeShop1->isVisible();
    upgradeShop1->setVisible(newVisibility);
    towerUpgrade1->setVisible(newVisibility);
    towerUpgrade2->setVisible(newVisibility);
    towerUpgrade3->setVisible(newVisibility);

}

void Tower::ontowerUpgrade1Clicked()
{
    towerLevel = 1;
    displayTower();
}

void Tower::ontowerUpgrade2Clicked()
{
    towerLevel = 2;
    displayTower();
}

void Tower::ontowerUpgrade3Clicked()
{
    towerLevel = 3;
    displayTower();
}

void Tower::displayTower()
{
    if (towerLevel == 0)
        tower1->setPixmap(QPixmap(":/assets/img/noTower.png"));
    else if (towerLevel == 1)
        tower1->setPixmap(QPixmap(":/assets/img/Tower1.png"));
    else if (towerLevel == 2)
        tower1->setPixmap(QPixmap(":/assets/img/Tower2.png"));
    else if (towerLevel == 3)
        tower1->setPixmap(QPixmap(":/assets/img/Tower3.png"));

}

Tower::~Tower()
{
}
