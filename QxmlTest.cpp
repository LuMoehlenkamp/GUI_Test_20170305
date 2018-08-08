#include "QxmlTest.h"

QxmlTest::QxmlTest()
{
  fopenOk = false;
  parseOk = false;
  fileName = "/home/pi/Qt_Projects/GUI_Test_20170305/xmlTest.xml";
  QFile *file = new QFile("/home/pi/Qt_Projects/GUI_Test_20170305/xmlTest.xml");
  if (!file->exists()) {
    qDebug() << "file: "
             << fileName
             << " doesn't exist";
    return;
    }

  fopenOk = file->open(QIODevice::ReadOnly | QIODevice::Text);
  if (!fopenOk) {
    qDebug() << "file: "
             << fileName
             << " could not be opened!";
    return;
    }

  xmlStreamReader.setDevice(file);

  while(!xmlStreamReader.atEnd() && !xmlStreamReader.hasError()) {
      // Read next element
      QXmlStreamReader::TokenType token = xmlStreamReader.readNext();
      //If token is just StartDocument - go to next
      if(token == QXmlStreamReader::StartDocument) {
        continue;
        }

      //If token is StartElement - read it
      if(token == QXmlStreamReader::StartElement) {
        if(xmlStreamReader.name() == "name") {
        continue;
        }

      if(xmlStreamReader.name() == "id") {
        qDebug() << xmlStreamReader.readElementText();
        }

      if(xmlStreamReader.name() == "value"){
          qDebug() << xmlStreamReader.readElementText();
        }

      }
    }


  //close reader and flush file
  xmlStreamReader.clear();
  file->close();
}
