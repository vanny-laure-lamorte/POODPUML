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

signals:
    void goldChanged(int newGold);

private:
    int gold = 500;
};

#endif // PLAYER_H
