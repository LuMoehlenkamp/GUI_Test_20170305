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
#include "QxmlTest.h"
#include "modbus/modbus-tcp.h"

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
  PaintHelper paintHelper;
  QxmlTest xmlTest;
  modbus_t *ctx;
  int modResult;
  void Increment(int& a);
  u_int16_t storage [8];

public:
  MainWindow(QMainWindow *parent = 0);
  ~MainWindow();

private slots:
  void TimerSlot();
};

#endif // MAINWINDOW_H
