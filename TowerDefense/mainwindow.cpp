#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    // Initialize the Monster object
    monster = new Monster(ui->pageGame);
    monster->move(100, 270); // Position initiale du monstre
    monster -> show();
    connect(ui->pushButtonMonster, &QPushButton::clicked, this, &MainWindow::moveMonster);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tower; // Delete the tower instance
    delete monster;
}

void MainWindow::showGamePage()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
    monster->show();
}

void MainWindow::showMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
}

void MainWindow::moveMonster()
{
    if (ui->stackedWidget->currentWidget() != ui->pageGame) {
        ui->stackedWidget->setCurrentWidget(ui->pageGame);
    }

    static int x = 100;
    static int y = 270; // Start from the initial position

    x += 10;
    y += 10;

    monster->moveMonster(x, y);
}
