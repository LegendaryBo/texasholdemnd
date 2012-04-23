#include <QtGui>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "DiagramScene.h"

DiagramScene::DiagramScene(QObject *parent) : QGraphicsScene(parent)
{
  caseInt=0;
  drawBackground();
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
    dealInitialHand("cardBackground.png", "cardBackground.png");
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



