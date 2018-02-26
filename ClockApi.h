#ifndef CLOCKAPI_H
#define CLOCKAPI_H

#include <sys/time.h>
#include <time.h>
#include <cstddef>
#include <string.h>
#include <QTimer>
#include <QObject>
#include <QWidget>

class ClockApi : public QWidget
{
  Q_OBJECT
  tm *dateTime;
  // ToDO : dayOfWeek (enum?);
  timeval currentTime;
  char TimeString[128];

public:
  ClockApi(QWidget *parent = 0);
  void GetSystemTime();
  int GetSeconds() const;
  int GetMinute() const;
  int GetHour() const;
  int GetDayOfWeek() const;
  int GetDayOfMonth() const;
  int GetDayOfYear() const;
  int GetMonth() const;
  int GetYear() const;
  bool IsDayLightSavingsTime() const;
  void GetTimeString(char[]);

private slots:
  void RetrieveSysTimeSlot();

};

#endif // CLOCKAPI_H
