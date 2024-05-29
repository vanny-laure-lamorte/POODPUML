#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>

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

    // Initialize the Player object
    player = new Player(this);

    connect(player, &Player::goldChanged, this, &MainWindow::updateGoldLabel);
    connect(player, &Player::lifeChanged, this, &MainWindow::updateLifeLabel);

    updateGoldLabel(player->getGold());
    updateLifeLabel(player->getLife());


    // Initialize the Tower object
    tower = new Tower(this, player); // Ensure `this` is passed to access UI elements

    //Monster Green
    Monster *monster1 = new Monster(":/assets/img/monster1.png", ui->pageGame, x = 100, y = 270);
    monster1->initialPosition(x, y); // Initial position
    monster1->moveSpeed(980); // Speed
    monsters.append(monster1);

    Monster *monster2 = new Monster(":/assets/img/monster1.png", ui->pageGame, x = 100, y = 305);
    monster2->initialPosition(x, y);
    monster2->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster2);

    Monster *monster3 = new Monster(":/assets/img/monster1.png", ui->pageGame, x= 50, y = 270);
    monster3->initialPosition(x, y);
    monster3->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster3);

    // Monster men
    Monster *monster4 = new Monster(":/assets/img/monster2.png", ui->pageGame, x = 40, y = 300);
    monster4->initialPosition(x, y);
    monster4->moveSpeed(980); // Speed in milliseconds
    monsters.append(monster4);

    Monster *monster5 = new Monster(":/assets/img/monster2.png", ui->pageGame, x = 70, y = 290);
    monster5->initialPosition(x, y);
    monster5->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster5);

    // Monster Bat
    Monster *monster6 = new Monster(":/assets/img/monster4.png", ui->pageGame,x= 100, y = 270);
    monster6->initialPosition(x, y);
    monster6->moveSpeed(100); // Speed in milliseconds
    monsters.append(monster6);

    Monster *monster7 = new Monster(":/assets/img/monster4.png", ui->pageGame, x = 100, y = 300);
    monster7->initialPosition(x, y);
    monster7->moveSpeed(80); // Speed in milliseconds
    monsters.append(monster7);

    // Show all monsters
    for (Monster *monster : as_const(monsters)) {
        monster->show();
    }

    //connect(ui->pushButtonMonster, &QPushButton::clicked, this, &MainWindow::moveMonsters);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tower; // Delete the tower instance
    delete player; // Delete the player instance
    qDeleteAll(monsters); // Delete all monsters
}

void MainWindow::showGamePage()
{
    for (Monster *monster : as_const(monsters)) {
        monster->show();
    }
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
}

void MainWindow::showMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
}

void MainWindow::updateGoldLabel(int newGold)
{
    ui->labelGold->setStyleSheet("font-size: 20px; color: black;font-weight: 800"); // Adjust the size as needed
    ui->labelGold->setText(QString::number(newGold));
}

void MainWindow::updateLifeLabel(int newLife)
{
    ui->labelLife->setStyleSheet("font-size: 20px; color: black; font-weight: 800"); // Adjust the size as needed
    ui->labelLife->setText(QString::number(newLife));
}

void MainWindow::moveMonsters()
{
    if (ui->stackedWidget->currentWidget() != ui->pageGame) {
        ui->stackedWidget->setCurrentWidget(ui->pageGame);
    }

    for (Monster *monster : as_const(monsters)) {
        monster->moveMonster();
        qDebug() << "Monster moved: " << monster;
    }

}
