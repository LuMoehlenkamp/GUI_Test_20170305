#ifndef PAINTHELPER_H
#define PAINTHELPER_H
#include <QPainter>
#include <QPaintEvent>

class PaintHelper
{
public:
  PaintHelper();
  void paint(QPainter *painter, QPaintEvent *event, int secondsElased, int minutesElapsed, int hoursElapsed);

private:
  QBrush background;
  QBrush circleBrush;
  QFont textFont;
  QPen circlePen;
  QPen textPen;
  QPen linePen;
  int zeroAngle;

  int count;
};

#endif // PAINTHELPER_H
