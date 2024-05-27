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

    // Initialize multiple Monster objects
    for (int i = 0; i < 5; ++i) { // Ceate 5 monsters
        Monster *monster = new Monster(ui->pageGame);
        monster->move(100 + i * 60, 270); // Adjust the initial positions to not overlap
        monster->show();
        monsters.append(monster);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveMonsters);
    timer->start(100); // Move monsters every 100 ms

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
        static int dx = 10; // Increment for x position
        static int dy = 0;  // Increment for y position
        int x = monster->x() + dx;
        int y = monster->y() + dy;
        monster->moveMonster(x, y);
    }


}
