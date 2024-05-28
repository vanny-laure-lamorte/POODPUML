#include "towermanager.h"

TowerManager::TowerManager(QWidget *parent, Player *player)
    : QWidget(parent), player(player)
{
    tower1 = new Tower1(this, player);
    tower2 = new Tower2(this, player);
    tower3 = new Tower3(this, player);

    // Layout management, positioning of towers if necessary
}

TowerManager::~TowerManager()
{
    delete tower1;
    delete tower2;
    delete tower3;
}
