#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "tower.h"
#include "player.h"

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

private:
    Ui::MainWindow *ui;
    Tower *tower;
    Player *player;
};

#endif // MAINWINDOW_H
