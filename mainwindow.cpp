#include "mainwindow.h"

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
