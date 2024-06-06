#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT

public:
    explicit Player(QObject *parent = nullptr);
    int getGold() const;
    void setGold(int value);

    int getLife() const;
    void setLife(int value);
    bool gameOver = false;

signals:
    void goldChanged(int newGold);
    void lifeChanged(int newLife);

private:
    int gold = 400;
    int life = 10;  // Example initial value for life
};

#endif // PLAYER_H
