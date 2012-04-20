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
#include <QPushButton>

using namespace std;


//Relatively unsure what this does (came from QT creator)
namespace Ui {
  class Table;
}

//Creates "Table" class, which is background and card display on table
class Table : public QWidget
{
    Q_OBJECT

      public:
  Table(QWidget *parent = 0); //Constructor
  void paintEvent(QPaintEvent*); //Event that does the painting

  void drawBackground();
  void moveCard();

  //Functions that display chips
  void displayChips(int, int, int); //player chips, comp chips, pot chips
  void displayPlayerChips(int);
  void displayCompChips(int);
  void displayPot(int);
  
  //Functions that deal cards to players
  void dealInitialHand(const char *, const char *);
  void dealComp();
  void dealPlayer(const char*, const char*);
  void dealFlop(const char *, const char *, const char *);
  void dealTurn(const char*);
  void dealRiver(const char*);
  
  void showComp(); //Shows the computer's cards at end of hand
    
 private:
  QPushButton *button;

  //Chips sizes
  //Go in ascending order
  int smallChips;
  int smallMediumChips;
  int mediumLargeChips;
  int largeChips;
};

#endif // TABLE_H

