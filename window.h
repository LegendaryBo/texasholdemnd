#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QAction>
#include "DiagramScene.h"

//class DiagramScene;

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
//class DiagramScene;

class Window : public QMainWindow
{
  Q_OBJECT
    
    public:
  Window();
  
  private slots:
  
  void bet();
  void call();
  void raise();
  void fold();
  void check();
  
  private:
  
  
  //Background

  DiagramScene *scene;
  QGraphicsScene *graphicsScene;
  QGraphicsView *graphicsView;
  
  void createActions();
  void createButtons();				
  void createDockWindows();
  void createLayout();
  
  QPushButton *betButton;
  QPushButton *raiseButton;
  QPushButton *callButton;
  QPushButton *foldButton;
  QPushButton *checkButton;
  
  QLineEdit *lineEditBet;
  QLineEdit *lineEditRaise;
  QLineEdit *lineEditCall;

  QFormLayout *layout;

  QAction *betAction;
  QAction *callAction;
  QAction *raiseAction;
  QAction *foldAction;
  QAction *checkAction;
};

#endif
