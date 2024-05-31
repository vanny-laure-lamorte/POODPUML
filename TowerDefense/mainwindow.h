#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

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

private:
    Player *player;
    void moveMonsters();

    int x = 0, y = 0 ;

    Ui::MainWindow *ui;
    Tower *tower; // Moved tower declaration to the private section
    Music *music;
    QVector<Monster*> monsters;
};

#endif // MAINWINDOW_H
