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
    void ontowerUpgrade1_1Clicked();
    void ontowerUpgrade1_2Clicked();
    void ontowerUpgrade1_3Clicked();

    void onTowerButton2Clicked();
    void ontowerUpgrade2_1Clicked();
    void ontowerUpgrade2_2Clicked();
    void ontowerUpgrade2_3Clicked();
private:
    void displayTower();

    QPushButton *towerButton1;
    QLabel *tower1;
    QLabel *upgradeShop1;
    QPushButton *towerUpgrade1_1;
    QPushButton *towerUpgrade1_2;
    QPushButton *towerUpgrade1_3;

    QPushButton *towerButton2;
    QLabel *tower2;
    QLabel *upgradeShop2;
    QPushButton *towerUpgrade2_1;
    QPushButton *towerUpgrade2_2;
    QPushButton *towerUpgrade2_3;

    Player *player;
    int tower1Level;
    int tower2Level;
};

#endif // TOWER_H
