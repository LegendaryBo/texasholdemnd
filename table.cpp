#include "table.h"
#include <QImage>
#include <QString>
#include <Q3Painter>
using namespace std;


Table::Table(QWidget *parent): QWidget (parent)
{
    tablePic= new QImage;
    tablePic->load("holdEmTable.jpg");
}


void Table::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  //! get a painter object to send drawing commands to
    painter.drawImage(0,0, *tablePic);
}
