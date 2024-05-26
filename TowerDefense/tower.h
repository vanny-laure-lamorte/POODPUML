#ifndef TOWER_H
#define TOWER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>

class Tower : public QWidget
{
    Q_OBJECT

public:
    explicit Tower(QWidget *parent = nullptr);
    ~Tower();

private slots:
    void onTowerButton1Clicked();
    void ontowerUpgrade1Clicked();
    void ontowerUpgrade2Clicked();
    void ontowerUpgrade3Clicked();

private:
    bool tower_visible = false;
    int towerLevel = 0;

    QPushButton *towerButton1;
    QLabel *tower1;

    QPushButton *towerUpgrade1;
    QPushButton *towerUpgrade2;
    QPushButton *towerUpgrade3;
    QLabel *upgradeShop1;

    QPropertyAnimation *animation;

    void displayTower();
};

#endif // TOWER_H
