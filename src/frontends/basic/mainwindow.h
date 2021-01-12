#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../common/gui_events.hpp"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void set_event_list(std::vector<events::MainControls> &events_to_extern);

private:
  Ui::MainWindow *ui;
  std::vector<events::MainControls> *event_list;

private slots:
  void release_playpause();
  void release_stop();
  void release_record();
};
#endif // MAINWINDOW_H
