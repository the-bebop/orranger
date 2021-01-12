#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    event_list->push_back(events::QUIT);
    delete ui;
}

void MainWindow::set_event_list(std::vector<events::MainControls> &events_to_extern)
{
    event_list = &events_to_extern;
}

void MainWindow::release_playpause()
{
    this->ui->lineEdit->setText("Play");
    event_list->push_back(events::PLAY);
    printf("Try ssThis!\n");
}

void MainWindow::release_stop()
{
    this->ui->lineEdit->setText("Stop");
    event_list->push_back(events::STOP);
}

void MainWindow::release_record()
{
    this->ui->lineEdit->setText("Record");
    event_list->push_back(events::RECORD);
}
