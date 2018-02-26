#include <QtGui>

#include "Widget.h"
#include "PaintHelper.h"

Widget::Widget(PaintHelper *helper, QWidget *parent) :
  QWidget(parent),
  helper(helper),
  clockApi(this)
{
  elapsedSeconds = 0;
  elapsedMinutes = 0;
  elapsedHours = 0;
  setFixedSize(200, 200);
}

void Widget::animate()
{
  elapsedSeconds = clockApi.GetSeconds();//(elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
  elapsedMinutes = clockApi.GetMinute();
  elapsedHours = clockApi.GetHour();
  repaint();
}

void Widget::paintEvent(QPaintEvent *event)
{
  QPainter painter;
  painter.begin(this);
  painter.setRenderHint(QPainter::Antialiasing);
  helper->paint(&painter, event, elapsedSeconds, elapsedMinutes, elapsedHours);
  painter.end();
}

