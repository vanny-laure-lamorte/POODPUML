#ifndef TOWER_H
#define TOWER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "player.h"

class Tower : public QWidget
{
    Q_OBJECT

public:
    explicit Tower(QWidget *parent = nullptr, Player *player = nullptr);
    ~Tower();

private slots:
    void onTowerButton1Clicked();
    void ontowerUpgrade1Clicked();
    void ontowerUpgrade2Clicked();
    void ontowerUpgrade3Clicked();

private:
    void displayTower();

    QPushButton *towerButton1;
    QLabel *tower1;
    QLabel *upgradeShop1;
    QPushButton *towerUpgrade1;
    QPushButton *towerUpgrade2;
    QPushButton *towerUpgrade3;
    Player *player;
    int towerLevel;
};

#endif // TOWER_H
