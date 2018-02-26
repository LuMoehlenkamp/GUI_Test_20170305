#include "ClockApi.h"

// Todo
// auf Datenhaltung in tm umbauen -> Kontruktor
ClockApi::ClockApi(QWidget *parent)
  : QWidget(parent)
{
  GetSystemTime();
  QTimer *retrieveSysTime = new QTimer(this);
  bool connectResult = connect(retrieveSysTime, SIGNAL(timeout()), this, SLOT(RetrieveSysTimeSlot()));
  if (connectResult)
    retrieveSysTime->start(250);
}

void ClockApi::GetSystemTime(){
  static int seconds_last = 99;
  gettimeofday(&currentTime, 0);
  if (currentTime.tv_sec == seconds_last)
      return;
  seconds_last = currentTime.tv_sec;
  dateTime = localtime(&currentTime.tv_sec);
  strftime(TimeString, 80, "%Y-%m-%d %H:%M:%S", dateTime);
}

int ClockApi::GetSeconds() const {
  return dateTime->tm_sec;
}

int ClockApi::GetMinute() const {
  return dateTime->tm_min;
}

int ClockApi::GetHour() const {
  return dateTime->tm_hour;
}

int ClockApi::GetDayOfWeek() const {
  return dateTime->tm_wday;
}

int ClockApi::GetDayOfMonth() const {
  return dateTime->tm_mday;
}

int ClockApi::GetDayOfYear() const {
  return dateTime->tm_yday + 1;
}

int ClockApi::GetMonth() const {
  return dateTime->tm_mon + 1;
}

int ClockApi::GetYear() const {
  return dateTime->tm_year + 1900;
}

bool ClockApi::IsDayLightSavingsTime() const {
  if (dateTime->tm_isdst >= 1)
    return true;
  return false;
}

void ClockApi::GetTimeString(char timeString[]){
  strcpy(timeString, TimeString);
}

void ClockApi::RetrieveSysTimeSlot()
{
  GetSystemTime();
}
