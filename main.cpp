#include <QApplication>
#include <QWidget>
#include "table.h"
using namespace std;

int main(int argc, char *argv[ ]) {
        QApplication app(argc, argv);

        Table table1;
        table1.setVisible(TRUE);
        return app.exec();
}
