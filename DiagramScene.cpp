#include <QtGui>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "DiagramScene.h"

using namespace std;

DiagramScene::DiagramScene (QObject * parent):QGraphicsScene (parent)
{
  caseInt = 0;
  drawBackground ();

  smallChips = 100;
  smallMediumChips = 400;
  mediumLargeChips = 800;
  largeChips = 1200;
}

void
DiagramScene::drawBackground ()
{
  QPixmap pixMapTable ("holdEmTable.png");
  graphicsScene = new QGraphicsScene ();
  graphicsScene->addPixmap (pixMapTable);
}

QGraphicsScene *
DiagramScene::getScene ()
{
  return graphicsScene;
}

void
DiagramScene::nextState ()
{
  switch (caseInt)
    {
    case 0:
      Round = 1;
      Holdem.reset ();
      Holdem.dealallcards ();
      dealInitialHand (Holdem.human.holecards[0].cardname,
               Holdem.human.holecards[1].cardname);
      Holdem.AI.choice = 'x'; Holdem.human.choice = 'x'; Holdem.AI.betamount = 0; Holdem.human.betamount = 0;
      Holdem.AI.decision(); // update buttons
      displayChips ();
      caseInt++; // needs to go before human choice because computer button would restart case if caseInt==0. 
      while(Holdem.human.choice == 'x') 
    QCoreApplication::processEvents();
      break;
    case 1:  
      if(Holdem.human.choice == 'f' || Holdem.AI.choice == 'f') {Holdem.winner(); caseInt = 0; nextState();}
      else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'b') {caseInt++; nextState();}
      else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
      else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
      else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'r') {caseInt++; nextState();}
      else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') {caseInt++; nextState();}    
      else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'p') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
      else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'b') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
      else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'b') {
        while(Holdem.human.choice == 'p') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 1 again to check for next move
    }
      else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'r')  {
        while(Holdem.human.choice == 'b') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 1 again to check for next move
        }
      break;
    case 2:
      Round  = 2;
      Holdem.AI.choice = 'x'; Holdem.human.choice = 'x'; highbet = 0; Holdem.AI.betamount = 0; Holdem.human.betamount = 0;
      dealFlop (community[0].cardname, community[1].cardname,
        community[2].cardname);
      Holdem.AI.decision();
      displayChips();
      while(Holdem.human.choice == 'x') 
    QCoreApplication::processEvents();
      caseInt++;
      break;
    case 3: 
    if(Holdem.human.choice == 'f' || Holdem.AI.choice == 'f') {Holdem.winner(); caseInt = 0; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'b') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'r') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') {caseInt++; nextState();}    
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'p') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'b') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'b') {
        while(Holdem.human.choice == 'p') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
    }
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'r')  {
        while(Holdem.human.choice == 'b') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
        }
      break;
    case 4:
      Round = 3;
      Holdem.AI.choice = 'x'; Holdem.human.choice = 'x'; highbet = 0; Holdem.AI.betamount = 0; Holdem.human.betamount = 0;
      dealTurn (community[3].cardname);
      Holdem.AI.decision();
      displayChips();
      while(Holdem.human.choice == 'x') 
    QCoreApplication::processEvents();
      caseInt++;
      break;
    case 5:
    if(Holdem.human.choice == 'f' || Holdem.AI.choice == 'f') {Holdem.winner(); caseInt = 0; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'b') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'r') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') {caseInt++; nextState();}    
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'p') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'b') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'b') {
        while(Holdem.human.choice == 'p') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
    }
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'r')  {
        while(Holdem.human.choice == 'b') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
        }
      break;
    case 6:
      Round = 4;
      Holdem.AI.choice = 'x'; Holdem.human.choice = 'x'; highbet = 0; Holdem.AI.betamount = 0; Holdem.human.betamount = 0;
      dealRiver (community[4].cardname);
      Holdem.AI.decision();
      displayChips();
      while(Holdem.human.choice == 'x') 
    QCoreApplication::processEvents();
      caseInt++;
      break;
    case 7:
    if(Holdem.human.choice == 'f' || Holdem.AI.choice == 'f') {Holdem.winner(); caseInt = 0; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'b') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'c') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'c' && Holdem.AI.choice == 'r') {caseInt++; nextState();}
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') {caseInt++; nextState();}    
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'p') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'r' && Holdem.AI.choice == 'b') {Holdem.AI.decision(); displayChips (); nextState();} //update buttons
          else if(Holdem.human.choice == 'p' && Holdem.AI.choice == 'b') {
        while(Holdem.human.choice == 'p') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
    }
          else if(Holdem.human.choice == 'b' && Holdem.AI.choice == 'r')  {
        while(Holdem.human.choice == 'b') 
            QCoreApplication::processEvents();
        nextState(); // Calls case 3 again to check for next move
        }
      break;
    case 8:
      showComp (Holdem.AI.holecards[0].cardname,
      Holdem.AI.holecards[1].cardname);
      caseInt = 0;
      break;
    }
}

int DiagramScene::updateCall()
{
  return highbet;
}
  
  
void
DiagramScene::setCaseInt (int newCase)
{
  caseInt = newCase;
}

int 
DiagramScene::getCaseInt ()
{
return caseInt;
}


void
DiagramScene::bet (int amount)
{
  highbet = amount;
  Holdem.human.bet(amount);
  Holdem.human.choice = 'b';
  displayChips ();
}

void
DiagramScene::raise (int amount)
{
  if (amount > Holdem.human.chips) amount = Holdem.human.chips;
  int raiseamount = amount - highbet;
  highbet = raiseamount;
  Holdem.human.bet(amount);
  Holdem.human.choice = 'r';
  displayChips ();
}

void
DiagramScene::check ()
{
  Holdem.human.choice = 'p';
  displayChips();
}

void
DiagramScene::call ()
{
  Holdem.human.bet(highbet); // leave this
  highbet = 0;               // leave this
  Holdem.human.choice = 'c'; // leave this
  displayChips ();           // leave this
}

void
DiagramScene::fold ()
{
  Holdem.human.choice = 'f';
}

void
DiagramScene::clearHand ()
{
  if (playerCardPtr1!=NULL) delete playerCardPtr1;
  if (playerCardPtr2!=NULL) delete playerCardPtr2;
  if (cardBackgroundPtr1!=NULL) delete cardBackgroundPtr1;
  if (cardBackgroundPtr2!=NULL) delete cardBackgroundPtr2;
  if (compCardPtr1!=NULL) delete compCardPtr1;
  if (compCardPtr2!=NULL) delete compCardPtr2;
  if (flopPtr1!=NULL) delete flopPtr1;
  if (flopPtr2!=NULL) delete flopPtr2;
  if (flopPtr3!=NULL) delete flopPtr3;
  if (turnPtr!=NULL) delete turnPtr;
  if (riverPtr!=NULL) delete riverPtr; 
  if (compChipsPtr!=NULL) delete potPtr;
  //update ();
}

void
DiagramScene::dealInitialHand (const char *player1, const char *player2)
{
  dealPlayer (player1, player2);
  dealComp ();
}

void
DiagramScene::dealPlayer (const char *player1, const char *player2)
{
  QPixmap pixMapOne (player1);
  playerCardPtr1 = graphicsScene->addPixmap (pixMapOne);
  playerCardPtr1->setPos (437, 330);

  QPixmap pixMapTwo (player2);
  playerCardPtr2 = graphicsScene->addPixmap (pixMapTwo);
  playerCardPtr2->setPos (460, 330);

  update ();
}

void
DiagramScene::dealComp ()
{
  //Deals two hidden cards to the top player
  QPixmap pixMapOne ("cardBackground.png");
  cardBackgroundPtr1 = graphicsScene->addPixmap (pixMapOne);
  cardBackgroundPtr1->setPos (447, 10);

  QPixmap pixMapTwo ("cardBackground.png");
  cardBackgroundPtr2 = graphicsScene->addPixmap (pixMapTwo);
  cardBackgroundPtr2->setPos (464, 10);

  update ();
}

void
DiagramScene::showComp (const char *comp1, const char *comp2)
{
  QPixmap pixMapOne (comp1);
  compCardPtr1 = graphicsScene->addPixmap (pixMapOne);
  compCardPtr1->setPos (447, 10);

  QPixmap pixMapTwo (comp2);
  compCardPtr2 = graphicsScene->addPixmap (pixMapTwo);
  compCardPtr2->setPos (464, 10);
}


void
DiagramScene::dealFlop (const char *flop1, const char *flop2,
            const char *flop3)
{
  QPixmap pixMapOne (flop1);
  flopPtr1 = graphicsScene->addPixmap (pixMapOne);
  flopPtr1->setPos (255, 160);

  QPixmap pixMapTwo (flop2);
  flopPtr2 = graphicsScene->addPixmap (pixMapTwo);
  flopPtr2->setPos (355, 160);

  QPixmap pixMapThree (flop3);
  flopPtr3 = graphicsScene->addPixmap (pixMapThree);
  flopPtr3->setPos (455, 160);

  update ();
}

void
DiagramScene::dealTurn (const char *turn)
{
  //Draws Turn Card
  QPixmap pixMapOne (turn);
  turnPtr = graphicsScene->addPixmap (pixMapOne);
  turnPtr->setPos (555, 160);

  update ();
}

void
DiagramScene::dealRiver (const char *river)
{
  //River
  QPixmap pixMapRiver (river);
  riverPtr = graphicsScene->addPixmap (pixMapRiver);
  riverPtr->setPos (655, 160);

  update ();
}

void
DiagramScene::displayChips ()
{
  displayPlayerChips ();
  displayCompChips ();
  displayPot ();

  update ();
}

void
DiagramScene::displayPlayerChips ()
{
  if (playerChipsPtr!=NULL) delete playerChipsPtr;

  int playerChips = Holdem.human.chips;
  
  if (playerChips==0)
    {
      QPixmap pixMap("tinyImage.png");
      playerChipsPtr = graphicsScene->addPixmap(pixMap);
      playerChipsPtr->setPos(321,381);
    }
  else if (playerChips < smallChips) // error
    {
      //display small chip size image

      QPixmap pixMap ("goldStack5.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (321, 381);
    }
  else if (playerChips >= smallChips && playerChips < smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap ("goldStack4.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (324, 378);
    }
  else if (playerChips >= smallMediumChips && playerChips < mediumLargeChips)
    {
      //MAKE NEW IMAGE THAT IS JUST A SINGLE IMAGE
      QPixmap pixMap ("goldStack4.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (324, 378);
    }
  else if (playerChips >= mediumLargeChips && playerChips < largeChips)
    {
      QPixmap pixMap ("goldStack1.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (310, 330);
    }
  else if (playerChips >= largeChips)
    {
      //MAKE ONE IMAGE
      QPixmap pixMap ("goldStack1.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (318, 330);
    }
  update ();
}

void
DiagramScene::displayCompChips ()
{
  if (compChipsPtr!=NULL) delete compChipsPtr;

  int chips = Holdem.AI.chips;
  if (chips>0 && chips < smallChips)
    {
      //display small chip size image
      QPixmap pixMap ("goldStack5.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (614, 20);
    }

  else if (chips >= smallChips && chips < smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap ("goldStack4.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (618, 18);
    }
  else if (chips >= smallMediumChips && chips < mediumLargeChips)
    {
      //MAKE ONE IMAGE
      QPixmap pixMap ("goldStack4.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (618, 18);
    }
  else if (chips >= mediumLargeChips && chips < largeChips)
    {
      QPixmap pixMap ("goldStack1.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (611, -4);
    }
  else if (chips >= largeChips)
    {
      //MAKE ONE IMAGE
      QPixmap pixMap ("goldStack1.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (611, -4);
    }
  update ();
}

void
DiagramScene::displayPot ()
{
  if (potPtr!=NULL) delete potPtr;

  int chips = potsize;
  if (chips>0 && chips < smallChips /*&& chips > 0*/) // possible error
    {
      //display small chip size image
      QPixmap pixMap ("goldStack5.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }

  else if (chips >= smallChips && chips < smallMediumChips)
    {
      //display medium size image
      QPixmap pixMap ("goldStack4.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }
  else if (chips >= smallMediumChips && chips < mediumLargeChips)
    {
      //MAKE ONE IMAGE
      QPixmap pixMap ("goldStack4.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }
  else if (chips >= mediumLargeChips && chips < largeChips)
    {
      QPixmap pixMap ("goldStack1.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }
  else if (chips >= largeChips)
    {
      //MAKE ONE IMAGE
      QPixmap pixMap ("goldStack1.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }
  update ();
}

int DiagramScene::AIChoice() {
int x;
switch(Holdem.AI.choice) {
case 'c': x = 1; break;
case 'p': x = 2; break;
case 'r': x = 3; break;
case 'f': x = 4; break;
case 'b': x = 5; break;
default: x = 6; break;
}
return x;
}
