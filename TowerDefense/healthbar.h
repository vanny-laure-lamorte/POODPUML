#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>

class HealthBar : public QWidget {
    Q_OBJECT

public:
    explicit HealthBar(QWidget *parent = nullptr);
    void setHealth(int newHealth);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int health;
};

#endif // HEALTHBAR_H
