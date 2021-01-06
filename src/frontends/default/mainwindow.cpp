#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_pauseplay_released()
{
    this->findChild<QLineEdit*>("lineEdit")->setText("Play");
}

void MainWindow::on_btn_stop_released()
{
    this->findChild<QLineEdit*>("lineEdit")->setText("Stop");
}

void MainWindow::on_btn_record_released()
{
    this->findChild<QLineEdit*>("lineEdit")->setText("Record");
}
