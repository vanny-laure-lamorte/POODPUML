#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Tower Defense");

    // Uncomment the following line if you want to set a background image
    // this->setStyleSheet("background-image: url(:/assets/img/homeBackground.jpg); background-repeat: no-repeat; background-position: center;");

    connect(ui->buttonGame, &QPushButton::clicked, this, &MainWindow::showGamePage);
    connect(ui->buttonMenu, &QPushButton::clicked, this, &MainWindow::showMenuPage);

    // Set the initial page to the menu page
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showGamePage() {
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
}

void MainWindow::showMenuPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
}
