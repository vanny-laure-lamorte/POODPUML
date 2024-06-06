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

int Player::getLife() const
{
    return life;
}

void Player::setLife(int value)
{
    if (life != value) {
        life = value;
        emit lifeChanged(life);
        if (life <= 0) {
            gameOver = true;
        }
    }
}
