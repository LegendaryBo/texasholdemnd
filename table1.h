#include <QtGui>
#include <QAction>
#include <QGraphicsScene>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include "window.h"

Window::Window()
{
  setWindowTitle(tr("Dock Widgets"));
  resize(1258, 500);
  QPixmap pixMapTable("holdEmTable.png");
  graphicsScene = new QGraphicsScene();
  graphicsScene -> addPixmap(pixMapTable);

  graphicsView = new QGraphicsView(graphicsScene);
  setCentralWidget(graphicsView);
  
  createButtons();
  createLayout();
  createDockWindows();
  //createActions();
}


void Window::createButtons()
{
  betButton = new QPushButton("Bet");
  lineEditBet = new QLineEdit;
  raiseButton = new QPushButton("Raise");
  lineEditRaise = new QLineEdit;
  callButton = new QPushButton("Call");
  lineEditCall = new QLineEdit;
  foldButton = new QPushButton("Fold");
  stayButton = new QPushButton("Stay");
}

void Window::createLayout()
{
  layout = new QFormLayout;
  layout->addRow(betButton, lineEditBet);
  layout->addRow(raiseButton, lineEditRaise);
  layout->addRow(callButton, lineEditCall);
  layout->addRow(foldButton);
  layout->addRow(stayButton);
}
  
//void Window::createActions()
//{
// betButtonAct = new QAction("Call", this);
// connect(betButtonAct, SIGNAL(triggered()), this, SLOT(bet()));
//}

void Window::createDockWindows()
{
    
  QWidget *wi = new QWidget;
  wi->setLayout(layout);
  
  QDockWidget *dw = new QDockWidget(tr("Buttons"), this);
  dw->setWidget(wi);
  addDockWidget(Qt::LeftDockWidgetArea, dw);
}

