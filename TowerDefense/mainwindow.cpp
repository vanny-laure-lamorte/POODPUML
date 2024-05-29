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

    // Set initial gold display
    updateGoldLabel(player->getGold());
    // Initialize the Tower object
    tower = new Tower(this, player); // Ensure `this` is passed to access UI elements


    //LANE1

    //Monster Green
    Monster *monster1 = new Monster(":/assets/img/monster1.png", ui->pageGame, x = 100, y = 270, 1);
    monster1->initialPosition(x, y); // Initial position
    monster1->moveSpeed(980); // Speed
    monsters.append(monster1);

    Monster *monster2 = new Monster(":/assets/img/monster1.png", ui->pageGame, x = 100, y = 305, 1);
    monster2->initialPosition(x, y);
    monster2->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster2);

    Monster *monster3 = new Monster(":/assets/img/monster1.png", ui->pageGame, x= 50, y = 270, 1);
    monster3->initialPosition(x, y);
    monster3->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster3);

    // Monster men
    Monster *monster4 = new Monster(":/assets/img/monster2.png", ui->pageGame, x = 40, y = 300, 1);
    monster4->initialPosition(x, y);
    monster4->moveSpeed(980); // Speed in milliseconds
    monsters.append(monster4);

    Monster *monster5 = new Monster(":/assets/img/monster2.png", ui->pageGame, x = 70, y = 290, 1);
    monster5->initialPosition(x, y);
    monster5->moveSpeed(500); // Speed in milliseconds
    monsters.append(monster5);

    // Monster Bat
    Monster *monster6 = new Monster(":/assets/img/monster4.png", ui->pageGame,x= 100, y = 270, 1);
    monster6->initialPosition(x, y);
    monster6->moveSpeed(100); // Speed in milliseconds
    monsters.append(monster6);

    Monster *monster7 = new Monster(":/assets/img/monster4.png", ui->pageGame, x = 100, y = 300, 1);
    monster7->initialPosition(x, y);
    monster7->moveSpeed(80); // Speed in milliseconds
    monsters.append(monster7);

    //LANE2
    Monster *monster11 = new Monster(":/assets/img/monster11.png", ui->pageGame, x = 1140, y = 0, 2);
    monster11->initialPosition(x, y);
    monster11->moveSpeed(100);
    monsters.append(monster11);

    Monster *monster12 = new Monster(":/assets/img/monster12.png", ui->pageGame, x = 1150, y = 0, 2);
    monster12->initialPosition(x, y);
    monster12->moveSpeed(70);
    monsters.append(monster12);

    Monster *monster13 = new Monster(":/assets/img/monster13.png", ui->pageGame, x= 1170, y = 0, 2);
    monster13->initialPosition(x, y);
    monster13->moveSpeed(50);
    monsters.append(monster13);

    Monster *monster14 = new Monster(":/assets/img/monster14.png", ui->pageGame, x = 1150, y = 2, 2);
    monster14->initialPosition(x, y);
    monster14->moveSpeed(50);
    monsters.append(monster14);

    Monster *monster15 = new Monster(":/assets/img/monster15.png", ui->pageGame, x= 1165, y = 50, 2);
    monster15->initialPosition(x, y);
    monster15->moveSpeed(50);
    monsters.append(monster15);

    //LANE3
    Monster *monster21 = new Monster(":/assets/img/monster21.png", ui->pageGame,x= 1485, y = 290, 3);
    monster21->initialPosition(x, y);
    monster21->moveSpeed(70);
    monsters.append(monster21);

    Monster *monster22 = new Monster(":/assets/img/monster22.png", ui->pageGame, x =1495, y = 310, 3);
    monster22->initialPosition(x, y);
    monster22->moveSpeed(60);
    monsters.append(monster22);

    Monster *monster23 = new Monster(":/assets/img/monster23.png", ui->pageGame, x =1510, y = 305, 3);
    monster23->initialPosition(x, y);
    monster23 ->moveSpeed(70);
    monsters.append(monster23);

    Monster *monster24 = new Monster(":/assets/img/monster23.png", ui->pageGame, x =1510, y = 315, 3);
    monster24->initialPosition(x, y);
    monster24 ->moveSpeed(70);
    monsters.append(monster24);

    Monster *monster25 = new Monster(":/assets/img/monster23.png", ui->pageGame, x =1480, y = 300, 3);
    monster25->initialPosition(x, y);
    monster25->moveSpeed(70);
    monsters.append(monster22);

    // Show all monsters
    for (Monster *monster : as_const(monsters)) {
        monster->show();
    }

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
