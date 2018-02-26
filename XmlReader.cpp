#include "XmlReader.h"

XmlReader::XmlReader()
{
  // file = new QFile("xmlTest.xml");
  this->labels.append("Title");// << tr("Location");
  this->fileName = QFileDialog::getOpenFileName(this, tr("Open Bookmark File"),
                                          QDir::currentPath(),
                                          tr("XBEL Files (*.xbel *.xml)"));
  this->source = new QXmlInputSource();
  this->handler = new QXmlDefaultHandler;
  this->xmlReader.setContentHandler(this->handler);
  this->xmlReader.setErrorHandler(this->handler);
}

XmlReader::~XmlReader()
{

}
