#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <cmath>

class HealthBar : public QWidget {
    Q_OBJECT

public:
    HealthBar(QWidget *parent = nullptr);
    void setHealth(int newHealth);
    void updatePosition(int x, int y);
    void applyDamage();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int health;
    int monsterPosX;
    int monsterPosY;
};

#endif // HEALTHBAR_H
