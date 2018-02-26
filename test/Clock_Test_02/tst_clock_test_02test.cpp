#include <QString>
#include <QtTest>
#include <QWidget>

#include "../../../../home/pi/Qt_Projects/GUI_Test_20170305/ClockApi.h"


class Clock_Test_02Test : public QObject, public QWidget
{
  Q_OBJECT

public:
  Clock_Test_02Test();

private:
  ClockApi clockApi;

private Q_SLOTS:
  void testCase1();
};

Clock_Test_02Test::Clock_Test_02Test() :
  clockApi()
{
}

void Clock_Test_02Test::testCase1()
{
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Clock_Test_02Test)

#include "tst_clock_test_02test.moc"
