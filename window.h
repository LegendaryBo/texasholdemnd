//window.h
//Authors: Matt Brittan, Kevin Jacobs, Scott Aufderheide
//Description in .cpp implementation
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QAction>
#include "DiagramScene.h"

//Classes defined for use
class QAction;
class QListWidget;
class QMenu;
class QLineEdit;
class QPushButton;
class QFormLayout;
class QGraphicsView;
class QWidget;
class QPixmap;
class QGraphicsScene;
class QLabel;

class Window : public QMainWindow
{
  Q_OBJECT
    
    public:
  
  Window();
  
  //Slots used for actions connected to buttons
  private slots:
  
  void bet();
  void call();
  void raise();
  void fold();
  void check();
  void updateCompAction();
  
  private:

  //A DiagramScene object is displayed as a QGraphicsScene through a QGraphicsView
  DiagramScene *scene;
  QGraphicsScene *graphicsScene;
  QGraphicsView *graphicsView;
  
  //Functions that create buttons, actions, lineEdits
  void createActions();
  void createButtonsandEdits();                         
  void createDockWindows();
  void createLayout();
  void closeEvent(QCloseEvent *event);

  //Used to update text boxes for chip counts
  void updatePot();
  void updateCompChips();
  void updateHumanChips();
  
  //Declaration of buttons
  QPushButton *betButton;
  QPushButton *raiseButton;
  QPushButton *callButton;
  QPushButton *foldButton;
  QPushButton *checkButton;
  QPushButton *compActionButton;

  //QLabels used for displaying chip counts
  QLabel *lineEditPlayer;
  QLabel *lineEditComputer;
  QLabel *lineEditHumanChips;
  QLabel *lineEditCompChips;
  QLabel *lineEditPotChips;
  QLabel *lineEditHumanChipCount;
  QLabel *lineEditCompChipCount;
  QLabel *lineEditShowPot;

  //Declaration of QLineEdits
  QLineEdit *lineEditBet;
  QLineEdit *lineEditRaise;
  QLineEdit *lineEditCompShow;
  QLineEdit *lineEditBlank;

  //Form layout to lay out the dockWidget cleanly
  QFormLayout *layout;
};

#endif

