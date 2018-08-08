#include "mainwindow.h"
//#include "../../home/pi/libmodbus/src/modbus.h"
//#include "../../home/pi/libmodbus/src/modbus-private.h"
#include <errno.h>
#include <stdlib.h>

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    count(0)
    // clockApi(this)
{
  setupUi(this);
  QTimer *timer_1 = new QTimer(this);
  connect(timer_1, SIGNAL(timeout()), this, SLOT(TimerSlot()));
  timer_1->start(250);

  PinExportRes = system("gpio export 24 out");
  WiringPiSetupRes = wiringPiSetup();

  Widget *widget = new Widget(&paintHelper, this);
  widget->setGeometry(20,20,200,200);
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(widget, 0, 0);
  connect(timer_1, SIGNAL(timeout()), widget, SLOT(animate()));
/*
  modbus_t *ctx;
  ctx = modbus_new_tcp("192.168.178.22", 502);
  modbus_set_debug(ctx, TRUE);

  if (modbus_connect(ctx) == -1) {
      fprintf(stderr, "Connection failed: %s\n",
              modbus_strerror(errno));
      modbus_free(ctx);
    }
*/
}

MainWindow::~MainWindow()
{
  digitalWrite(5,0);
}

void MainWindow::TimerSlot()
{
  Increment(count);
  int a = count % 2;
  digitalWrite(5,a);

 }

void MainWindow::Increment(int& a)
{
  ++a;
}
