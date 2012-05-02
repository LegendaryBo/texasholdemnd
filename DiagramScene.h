//DiagramScene.h
//Authors: Matt Brittan, Kevin Jacobs, Scott Aufderheide
//Description in .cpp implementation

#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include "game.h"

//Classes included for definitions
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
class QPixMap;
class QGraphicsPixmapItem;

//Extends QGraphicsScene for functionality
class DiagramScene : public QGraphicsScene
{
  Q_OBJECT
    
    public:
  
  DiagramScene(QObject *parent=0);
  QGraphicsScene* getScene();
  void clearHand(); //Clears all pics on board by deleting their pointers
  void drawBackground(); //Draws table
  void setCaseInt(int); //Sets int for case function in nextState
  int getCaseInt(); //Returns int for case function in nextState
  
  //All cards dealt through fileNames
  void dealInitialHand(const char *, const char *); //Deals two initial cards
  void dealPlayer(const char *, const char *); //Deals two cards to player
  void dealComp(); //Shows two backgrounds
  void dealFlop(const char *, const char *, const char *); //Deals three cards
  void dealTurn(const char*);
  void dealRiver(const char *);
  void showComp(const char *, const char *);
  
  //Where major case decision making is done
  void nextState();

  //Functions that display image for amount of chips
  void displayChips();
  void displayPlayerChips();
  void displayCompChips();
  void displayPot();

  void fold();
  void bet(int);
  void raise(int);
  void call();
  void check();
  
  int updateCall(); //Returns amount of bet to help player call amount
  int AIChoice(); //Returns choice AI made
   
  Game Holdem; //Instance of Game to play hold 'em
  
 private:

  int caseInt;
  QGraphicsScene *graphicsScene;
  
  QPixmap *pixMap;
  
  //Pointers to images created
  QGraphicsPixmapItem *playerCardPtr1;
  QGraphicsPixmapItem *playerCardPtr2; 
  QGraphicsPixmapItem *cardBackgroundPtr1; 
  QGraphicsPixmapItem *cardBackgroundPtr2;
  QGraphicsPixmapItem *compCardPtr1;
  QGraphicsPixmapItem *compCardPtr2;
  QGraphicsPixmapItem *flopPtr1;
  QGraphicsPixmapItem *flopPtr2;
  QGraphicsPixmapItem *flopPtr3;
  QGraphicsPixmapItem *turnPtr;
  QGraphicsPixmapItem *riverPtr;
  QGraphicsPixmapItem *playerChipsPtr;
  QGraphicsPixmapItem *compChipsPtr;
  QGraphicsPixmapItem *potPtr;
  
  //Cutoffs for chips image
  int smallChips;
  int smallMediumChips;
  int mediumLargeChips;
  int largeChips;
};

#endif



