#include <QtGui>
#include <QAction>
#include <QGraphicsScene>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <stdio.h>
#include <stdlib.h>
#include "window.h"

Window::Window()
{
  setWindowTitle(tr("Dock Widgets"));
  resize(1258, 500);

  scene = new DiagramScene(this);
  graphicsScene = scene->getScene();

  graphicsView = new QGraphicsView(graphicsScene);
  setCentralWidget(graphicsView);
  
  createButtons();
  createLayout();
  createDockWindows();
  createActions();
}


void Window::createButtons()
{
  betButton = new QPushButton("Bet");
  lineEditBet = new QLineEdit;
  lineEditBet->setText("50");
  raiseButton = new QPushButton("Raise");
  lineEditRaise = new QLineEdit;
  lineEditBet->setText("50");
  callButton = new QPushButton("Call");
  lineEditCall = new QLineEdit;
  foldButton = new QPushButton("Fold");
  checkButton = new QPushButton("Check");
}

void Window::createLayout()
{
  layout = new QFormLayout;
  layout->addRow(betButton, lineEditBet);
  layout->addRow(raiseButton, lineEditRaise);
  layout->addRow(callButton, lineEditCall);
  layout->addRow(foldButton);
  layout->addRow(checkButton);
}

void Window::createDockWindows()
{
  QWidget *wi = new QWidget;
  wi->setLayout(layout);
  
  QDockWidget *dw = new QDockWidget(tr("Buttons"), this);
  dw->setWidget(wi);
  addDockWidget(Qt::LeftDockWidgetArea, dw);
}

void Window::createActions()
{
  connect(betButton, SIGNAL(clicked()), this, SLOT(bet()));
  connect(raiseButton, SIGNAL(clicked()), this, SLOT(raise()));
  connect(callButton, SIGNAL(clicked()), this, SLOT(call()));
  connect(foldButton, SIGNAL(clicked()), this, SLOT(fold()));
  connect(checkButton, SIGNAL(clicked()), this, SLOT(check()));
}

void Window::bet()
{ 
  scene->bet(lineEditBet->text().toInt());
  scene->nextState();
  scene->update();
  graphicsScene->update();
  graphicsView->update();
}

void Window::raise()
{
  scene->raise(lineEditRaise->text().toInt());
}

void Window::call()
{
  //Figure out how to convert this to an int
  char str[9];
  int x=567;

  sprintf(str,"%d", x);

  lineEditCall->setText(str);
  scene->nextState();
  scene->update();
  graphicsScene->update();
  graphicsView->update();
}

void Window::fold()
{
  scene->fold();
  scene->nextState();

  scene->update();
  graphicsScene->update();
  graphicsView->update();
}

void Window::check()
{
}

