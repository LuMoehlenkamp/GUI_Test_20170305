#ifndef XMLREADER_H
#define XMLREADER_H

#include <QtXml/QXmlSimpleReader>
#include <QFile>
#include <QtXml/QXmlDefaultHandler>
#include <QFileDialog>

class XmlReader
{
private:
  QStringList labels;

  QString fileName;
  QFile file; // = QFile(fileName);
  QXmlSimpleReader xmlReader;
  QXmlInputSource *source;
  QXmlDefaultHandler *handler;

public:
  XmlReader();
  ~XmlReader();
};

#endif // XMLREADER_H
