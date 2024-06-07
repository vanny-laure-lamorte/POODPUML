#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <QPainter>
#include <QList>
#include <QTimer>

class HealthBar : public QWidget {
    Q_OBJECT

public:
    explicit HealthBar(QWidget *parent = nullptr, int health = 100, int monsterPosX = 0, int monsterPosY = 0);
    void setHealth(int newHealth);
    void updatePosition(int x, int y);

public slots:
    void applyDamageToClosest();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int health;
    int monsterPosX;
    int monsterPosY;
    static QList<HealthBar*> healthbarList; // Static list to track all health bars
    QTimer *damageTimer; // Static timer for periodic damage
};

#endif // HEALTHBAR_H
