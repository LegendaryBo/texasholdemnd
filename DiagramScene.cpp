//DiagramScene.cpp
//Authors: Matt Brittan, Kevin Jacobs, Scott Aufderheide
/*Description: This file runs/controls the display of the game through the
object displayed in the main window. From here, all the chips are displayed, 
cards are displayed, and hands are cleared. However, this also contains the main
case statement to decide when to progress to the next hand (and display it) by
reading the inputs/choices from the Game object included. This case statement
lies within "nextState" and is shown/described below*/

#include <QtGui>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "DiagramScene.h"

DiagramScene::DiagramScene (QObject * parent):QGraphicsScene (parent)
{
  caseInt = -1; //Initializes integer for case statement
  drawBackground (); //Draws table

  //Sets choice to welcome state for display purposes
  Holdem.AI.choice='w';

  //Initializes chip counts for display purposes
  smallChips = 100;
  smallMediumChips = 400;
  mediumLargeChips = 800;
  largeChips = 1200;
}

//Draws table background
void
DiagramScene::drawBackground ()
{
  QPixmap pixMapTable ("holdEmTable.png");
  graphicsScene = new QGraphicsScene ();
  graphicsScene->addPixmap (pixMapTable);
}

//returns the graphics scene which this inhabits 
//used to draw in window
QGraphicsScene *
DiagramScene::getScene ()
{
  return graphicsScene;
}

//function that holds case statement for gameplay decision
void
DiagramScene::nextState ()
{
  char turn;
  switch (caseInt)
    {
    case -1:
      caseInt = 0;
    case 0:
      clearHand();
      Round = 1;
      Holdem.reset ();
      Holdem.dealallcards ();
      dealInitialHand (Holdem.human.holecards[0].cardname,
               Holdem.human.holecards[1].cardname);
      Holdem.AI.choice = 'x';
      Holdem.human.choice = 'x';
      Holdem.AI.betamount = 0;
      Holdem.human.betamount = 0;
      Holdem.AI.decision ();    // update buttons
      displayChips ();
      caseInt = 1;        // needs to go before human choice because computer button would restart case if caseInt==0.
      while (Holdem.human.choice == 'x')
    QCoreApplication::processEvents ();
      if (Holdem.human.choice == 'f')
    fold ();
      else if (Holdem.AI.choice == 'f')
    fold ();
// check if fold
if (caseInt!=8) {
    case 1:
      turn = 'a';
      while (Holdem.human.choice != 'c' && Holdem.AI.choice != 'c'
         && !(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') && Holdem.human.choice != 'f'
         && Holdem.AI.choice != 'f')
    {
      if (turn == 'h')
        {
          Holdem.human.choice = 'x';
          while (Holdem.human.choice == 'x')
        QCoreApplication::processEvents ();
          turn = 'a';
        }
      else if (turn == 'a')
        {
          Holdem.AI.decision ();
              if(Holdem.AI.choice == 'f') fold();
          displayChips ();
          turn = 'h';
          QCoreApplication::processEvents ();
        }
    }
}
if (caseInt!=8) {
      caseInt = 2;
    case 2:
      Round = 2;
      Holdem.AI.choice = 'x';
      Holdem.human.choice = 'x';
      highbet = 0;
      Holdem.AI.betamount = 0;
      Holdem.human.betamount = 0;
      dealFlop (community[0].cardname, community[1].cardname,
        community[2].cardname);
      Holdem.AI.decision ();
      displayChips ();
      while (Holdem.human.choice == 'x')
    QCoreApplication::processEvents ();
      if (Holdem.human.choice == 'f')
    fold ();
      else if (Holdem.AI.choice == 'f')
    fold ();
      else
    caseInt++;
}
if (caseInt!=8) {
    case 3:
      turn = 'a';
      while (Holdem.human.choice != 'c' && Holdem.AI.choice != 'c'
         && !(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p') && Holdem.human.choice != 'f'
         && Holdem.AI.choice != 'f')
    {
      if (turn == 'h')
        {
          Holdem.human.choice = 'x';
          while (Holdem.human.choice == 'x')
        QCoreApplication::processEvents ();
          turn = 'a';
        }
      else if (turn == 'a')
        {
          Holdem.AI.decision ();
              if(Holdem.AI.choice == 'f') fold();
          displayChips ();
          turn = 'h';
          QCoreApplication::processEvents ();
        }
    }
}
if (caseInt!=8) {
      caseInt++;
    case 4:
      Round = 3;
      Holdem.AI.choice = 'x';
      Holdem.human.choice = 'x';
      highbet = 0;
      Holdem.AI.betamount = 0;
      Holdem.human.betamount = 0;
      dealTurn (community[3].cardname);
      Holdem.AI.decision ();
      displayChips ();
      while (Holdem.human.choice == 'x')
    QCoreApplication::processEvents ();
      if (Holdem.human.choice == 'f')
    fold ();
      else if (Holdem.AI.choice == 'f')
    fold ();
      else
    caseInt++;
}
if (caseInt!=8) {
    case 5:
      turn = 'a';
      while (Holdem.human.choice != 'c' && Holdem.AI.choice != 'c'
         && !(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p')&& Holdem.human.choice != 'f'
         && Holdem.AI.choice != 'f')
    {
      if (turn == 'h')
        {
          Holdem.human.choice = 'x';
          while (Holdem.human.choice == 'x')
        QCoreApplication::processEvents ();
          turn = 'a';
        }
      else if (turn == 'a')
        {
          Holdem.AI.decision ();
          if(Holdem.AI.choice == 'f') fold();
          displayChips ();
          turn = 'h';
          QCoreApplication::processEvents ();
        }
    }
}
if (caseInt!=8) {
      caseInt++;
    case 6:
      Round = 4;
      Holdem.AI.choice = 'x';
      Holdem.human.choice = 'x';
      highbet = 0;
      Holdem.AI.betamount = 0;
      Holdem.human.betamount = 0;
      dealRiver (community[4].cardname);
      Holdem.AI.decision ();
      displayChips ();
      while (Holdem.human.choice == 'x')
    QCoreApplication::processEvents ();
      if (Holdem.human.choice == 'f')
    fold ();
      else if (Holdem.AI.choice == 'f')
    fold ();
      else
    caseInt++;
}
if (caseInt!=8) {
    case 7:
      turn = 'a';
      while (Holdem.human.choice != 'c' && Holdem.AI.choice != 'c'
         && !(Holdem.human.choice == 'p' && Holdem.AI.choice == 'p')&& Holdem.human.choice != 'f'
         && Holdem.AI.choice != 'f')
    {
      if (turn == 'h')
        {
          Holdem.human.choice = 'x';
          while (Holdem.human.choice == 'x')
        QCoreApplication::processEvents ();
          turn = 'a';
        }
      else if (turn == 'a')
        {
          Holdem.AI.decision ();
          if(Holdem.AI.choice == 'f') fold();
          displayChips ();
          turn = 'h';
          QCoreApplication::processEvents ();
        }
    }
      caseInt++;
}
    case 8:
      showComp (Holdem.AI.holecards[0].cardname,
        Holdem.AI.holecards[1].cardname);  
      Holdem.winner();
      Holdem.human.choice = 'x';
      caseInt = -1;
      break;
    }
}

//Used to update the amount player needs to bet to call AI's bet
int
DiagramScene::updateCall ()
{
  return highbet;
}

//Used to set the game to a certain state in nextState
void
DiagramScene::setCaseInt (int newCase)
{
  caseInt = newCase;
}

//Returns the int for the current case of the nextState decision making process
int
DiagramScene::getCaseInt ()
{
  return caseInt;
}

//Used to update the players bet
//Calls player bet() fcn which decreases chips and updates bet amount
void
DiagramScene::bet (int amount)
{
  highbet = amount;
  Holdem.human.bet (amount);
  Holdem.human.choice = 'b';
  displayChips ();
}

//Calls human raise function with specific value
//Functions in essentially same way as bet
void
DiagramScene::raise (int amount)
{
  if (amount > Holdem.human.chips)
    amount = Holdem.human.chips;
  int raiseamount = amount - highbet;
  highbet = raiseamount;
  Holdem.human.bet (amount);
  Holdem.human.choice = 'r';
  displayChips ();
}

//Simply sets human choice to check
void
DiagramScene::check ()
{
  Holdem.human.choice = 'p';
}

//Calls the AI bet, sets human's choice to call
void
DiagramScene::call ()
{
  Holdem.human.bet (highbet);    
  highbet = 0;            
  Holdem.human.choice = 'c';    
  displayChips ();        
}

//Sets the nextState to 8, skips rest of hand
void
DiagramScene::fold ()
{
  caseInt = 8;
  QCoreApplication::processEvents ();
}

//Deletes all images if they exist
//resets pointers to null
void
DiagramScene::clearHand ()
{
  if (playerCardPtr1 != NULL)
    {
      delete playerCardPtr1;
      playerCardPtr1=NULL;
    }
  if (playerCardPtr2 != NULL)
    {
      delete playerCardPtr2;
      playerCardPtr2=NULL;
    }
  if (cardBackgroundPtr1 != NULL)
    {
      delete cardBackgroundPtr1;
      cardBackgroundPtr1=NULL;
    }
  if (cardBackgroundPtr2 != NULL)
    {
      delete cardBackgroundPtr2;
      cardBackgroundPtr2=NULL;
    }
  if (compCardPtr1 != NULL)
    {
      delete compCardPtr1;
      compCardPtr1=NULL;
    }
  if (compCardPtr2 != NULL)
    {
      delete compCardPtr2;
      compCardPtr2=NULL;
    }
  if (flopPtr1 != NULL)
    {
      delete flopPtr1;
      flopPtr1=NULL;
    }
  if (flopPtr2 != NULL)
    {
      delete flopPtr2;
      flopPtr2=NULL;
    }
  if (flopPtr3 != NULL)
    {
      delete flopPtr3;
      flopPtr3=NULL;
    }
  if (turnPtr != NULL)
    {
      delete turnPtr;
      turnPtr=NULL;
    }
  if (riverPtr != NULL)
    {
      delete riverPtr;
      riverPtr=NULL;
    }
  if (compChipsPtr != NULL)
    {
      delete potPtr;
      potPtr=NULL;
    }
}

void
DiagramScene::dealInitialHand (const char *player1, const char *player2)
{
  dealPlayer (player1, player2);
  dealComp ();
}

//Deals player two cards through using fileNames passed in
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

//Shows two card backgrounds for computer player
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

//Shows computer cards at end of the round
void
DiagramScene::showComp (const char *comp1, const char *comp2)
{
 delete cardBackgroundPtr1;
 cardBackgroundPtr1=NULL;
 delete cardBackgroundPtr2;
 cardBackgroundPtr2=NULL;

  QPixmap pixMapOne (comp1);
  compCardPtr1 = graphicsScene->addPixmap (pixMapOne);
  compCardPtr1->setPos (447, 10);

  QPixmap pixMapTwo (comp2);
  compCardPtr2 = graphicsScene->addPixmap (pixMapTwo);
  compCardPtr2->setPos (464, 10);
}

//Deals flop, functions in same way as above
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

//Deals turn, functions in same way as above
void
DiagramScene::dealTurn (const char *turn)
{
  //Draws Turn Card
  QPixmap pixMapOne (turn);
  turnPtr = graphicsScene->addPixmap (pixMapOne);
  turnPtr->setPos (555, 160);

  update ();
}

//Deals river, functions in same way as above
void
DiagramScene::dealRiver (const char *river)
{
  //River
  QPixmap pixMapRiver (river);
  riverPtr = graphicsScene->addPixmap (pixMapRiver);
  riverPtr->setPos (655, 160);

  update ();
}

//Displays all chips (user, pot, comp)
void
DiagramScene::displayChips ()
{
  displayPlayerChips ();
  displayCompChips ();
  displayPot ();

  update ();
}

//Displays human chips
//Uses limits above to decide which image to show, of how many chips
void
DiagramScene::displayPlayerChips ()
{
  if (playerChipsPtr != NULL){
    delete playerChipsPtr;
    playerChipsPtr=NULL;
}

  int playerChips = Holdem.human.chips;

  if (playerChips == 0)
    {
      QPixmap pixMap ("tinyImage.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (321, 381);
    }
  else if (playerChips < smallChips) 
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
      QPixmap pixMap ("goldStack3.png");
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
      QPixmap pixMap ("goldStack6.png");
      playerChipsPtr = graphicsScene->addPixmap (pixMap);
      playerChipsPtr->setPos (318, 330);
    }
  update ();
}

//Shows computer chips, functions in same way as human chips
void
DiagramScene::displayCompChips ()
{
  if (compChipsPtr != NULL){
    delete compChipsPtr;
    compChipsPtr=NULL;
}
  int chips = Holdem.AI.chips;
  if (chips > 0 && chips < smallChips)
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
     
      QPixmap pixMap ("goldStack3.png");
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
     
      QPixmap pixMap ("goldStack6.png");
      compChipsPtr = graphicsScene->addPixmap (pixMap);
      compChipsPtr->setPos (611, -4);
    }
  update ();
}

//Shows pot chips, functions in same way as above
void
DiagramScene::displayPot ()
{
  if (potPtr != NULL){
    delete potPtr;
    potPtr=NULL;
}

  int chips = potsize;
  if (chips > 0 && chips < smallChips)    
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
      QPixmap pixMap ("goldStack3.png");
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
      QPixmap pixMap ("goldStack6.png");
      potPtr = graphicsScene->addPixmap (pixMap);
      potPtr->setPos (115, 165);
    }
  update ();
}

//Returns an int for AI's choice
int
DiagramScene::AIChoice ()
{
  int x;
  switch (Holdem.AI.choice)
    {
    case 'c':
      x = 1;
      break;
    case 'p':
      x = 2;
      break;
    case 'r':
      x = 3;
      break;
    case 'f':
      x = 4;
      break;
    case 'b':
      x = 5;
      break;
    default:
      x = 6;
      break;
    }
  return x;
}

