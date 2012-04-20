#include "table.h"
#include <QImage>
#include <QString>
#include <QPainter>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

//Constructor for table that opens a window
//Start with player's, then to comp's, go to flop, then to turn, then river, 
Table::Table(QWidget *parent, const char *player1, const char *player2, const char *comp1, const char *comp2, const char *flop1, const char *flop2, const char *flop3, const char *turn, const char *river) : QWidget(parent)
{
  setWindowTitle(tr("Welcome to Hold 'Em!")); //titles window
  resize(991, 520); //resizes window to fit background  

  //Set chip sizes for image
}

void Table::paintEvent(QPaintEvent *)
{
  drawBackground();                   
  displayPlayerChips(300);
  displayCompChips(300);
  displayPot(300);
  

  //Begin case structure here
  //This will be done Saturday night(ish)--make any comments if you decide that some idea is better (or email me of course)
  /*dealInitialHand("aceSpades.png", "kingSpades.png");
  dealFlop("queenSpades.png", "jackSpades.png", "tenSpades.png");
  
  
  //dealComp();
  
  dealInitialHand(player1, player2);
  //Need to wait for bet--Talk to Kev and Scott about this
  but thinking we could just do setVisible=false()
  dealFlop(flop1, flop2, flop3);
  //Need to wait again
  dealTurn(turn);
  //Need to wait
  dealRiver(river);*/
}

void Table::drawBackground()
{
  QRectF targetTable(0, 0, 991, 441);
  QRectF sourceTable(0, 0, 991, 441);
  QPixmap pixMapTable("holdEmTable.png");
  
  //QPixmap pixMap(targetTable, pixMapTable, sourceTable);
  QPainter painter(this);
  painter.drawPixmap(0, 0, pixMapTable);
}
  

void Table::dealInitialHand(const char *player1, const char *player2)
{
  dealPlayer(player1, player2);
  dealComp();
}

void Table::dealPlayer(const char *file1, const char *file2)
{
  QPainter painter(this);
  //Deals two cards to user-player in bottom left
  QRectF targetOne(437, 330, 70, 95);
  QRectF sourceOne(0, 0, 70, 95);
  QPixmap pixMapOne(file1);
  painter.drawPixmap(targetOne, pixMapOne, sourceOne);

  QRectF targetTwo(460, 330, 70, 97);
  QRectF sourceTwo(0, 0, 70, 97);
  QPixmap pixMapTwo(file2);
  painter.drawPixmap(targetTwo, pixMapTwo, sourceTwo);
}

void Table::dealComp()
{
  //Deals two hidden cards to the top player
  //This is what bottom right player will look like as well
  QPainter painter(this);
  QRectF targetBackground1(447, 10, 74, 97);
  QRectF sourceBackground1(0, 0, 74, 97);
  QPixmap pixMapBackground1("cardBackground.png");
  painter.drawPixmap(targetBackground1, pixMapBackground1, sourceBackground1);

  QRectF targetBackground2(464, 10, 74, 97);
  QRectF sourceBackground2(0, 0, 74, 97);
  QPixmap pixMapBackground2("cardBackground.png");
  painter.drawPixmap(targetBackground2, pixMapBackground2, sourceBackground2);
}

void Table::showComp(const char *comp1, const char *comp2)
{
  QPainter painter(this);
  QRectF targetBackground1(447, 10, 74, 97);
  QRectF sourceBackground1(0, 0, 74, 97);
  QPixmap pixMapBackground1(comp1);
  painter.drawPixmap(targetBackground1, pixMapBackground1, sourceBackground1);

  QRectF targetBackground2(464, 10, 74, 97);
  QRectF sourceBackground2(0, 0, 74, 97);
  QPixmap pixMapBackground2(comp2);
  painter.drawPixmap(targetBackground2, pixMapBackground2, sourceBackground2);
}

void Table::dealFlop(const char *flop1, const char *flop2, const char *flop3)
{
  QPainter painter(this);
  //Draws Card
  /*QRect target(255, 160, 72, 97);
  QPixmap pixMap(fileName);
  painter.drawPixmap(targetCard, pixMapCard);*/

  //Section that draws flop
  //Draws far left card
  QRectF targetFlop1(255, 160, 72, 97);
  QRectF sourceFlop1(0, 0, 72, 97);
  QPixmap pixMapFlop1(flop1);
  painter.drawPixmap(targetFlop1, pixMapFlop1, sourceFlop1);

  //Draws middle
  QRectF targetFlop2(355, 160, 72, 97);
  QRectF sourceFlop2(0, 0, 72, 97);
  QPixmap pixMapFlop2(flop2);
  painter.drawPixmap(targetFlop2, pixMapFlop2, sourceFlop2);

  //Draws right
  QRectF targetFlop3(455, 160, 72, 97);
  QRectF sourceFlop3(0, 0, 72, 97);
  QPixmap pixMapFlop3(flop3);
  painter.drawPixmap(targetFlop3, pixMapFlop3, sourceFlop3);
}

void Table::dealTurn(const char* turn)
{
  //Draws Turn Card
  QPainter painter(this);
  QRectF target(555, 160, 70, 97);
  QRectF source(0, 0, 70, 97);
  QPixmap pixMap(turn);
  painter.drawPixmap(target, pixMap, source);
}

void Table::dealRiver(const char *river)
{
  //River
  QPainter painter(this);
  QRectF targetRiver(655, 160, 72, 95);
  QRectF sourceRiver(0, 0, 72, 95);
  QPixmap pixMapRiver(river);
  painter.drawPixmap(targetRiver, pixMapRiver, sourceRiver);
}

//Locations: 310, 355, 400
void Table:: displayPlayerChips(int playerChips)
{
  /* //if (playerChips<smallChips)
  //{
      //display small chip size image
      QRect target(321, 381, 30, 34);
      QPixmap pixMap("goldStack5.png");
      QPainter painter(this);
      painter.drawPixmap(target, pixMap);
      //}
      else if (playerChips>=smallChips && playerChips<smallMediumChips)
      {
      //display medium size image
  QRect target(324, 378, 26, 30);
  QPixmap pixMap("goldStack4.png");
  QPainter painter(this);
  painter.drawPixmap(target, pixMap);
  
  }
  // else if (playerChips>=smallMediumChips && playerChips<mediumLargeChips)
  // {
  QPainter painter(this);
  QRect target1(324, 378, 26, 30);
  QPixmap pixMap1("goldStack4.png");
  painter.drawPixmap(target1, pixMap1);

  QRect target(351, 378, 26, 30);
  QPixmap pixMap("goldStack4.png");
  painter.drawPixmap(target, pixMap);
  // }
  else if (playerChips>=mediumLargeChips && playerChips<largeChips)
  {
      //display one big image
      QRect target(310, 330, 44, 93);
      QPixmap pixMap("goldStack1.png");
      QPainter painter(this);
      painter.drawPixmap(target, pixMap);
      } */
  //else if (playerChips>=largeChips)
  //{
      //display 2 full chip holders image
  QRect target(318, 330, 35, 86);
      QPixmap pixMap("goldStack1.png");
      QPainter painter(this);
      painter.drawPixmap(target, pixMap);

       QRect target1(346, 330, 35, 86);
      QPixmap pixMap1("goldStack1.png");
      painter.drawPixmap(target1, pixMap1);
      
  //}
}

void Table:: displayCompChips(int chips)
{
  if (chips<smallChips)
    {
      //display small chip size image
      
      QPainter painter(this);
      QRectF target(614, 20, 36, 34);
      QRectF source(0, 0, 74, 97);
      QPixmap pixMap("goldStack5.png");
      painter.drawPixmap(target, pixMap, source);
    }
  
  else if (chips>=smallChips && chips<smallMediumChips)
    {
      //display medium size image
      QPainter painter(this);
      QRectF target(618, 18, 41, 71);
      QRectF source(0, 0, 74, 97);
      QPixmap pixMap("goldStack4.png");
      painter.drawPixmap(target, pixMap, source);
      
    }
  else if (chips>=smallMediumChips && chips<mediumLargeChips)
    {
      //Display two medium images
      QPainter painter(this);
      QRectF target1(618, 18, 41, 71);
      QRectF source1(0, 0, 74, 97);
      QPixmap pixMap1("goldStack4.png");
      painter.drawPixmap(target1, pixMap1, source1);
      
      QRectF target(595, 18, 41, 71);
      QRectF source(0, 0, 74, 97);
      QPixmap pixMap("goldStack4.png");
      painter.drawPixmap(target, pixMap, source);
    }
  else if (chips>=mediumLargeChips && chips<largeChips)
    {
      //display one big image
      QPainter painter(this);
      QRectF target(611, -4, 36, 71);
      QRectF source(0, 0, 74, 97);
      QPixmap pixMap("goldStack1.png");
      painter.drawPixmap(target, pixMap, source);    
      
    }
  else if (chips>=largeChips)
    {
      //display 2 full chip holders image
      QPainter painter(this);
      QRectF target1(611, -4, 36, 71);
      QRectF source1(0, 0, 74, 97);
      QPixmap pixMap1("goldStack1.png");
      painter.drawPixmap(target1, pixMap1, source1);
      
      QRectF target(583, -4, 36, 71);
      QRectF source(0, 0, 74, 97);
      QPixmap pixMap("goldStack1.png");
      painter.drawPixmap(target, pixMap, source);
    }
  
}

void Table::displayPot(int chips)
{
  QPainter painter(this);
  QRectF target(115, 165, 41, 71);
  QRectF source(0, 0, 74, 97);
  QPixmap pixMap("goldStack1.png");
  painter.drawPixmap(target, pixMap, source);
}

 /*void Table:: moveCard()
{
  QRect targetCard(355, 160, 72, 97);
  QPixmap pixMapCard("tenSpades.png");
  QPainter painter(this);

  for (int i=0; i<=100; i++)
    {
      targetCard.translate(1, 0);  
      painter.drawPixmap(targetCard, pixMapCard);
    }
    }*/



