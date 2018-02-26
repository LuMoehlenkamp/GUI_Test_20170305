#ifndef WIDGET_H
#define WIDGET_H

#include "ClockApi.h"

#include <QWidget>


class PaintHelper;
class QPaintEvent;

class Widget : public QWidget
{
  Q_OBJECT
public:
  explicit Widget(PaintHelper *helper, QWidget *parent);

signals:

public slots:
  void animate();

protected:
  void paintEvent(QPaintEvent *event);

private:
  PaintHelper *helper;
  ClockApi clockApi;
  int elapsedSeconds;
  int elapsedMinutes;
  int elapsedHours;
};

#endif // WIDGET_H
