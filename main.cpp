
#include <QtGui/QApplication>
#include <QLabel>
#include <QString>
#include <iomanip>
#include <iostream>
#include <QPushButton>
#include <QGraphicsScene>
//import QtQuick 1.0

#include "table.h" //includes table header file
#include "card.h" //includes cards header file

int main(int argc, char *argv[])
{
  QApplication app(argc, argv); //starts a new QApp

  //Creates a table and runs paintevent
  Table table1;
  table1.show();
  return app.exec();

}
