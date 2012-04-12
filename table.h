#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QLabel>
#include <string>
#include <QWidget>
using namespace std;


//Relatively unsure what this does (came from QT creator)
namespace Ui {
  class Table;
}

//Creates "Table" class, which is background and card display on table
class Table : public QMainWindow
{
    Q_OBJECT

      public:
  Table(QWidget *parent = 0, const char *name=""); //Constructor
  void paintEvent(QPaintEvent*); //Event that does the painting
  ~Table(); //Deconstructor
  void moveCard(QRect, QPixmap);
    
 private:
  const char *fileName;
  int velocity;
};

#endif // TABLE_H

