#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QDebug>

#include "tower.h"
#include "player.h"
#include "monster.h"
#include "music.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showMenuPage();
    void showGamePage();
    void updateGoldLabel(int newGold);
    void updateLifeLabel(int newLife);
    void attack();

    void resizeGameOverImage();
    void blinkBaseAttacked();

private:
    Player *player;

    int x = 0, y = 0 ;

    Ui::MainWindow *ui;
    Tower *tower;
    Music *music;
    QVector<Monster*> monsters;
    bool gameLaunched = false;
    QTimer *attackTimer;
    QTimer *blinkTimer;

    QLabel *baseAttacked;

    QLabel *gameOverLabel;
    QPixmap gameOverimage;
    QTimer *resizeImage;
    int imageX = 50;
    int imageY = 28;
};

#endif // MAINWINDOW_H
