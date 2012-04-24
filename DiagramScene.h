#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H
#include <QGraphicsScene>
#include <QObject>

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
  void dealInitialHand(const char *, const char *);
  void dealPlayer(const char *, const char *);
  void dealComp();
  void dealFlop(const char *, const char *, const char *);
  void dealTurn(const char*);
  void dealRiver(const char *);
  void nextState();
  void showComp(const char *, const char *);

  void displayChips(int, int, int);
  void displayPlayerChips(int);
  void displayCompChips(int);
  void displayPot(int);
  
    
  
  //public slots:
  
  //signals:
  
  //protected:
    
  private:
  
  int caseInt;
  QGraphicsScene *graphicsScene;
  
  QPixmap *pixMap;
  
  QGraphicsPixmapItem *item1Ptr;
  QGraphicsPixmapItem *item2Ptr; 
  QGraphicsPixmapItem *item3Ptr; 
  QGraphicsPixmapItem *item4Ptr;
  QGraphicsPixmapItem *item5Ptr;
  QGraphicsPixmapItem *item6Ptr;
  QGraphicsPixmapItem *item7Ptr;
  QGraphicsPixmapItem *item8Ptr;
  QGraphicsPixmapItem *item9Ptr;
  QGraphicsPixmapItem *item10Ptr;
  QGraphicsPixmapItem *item11Ptr;
  QGraphicsPixmapItem *item12Ptr;
  QGraphicsPixmapItem *item13Ptr;
  QGraphicsPixmapItem *item14Ptr;
  QGraphicsPixmapItem *item15Ptr;
  

  int smallChips;
  int smallMediumChips;
  int mediumLargeChips;
  int largeChips;
};

#endif

