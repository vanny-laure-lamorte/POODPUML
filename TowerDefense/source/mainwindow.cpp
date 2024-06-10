#include "../include/mainwindow.h"
#include "ui_mainwindow.h"


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
    connect(ui->buttonRules, &QPushButton::clicked, this, &MainWindow::showRulePage);
    connect(ui->backToMenu, &QPushButton::clicked, this, &MainWindow::showMenuPage);

    //
    connect(ui->buttonExit, SIGNAL(clicked()), this, SLOT(close()));

    ui->stackedWidget->setCurrentWidget(ui->pageMenu);

    // Initialize the Player object
    player = new Player(this);

    connect(player, &Player::goldChanged, this, &MainWindow::updateGoldLabel);
    connect(player, &Player::lifeChanged, this, &MainWindow::updateLifeLabel);

    updateGoldLabel(player->getGold());
    updateLifeLabel(player->getLife());

    // Initialize the Tower object
    tower = new Tower(this, player);

    monsters = Monster::generateMonsters(ui->pageGame, player);
    attackTimer = new QTimer(this);
    attackTimer->start(1000);
    blinkTimer = new QTimer(this);
    blinkTimer->setInterval(100); // Blink interval (milliseconds)
    connect(blinkTimer, &QTimer::timeout, this, &MainWindow::blinkBaseAttacked);

    baseAttacked = ui->pageGame->findChild<QLabel*>("baseAttacked");

    baseAttacked->setVisible(false);

    connect(attackTimer, &QTimer::timeout, this, &MainWindow::attack);

    resizeImage = new QTimer(this);
    connect(resizeImage, &QTimer::timeout, this, &MainWindow::resizeGameOverImage);

    gameOverimage = QPixmap(":/assets/img/gameOver.png");
    gameOverLabel = new QLabel(this);
    gameOverLabel->setPixmap(gameOverimage.scaled(imageX, imageY, Qt::KeepAspectRatio));
    gameOverLabel->setVisible(false);

    // Position the gameOverLabel at the center of the window (adjust as needed)
    gameOverLabel->move(750 - imageX / 2, 375 - imageY / 2);

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
    delete tower;
    delete player;
    qDeleteAll(monsters);
    delete music;
}

void MainWindow::showGamePage()
{
    for (Monster *monster : monsters) {
        monster->show();
    }
    music->play();
    ui->stackedWidget->setCurrentWidget(ui->pageGame);

    if (!gameLaunched) {
        for (Monster *monster : monsters) {
            monster->initializeTimers();
        }
        gameLaunched = true;
        menuLaunched = false;
    }
}

void MainWindow::showMenuPage()
{
    music->pause();
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    if(!menuLaunched){
        gameLaunched = false;
        menuLaunched = true;
    }
}

void MainWindow::showRulePage(){
    ui->stackedWidget->setCurrentWidget(ui->pageRule);
}

void MainWindow::updateGoldLabel(int newGold)
{
    ui->labelGold->setStyleSheet("font-size: 20px; color: black;font-weight: 800");
    ui->labelGold->setText(QString::number(newGold));
}

void MainWindow::updateLifeLabel(int newLife)
{
    ui->labelLife->setStyleSheet("font-size: 20px; color: black; font-weight: 800");
    ui->labelLife->setText(QString::number(newLife));
}

void MainWindow::attack(){
    int monsterAttacking = 0;
    for (Monster *monster : monsters) {
        if (player->getLife() > 0) {
            if (monster->attacking) {
                monsterAttacking ++;

            }
        } else {
            if (!player->gameOver) {
                player->gameOver = true;
                monsterAttacking = 0;
            }
            if (!menuLaunched){
                gameOverLabel->setVisible(true);
                resizeImage->start(3);
            }
            else
                gameOverLabel->setVisible(false);
        }
    }
    player->setLife(player->getLife() - monsterAttacking);
    if (monsterAttacking > 0)
        blinkTimer->start();
    else{
        baseAttacked->setVisible(false);
        blinkTimer->stop();
    }
}

void MainWindow::resizeGameOverImage()
{
    if (imageX < 700) {
        imageX += 1;  // Adjust the increment as needed
        imageY += 1;  // Adjust the increment as needed
        gameOverLabel->move(750 - imageX / 2, 375 - imageY / 2);
        gameOverLabel->setPixmap(gameOverimage.scaled(imageX, imageY, Qt::KeepAspectRatio));
        gameOverLabel->resize(imageX, imageY);
    } else {
        resizeImage->stop();
    }
}

void MainWindow::blinkBaseAttacked()
{
    if (!player->gameOver){
        if (baseAttacked->isVisible()) {
            baseAttacked->setVisible(false);
        } else {
            baseAttacked->setVisible(true);
        }
    }
}
