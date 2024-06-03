#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    music(new Music(this))
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

    monsters = Monster::generateMonsters(ui->pageGame);
    attackTimer = new QTimer(this);
    attackTimer->start(1000);

    connect(attackTimer, &QTimer::timeout, this, &MainWindow::attack);


    // Show all monsters
    for (Monster *monster : monsters) {
        monster->show();
    }

    // Music
    music->pause();
    connect(ui->btnPlay, &QPushButton::clicked, music, &Music::play);
    connect(ui->btnMute, &QPushButton::clicked, music, &Music::pause);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tower; // Delete the tower instance
    delete player; // Delete the player instance
    qDeleteAll(monsters); // Delete all monsters
    delete music; // Delete music
}

void MainWindow::showGamePage()
{
    for (Monster *monster : monsters) {
        monster->show();
    }
    music->play();
    ui->stackedWidget->setCurrentWidget(ui->pageGame);

    if (!gameLaunched) {
        // Initialize timers for each monster
        for (Monster *monster : monsters) {
            monster->initializeTimers();
        }
        gameLaunched = true;
    }
}
void MainWindow::showMenuPage()
{
    music->pause();
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

void MainWindow::attack(){
    for (Monster *monster : monsters) {
        if (monster->attacking){
            player->setLife(player->getLife() - 1);
        }
    }
}
