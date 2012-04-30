#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H
#include <QGraphicsScene>
#include <QObject>
#include "game.h"

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


class DiagramScene : public QGraphicsScene
{
  Q_OBJECT
    
    public:
  
  DiagramScene(QObject *parent=0);
  QGraphicsScene* getScene();
  void addItem();
  void clearHand();
  void drawBackground();
  void setCaseInt(int);
  int getCaseInt();
  void dealInitialHand(const char *, const char *);
  void dealPlayer(const char *, const char *);
  void dealComp();
  void dealFlop(const char *, const char *, const char *);
  void dealTurn(const char*);
  void dealRiver(const char *);
  void nextState();
  void showComp(const char *, const char *);

  void displayChips();
  void displayPlayerChips();
  void displayCompChips();
  void displayPot();

  void fold();
  void bet(int);
  void raise(int);
  void call();
  void check();
  
  int updateCall();
  int AIChoice();
  
  //public slots:
  
  //signals:
  
  //protected:
  game Holdem; // move back to private    
  private:

  int caseInt;
  QGraphicsScene *graphicsScene;
  
  QPixmap *pixMap;
  
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
  

  int smallChips;
  int smallMediumChips;
  int mediumLargeChips;
  int largeChips;
};

#endif
