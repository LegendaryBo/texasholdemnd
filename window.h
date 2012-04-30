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
  void update();
  void info();
  
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
  QPushButton *updateButton;
  QPushButton *infoButton;
  QLineEdit *lineEditBet;
  QLineEdit *lineEditRaise;
  QLineEdit *lineEditCall;
  QLineEdit *lineEditUpdate;
  QLineEdit *lineEditInfo;
  QFormLayout *layout;

  QAction *betAction;
  QAction *callAction;
  QAction *raiseAction;
  QAction *foldAction;
  QAction *checkAction;
};

#endif

