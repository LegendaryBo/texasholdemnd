#include <QtGui>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "DiagramScene.h"

DiagramScene::DiagramScene(QObject *parent) : QGraphicsScene(parent)
{
  caseInt=0;
  drawBackground();

  smallChips=30;
  smallMediumChips=400;
  mediumLargeChips=800;
  largeChips=1200;
}

void DiagramScene::drawBackground()
{
  QPixmap pixMapTable("holdEmTable.png");
  graphicsScene = new QGraphicsScene();
  graphicsScene -> addPixmap(pixMapTable);
}

QGraphicsScene * DiagramScene::getScene()
{
  return graphicsScene;
}

void DiagramScene::nextState()
{
  switch (caseInt) {
  case 0:
    Holdem.reset();
    Holdem.dealallcards();
    dealInitialHand(Holdem.human.holecards[0].cardname, "cardBackground.png");
    Holdem.AI.decision();
    displayChips();    
   // Holdem.human.decision();
    displayChips();
    caseInt++;
    break;
  case 1:
    dealFlop("cardBackground.png", "cardBackground.png", "cardBackground.png");
    caseInt++;
    break;
  case 2:
    dealTurn("cardBackground.png");
    caseInt++;
    break;
  case 3:
    dealRiver("cardBackground.png");
    caseInt++;
    break;
  case 4:
    showComp("cardBackground.png", "cardBackground.png"); 
    clearHand();
    caseInt=0;
    break;
  }
}

void DiagramScene::setCaseInt(int newCase)
{
  caseInt=newCase;
}

void DiagramScene::bet(int amount)
{
  highbet=amount;
  Holdem.human.chips-=amount;
  Holdem.human.choice = 'b';
}

void DiagramScene::raise(int amount)
{
  highbet+=amount;
  Holdem.human.chips-=amount;
  Holdem.human.choice = 'r';
}

void DiagramScene::check()
{
Holdem.human.choice = 'p';
}

void DiagramScene::call(int amount)
{
  Holdem.human.chips-=amount;
  highbet=0;
  Holdem.human.choice = 'c';
}  

void DiagramScene::fold()
{
 Holdem.human.choice='f';
 clearHand();
 Holdem.winner();
}

void DiagramScene::clearHand()
{
  delete item1Ptr;
  delete item2Ptr;
  delete item3Ptr;
  delete item4Ptr;
  delete item5Ptr;
  delete item6Ptr;
  delete item7Ptr;
  delete item8Ptr;
  delete item9Ptr;
  delete item10Ptr;
  //delete item11Ptr;
  delete item12Ptr;
  delete item13Ptr;
  delete item14Ptr;
  
  update();
}

void DiagramScene::dealInitialHand(const char *player1, const char *player2)
{
  dealPlayer(player1, player2);
  dealComp();
}

void DiagramScene::dealPlayer(const char *player1, const char *player2)
{
  QPixmap pixMapOne(player1);
  item1Ptr=graphicsScene->addPixmap(pixMapOne);
  item1Ptr->setPos(437,330);

  QPixmap pixMapTwo(player2);
  item2Ptr=graphicsScene->addPixmap(pixMapTwo);
  item2Ptr->setPos(460, 330);

  update();
}

void DiagramScene::dealComp()
{
  //Deals two hidden cards to the top player
  QPixmap pixMapOne("cardBackground.png");
  item3Ptr=graphicsScene->addPixmap(pixMapOne);
  item3Ptr->setPos(447, 10);

  QPixmap pixMapTwo("cardBackground.png");
  item4Ptr=graphicsScene->addPixmap(pixMapTwo);
  item4Ptr->setPos(464, 10);
  
  update();
}

void DiagramScene::showComp(const char *comp1, const char *comp2)
{
  QPixmap pixMapOne("cardBackground.png");
  item3Ptr=graphicsScene->addPixmap(pixMapOne);
  item3Ptr->setPos(447, 10);

  QPixmap pixMapTwo("cardBackground.png");
  item4Ptr=graphicsScene->addPixmap(pixMapTwo);
  item4Ptr->setPos(464, 10);
}


void DiagramScene::dealFlop(const char *flop1, const char *flop2, const char *flop3)
{
  QPixmap pixMapOne(flop1);
  item5Ptr=graphicsScene->addPixmap(pixMapOne);
  item5Ptr->setPos(255, 160);

  QPixmap pixMapTwo(flop2);
  item6Ptr=graphicsScene->addPixmap(pixMapTwo);
  item6Ptr->setPos(355, 160);

  QPixmap pixMapThree(flop3);
  item7Ptr=graphicsScene->addPixmap(pixMapThree);
  item7Ptr->setPos(455, 160);

  update();
}

void DiagramScene::dealTurn(const char* turn)
{
  //Draws Turn Card
  QPixmap pixMapOne(turn);
  item8Ptr=graphicsScene->addPixmap(pixMapOne);
  item8Ptr->setPos(555, 160);

  update();
}

void DiagramScene::dealRiver(const char *river)
{
  //River
  QPixmap pixMapRiver(river);
  item9Ptr=graphicsScene->addPixmap(pixMapRiver);
  item9Ptr->setPos(655, 160);
  
  update();
}

void DiagramScene:: displayChips()
{
  displayPlayerChips();
  displayCompChips();
  displayPot();
  
  update();
}

void DiagramScene:: displayPlayerChips()
{
int playerChips = Holdem.human.chips;
  if (playerChips<smallChips)
    {
      //display small chip size image

      QPixmap pixMap("goldStack5.png");
      item10Ptr=graphicsScene->addPixmap(pixMap);
      item10Ptr->setPos(321, 381);
    }
  else if (playerChips>=smallChips && playerChips<smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap("goldStack4.png");
      item10Ptr=graphicsScene->addPixmap(pixMap);
      item10Ptr->setPos(324, 378);
    }
  else if (playerChips>=smallMediumChips && playerChips<mediumLargeChips)
    {

      QPixmap pixMap("goldStack4.png");
      item10Ptr=graphicsScene->addPixmap(pixMap);
      item10Ptr->setPos(324, 378);
      
      QPixmap pixMap1("goldStack4.png");
      item11Ptr=graphicsScene->addPixmap(pixMap1);
      item11Ptr->setPos(351, 378);
    }
  else if (playerChips>=mediumLargeChips && playerChips<largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item10Ptr=graphicsScene->addPixmap(pixMap);
      item10Ptr->setPos(310, 330);
    } 
  else if (playerChips>=largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item10Ptr=graphicsScene->addPixmap(pixMap);
      item10Ptr->setPos(318, 330);

      QPixmap pixMap1("goldStack1.png");
      item11Ptr=graphicsScene->addPixmap(pixMap1);
      item11Ptr->setPos(346, 330);
    }
  update();
}

void DiagramScene:: displayCompChips()
{
int chips = Holdem.AI.chips;
  if (chips<smallChips)
    {
      //display small chip size image
      QPixmap pixMap("goldStack5.png");
      item12Ptr=graphicsScene->addPixmap(pixMap);
      item12Ptr->setPos(614, 20);
    }
  
  else if (chips>=smallChips && chips<smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap("goldStack4.png");
      item12Ptr=graphicsScene->addPixmap(pixMap);
      item12Ptr->setPos(618, 18);
    }
  else if (chips>=smallMediumChips && chips<mediumLargeChips)
    {
      QPixmap pixMap("goldStack4.png");
      item12Ptr=graphicsScene->addPixmap(pixMap);
      item12Ptr->setPos(618, 18);
      
      item13Ptr=graphicsScene->addPixmap(pixMap);
      item13Ptr->setPos(595, 18);  
    }
  else if (chips>=mediumLargeChips && chips<largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item12Ptr=graphicsScene->addPixmap(pixMap);
      item12Ptr->setPos(611, -4);      
    }
  else if (chips>=largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item12Ptr=graphicsScene->addPixmap(pixMap);
      item12Ptr->setPos(611, -4);
      
      item13Ptr=graphicsScene->addPixmap(pixMap);
      item13Ptr->setPos(583, -4);
    }
  update();
}

//115, 165
void DiagramScene::displayPot()
{
int chips = potsize;
  if (chips<smallChips)
    {
      //display small chip size image
      QPixmap pixMap("goldStack5.png");
      item14Ptr=graphicsScene->addPixmap(pixMap);
      item14Ptr->setPos(115, 165);
    }
  
  else if (chips>=smallChips && chips<smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap("goldStack4.png");
      item14Ptr=graphicsScene->addPixmap(pixMap);
      item14Ptr->setPos(115, 165);
    }
  else if (chips>=smallMediumChips && chips<mediumLargeChips)
    {
      QPixmap pixMap("goldStack4.png");
      item14Ptr=graphicsScene->addPixmap(pixMap);
      item14Ptr->setPos(115, 165);
      
      item15Ptr=graphicsScene->addPixmap(pixMap);
      item15Ptr->setPos(70, 165);  
    }
  else if (chips>=mediumLargeChips && chips<largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item14Ptr=graphicsScene->addPixmap(pixMap);
      item14Ptr->setPos(115, 165);      
    }
  else if (chips>=largeChips)
    {
      QPixmap pixMap("goldStack1.png");
      item14Ptr=graphicsScene->addPixmap(pixMap);
      item14Ptr->setPos(115, 165);
      
      item15Ptr=graphicsScene->addPixmap(pixMap);
      item15Ptr->setPos(70, 165);
    }
  update();
}

