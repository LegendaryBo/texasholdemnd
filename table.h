#ifndef TABLE_H
#define TABLE_H

#include "lab8_global.h"
#include <QWidget>
#include <QImage>
#include <QString>
#include <QPainter>
using namespace std;

class Table : public QWidget {
    Q_OBJECT
public:
    Table(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
private:
     QImage *tablePic;
};

#endif // TABLE_H
