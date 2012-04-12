#include "table.h"
#include <QImage>
#include <QString>
#include <QPainter>
#include <QWidget>
#include <QGridLayout>
//#include <QTGui>
#include <QLabel>

//Constructor for table that opens a window
Table::Table(QWidget *parent, const char *name) : QMainWindow(parent)
  //ui(new Ui::Table)
{
  setWindowTitle(tr("Welcome to Hold 'Em!")); //titles window
  resize(991, 441); //resizes window to fit background
  fileName=name;
}

void Table::paintEvent(QPaintEvent *)
{
  //Portion that creates background image
  //Uses a pixmap and two QrectFs to draw an image on the background
  //Painter things for table
  QRectF targetTable(0, 0, 991, 441);
  QRectF sourceTable(0, 0, 991, 441);
  QPixmap pixMapTable("holdEmTable.png");

  QPainter painter(this);
  painter.drawPixmap(targetTable, pixMapTable, sourceTable);

  //Draws Card
  QRect targetCard(255, 160, 72, 97);
  QPixmap pixMapCard(fileName);
  painter.drawPixmap(targetCard, pixMapCard);  
  
  moveCard(targetCard, pixMapCard);
}

void Table:: moveCard(QRect card, QPixmap pixMap)
{
  QRect targetCard=card;
  QPixmap pixMapCard=pixMap;
  QPainter painter(this);

  for (int i=0; i<=100; i++)
    {
      targetCard.translate(1, 0);
      
    }
}

Table::~Table()
{
 
}

