#ifndef TOWER2_H
#define TOWER2_H

#include "abstracttower.h"

class Tower2 : public AbstractTower
{
    Q_OBJECT

public:
    explicit Tower2(QWidget *parent = nullptr, Player *player = nullptr);
    ~Tower2();

protected:
    void displayTower() override;
};

#endif // TOWER1_H
