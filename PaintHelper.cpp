#include "PaintHelper.h"

#include <QRectF>
#include <QLine>
#include <math.h>

PaintHelper::PaintHelper()
{
  QLinearGradient gradient(QPointF(50, -20), QPointF(80,20));
  gradient.setColorAt(0.0,Qt::white);
  gradient.setColorAt(1.0,QColor(0xa6,0xce,0x39));

  background = QBrush(QColor(0,0,0));
  circleBrush = QBrush(gradient);
  circlePen = QPen(Qt::white);
  circlePen.setWidth(7);
  circlePen.setCapStyle(Qt::RoundCap);
  textPen = QPen(Qt::white);
  textFont.setPixelSize(50);
  linePen = QPen(Qt::white);
  linePen.setWidth(1);
  count = 0;
  zeroAngle = 1440;
}

void PaintHelper::paint(QPainter *painter, QPaintEvent *event, int secondsElapsed, int minutesElapsed,int hoursElapsed)
{
  painter->fillRect(event->rect(), background);
  painter->translate(100, 100);
  painter->save();
  painter->setBrush(circleBrush);
  painter->setPen(circlePen);

  int spanAngleSeconds, spanAngleMinutes, spanAngleHours;
  float spanAngleSecondsFloat, spanAngleMinutesFloat, spanAngleHoursFloat;

  QRectF rectSeconds = QRectF(-70.0, -70.0, 140.0, 140.0);
  if (secondsElapsed == 0)
    spanAngleSecondsFloat = -5760.0;
  else
    spanAngleSecondsFloat = float(secondsElapsed)/60.0 * -5760.0; // 96 = 5760 / 60
  spanAngleSeconds = int(spanAngleSecondsFloat);
  painter->drawArc(rectSeconds, zeroAngle, spanAngleSeconds);

  QRectF rectMinutes = QRectF(-60.0,-60.0,120.0,120.0);
  if (minutesElapsed == 0)
    spanAngleMinutesFloat = -5760.0;
  else
    spanAngleMinutesFloat = float(minutesElapsed)/60.0 * -5760.0;
  spanAngleMinutes = int(spanAngleMinutesFloat);
  painter->drawArc(rectMinutes, zeroAngle, spanAngleMinutes);

  QRectF rectHours = QRectF(-50.0,-50.0,100.0,100.0);
  if (hoursElapsed == 0)
    spanAngleHoursFloat = -5760.0;
  else
    spanAngleHoursFloat = float(hoursElapsed%12)/12.0 * -5760.0;
  spanAngleHours = int(spanAngleHoursFloat);
  painter->drawArc(rectHours, zeroAngle, spanAngleHours);


  painter->setPen(linePen);
  QLine line_1 = QLine(0,-100,0,100);
  for (int i=0;i<6;++i){
    painter->rotate(30);
    painter->drawLine(line_1);
  }

  painter->rotate(180);
  painter->setPen(textPen);
  painter->setFont(textFont);
  painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QString::number(secondsElapsed%60,10));
  painter->restore();
}




