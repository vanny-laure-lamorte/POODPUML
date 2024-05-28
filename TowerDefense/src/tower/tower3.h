#ifndef TOWER3_H
#define TOWER3_H

#include "abstracttower.h"

class Tower3 : public AbstractTower
{
    Q_OBJECT

public:
    explicit Tower3(QWidget *parent = nullptr, Player *player = nullptr);
    ~Tower3();

protected:
    void displayTower() override;
};

#endif // TOWER1_H
