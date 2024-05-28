#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <QWidget>
#include "tower1.h"
#include "tower2.h"
#include "tower3.h"

class TowerManager : public QWidget
{
    Q_OBJECT

public:
    explicit TowerManager(QWidget *parent = nullptr, Player *player = nullptr);
    ~TowerManager();

private:
    Tower1 *tower1;
    Tower2 *tower2;
    Tower3 *tower3;
    Player *player;
};

#endif // TOWERMANAGER_H
