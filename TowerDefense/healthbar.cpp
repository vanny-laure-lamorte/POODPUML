#include "healthbar.h"
#include <QPainter>

HealthBar::HealthBar(QWidget *parent) : QWidget(parent), health(100) {
    setFixedSize(50, 6);
}

void HealthBar::setHealth(int newHealth) {
    health = newHealth;
    update(); // Redessine le widget
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::green);
    int healthWidth = static_cast<int>((static_cast<float>(health) / 100.0f) * width());
    painter.drawRect(0, 0, healthWidth, height());
}
