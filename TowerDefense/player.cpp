#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
}

int Player::getGold() const
{
    return gold;
}

void Player::setGold(int value)
{
    if (gold != value) {
        gold = value;
        emit goldChanged(gold);
    }
}
