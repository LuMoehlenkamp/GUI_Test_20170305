#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <wiringPi.h>
#include <QTimer>
#include <QPainter>
#include <QGridLayout>
#include <sys/time.h>

#include "GPIO_class.h"
#include "PaintHelper.h"
#include "Widget.h"
#include "XmlReader.h"
#include "ClockApi.h"

#include "QxmlTest.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow, public Ui::MainWindow{
  Q_OBJECT
  int count;
  int WiringPiSetupRes;
  int PinExportRes;
  Ui::MainWindow *ui;

  GPIO_class GPIO_1;
  void Increment(int& a);

  PaintHelper paintHelper;
  // ClockApi clockApi;

  QxmlTest xmlTest;

public:
  MainWindow(QMainWindow *parent = 0);
  ~MainWindow();


private slots:
  void TimerSlot();
};

#endif // MAINWINDOW_H
