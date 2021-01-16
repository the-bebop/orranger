#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <backend/reactor/hpp/moderator.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  moderator->set_event(events::QUIT);
  delete ui;
}

void MainWindow::set_event_list(moderator::Moderator &reactor_moderator) {
  moderator = &reactor_moderator;
}

void MainWindow::release_playpause() {
  this->ui->lineEdit->setText("Play");
  moderator->set_event(events::PLAY);
}

void MainWindow::release_stop() {
  this->ui->lineEdit->setText("Stop");
  moderator->set_event(events::STOP);
}

void MainWindow::release_record() {
  this->ui->lineEdit->setText("Record");
  moderator->set_event(events::RECORD);
}
