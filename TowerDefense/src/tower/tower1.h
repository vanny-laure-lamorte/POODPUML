#ifndef TOWER1_H
#define TOWER1_H

#include "abstracttower.h"

class Tower1 : public AbstractTower
{
    Q_OBJECT

public:
    explicit Tower1(QWidget *parent = nullptr, Player *player = nullptr);
    ~Tower1();

protected:
    void displayTower() override;
};

#endif // TOWER1_H
