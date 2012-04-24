#include <QApplication>
#include <QLineEdit>
#include <QWidget>
#include <QFormLayout>
#include "window.h"



 int main(int argc, char *argv[])
 {
   
   QApplication app(argc, argv);
   
   //Q_INIT_RESOURCE(dockwidgets);
   Window mainWin;
   mainWin.show();
   return app.exec();
 }

