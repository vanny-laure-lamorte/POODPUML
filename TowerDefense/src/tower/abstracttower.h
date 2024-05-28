#ifndef ABSTRACTTOWER_H
#define ABSTRACTTOWER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "../../player.h"

             class AbstractTower : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractTower(QWidget *parent = nullptr, Player *player = nullptr);
    virtual ~AbstractTower();

    void showUpgradeShop();
    void hideUpgradeShop();

protected:
    virtual void displayTower() = 0;

protected slots:
    void onUpgrade1Clicked();
    void onUpgrade2Clicked();
    void onUpgrade3Clicked();

protected:
    QPushButton *towerButton;
    QLabel *towerLabel;
    QLabel *upgradeShopLabel;
    QPushButton *towerUpgrade1;
    QPushButton *towerUpgrade2;
    QPushButton *towerUpgrade3;
    Player *player;
    int towerLevel;
};

#endif // ABSTRACTTOWER_H
