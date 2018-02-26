#ifndef QXMLTEST_H
#define QXMLTEST_H

#include <QtXml/QtXml>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>
#include <QFile>

using namespace std;

class QxmlTest : public QXmlDefaultHandler
{
  QXmlSimpleReader xmlReader;
  QXmlStreamReader xmlStreamReader;
  QXmlDefaultHandler handler;
  QString fileName;
  //QFile file;
public:
  QxmlTest();
  bool fopenOk;
  bool parseOk;
};

#endif // QXMLTEST_H
