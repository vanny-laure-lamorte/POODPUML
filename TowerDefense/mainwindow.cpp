#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tower Defense");

    connect(ui->buttonGame, &QPushButton::clicked, this, &MainWindow::showGamePage);
    connect(ui->buttonMenu, &QPushButton::clicked, this, &MainWindow::showMenuPage);

    ui->stackedWidget->setCurrentWidget(ui->pageMenu);

    // Initialize the Tower object
    tower = new Tower(this); // Ensure `this` is passed to access UI elements

    // Initialize the Tower object
    tower = new Tower(this);

    Monster *monster1 = new Monster(":/assets/img/monster1.png", ui->pageGame);
    monster1->move(100, 270); // Initial position of the monster
    monster1->moveSpeed(1000); // Speed in milliseconds
    monsters.append(monster1);

    Monster *monster2 = new Monster(":/assets/img/monster1.png", ui->pageGame);
    monster2->move(200, 270); // Initial position of the monster
    monster2->moveSpeed(800); // Speed in milliseconds
    monsters.append(monster2);

    Monster *monster3 = new Monster(":/assets/img/monster.png", ui->pageGame);
    monster3->move(300, 270); // Initial position of the monster
    monster3->moveSpeed(1200); // Speed in milliseconds
    monsters.append(monster3);

    // Show all monsters
    for (Monster *monster : as_const(monsters)) {
        monster->show();
    }

    connect(ui->pushButtonMonster, &QPushButton::clicked, this, &MainWindow::moveMonsters);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tower; // Delete the tower instance
    qDeleteAll(monsters); // Delete all monsters
}

void MainWindow::showGamePage()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
    for (Monster *monster : as_const(monsters)) {
        monster->show();
    }
}

void MainWindow::showMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
}

void MainWindow::moveMonsters()
{
    if (ui->stackedWidget->currentWidget() != ui->pageGame) {
        ui->stackedWidget->setCurrentWidget(ui->pageGame);
    }

    for (Monster *monster : as_const(monsters)) {
        monster->moveMonster();
    }

}
