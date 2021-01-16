#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <backend/reactor/hpp/moderator.hpp>
#include <frontends/common/gui_events.hpp>

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

  void set_event_list(moderator::Moderator &reactor_moderator);

private:
  Ui::MainWindow *ui;
  moderator::Moderator *moderator;

private slots:
  void release_playpause();
  void release_stop();
  void release_record();
};
#endif // MAINWINDOW_H
