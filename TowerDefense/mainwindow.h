#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>


#include "tower.h"
#include "monster.h"

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
    void moveMonsters();

private:
    Ui::MainWindow *ui;
    Tower *tower; // Moved tower declaration to the private section
    QVector<Monster*> monsters;
};

#endif // MAINWINDOW_H
