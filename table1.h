#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>

class QAction;
class QListWidget;
class QMenu;
class QLineEdit;
class QPushButton;
class QFormLayout;
class QGraphicsView;
class QWidget;

class Window : public QMainWindow
{
  Q_OBJECT
    
    public:
  Window();
  
private slots:
  
  //void bet();
  
 private:
  
  
  //Background
  //QGraphicsScene *graphicsScene;
  //QGraphicsView *graphicsView;
  
  void createActions();
  void createButtons();                
  void createDockWindows();
  void createLayout();
  

  //QPushButton *betButton;

  QGraphicsView *graphicsView;
  QPushButton *button1;
  QPushButton *button2;
  QPushButton *button3;
  
  QLineEdit *lineEdit1;
  QLineEdit *lineEdit2;
  QLineEdit *lineEdit3;

  QAction *betButtonAct;

  QFormLayout *layout;
};

#endif

