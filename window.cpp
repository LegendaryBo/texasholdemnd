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

  updateButton = new QPushButton("Make Computer Action");
  lineEditUpdate = new QLineEdit;

  infoButton = new QPushButton("Info");
  lineEditInfo = new QLineEdit;
}

void Window::createLayout()
{
  layout = new QFormLayout;
  layout->addRow(betButton, lineEditBet);
  layout->addRow(raiseButton, lineEditRaise);
  layout->addRow(callButton, lineEditCall);
  layout->addRow(foldButton);
  layout->addRow(checkButton);
  layout->addRow(updateButton, lineEditUpdate);
  layout->addRow(infoButton, lineEditInfo);
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
  connect(updateButton, SIGNAL(clicked()), this, SLOT(update()));
  connect(infoButton, SIGNAL(clicked()), this, SLOT(info()));
}


void Window::update()
{
  char str[9];
  int x;
  x=scene->updateCall();
  x=scene->AIChoice();
  sprintf(str,"%d", x);

  lineEditUpdate->setText(str);
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  if(scene->getCaseInt() == 0) scene->nextState ();
  if(scene->getCaseInt() == 8) { scene->clearHand();scene->update(); scene->nextState(); }
}

void Window::info()
{
   char str[40];
   int AIbet = scene->Holdem.human.betamount;
   int AIchips = scene->Holdem.human.chips;
   int pot = potsize;
   sprintf(str, "bet=%d,highbet=%d,pot=%d",AIbet,highbet,pot);

  lineEditInfo->setText(str);
  scene->update();
  graphicsScene->update();
  graphicsView->update();

}


void Window::bet()
{ 
if(scene->Holdem.AI.choice != 'r' && scene->Holdem.AI.choice != 'b') {
  scene->bet(lineEditBet->text().toInt());
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  if (scene->getCaseInt() % 2 == 1)
  scene->nextState();
}
}

void Window::raise()
{
int raiseamount;    
if(scene->Holdem.AI.choice == 'r' || scene->Holdem.AI.choice == 'b') {
raiseamount = lineEditRaise->text().toInt();
if(raiseamount > highbet) {
  scene->raise(raiseamount);
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  if (scene->getCaseInt() % 2 == 1)
  scene->nextState();
}// end check if raise is valid
}// end check if available option
}// end function

void Window::call()
{
int currentcase = scene->getCaseInt();
if(scene->Holdem.AI.choice == 'r' || scene->Holdem.AI.choice == 'b') {
  scene->call();
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  scene->setCaseInt(++currentcase); // maybe don't this
  scene->nextState();
}
}

void Window::fold()
{
if(scene->Holdem.AI.choice == 'r' || scene->Holdem.AI.choice == 'b') {
  scene->fold();
  scene->update();
  //graphicsScene->update();
  //graphicsView->update();
  scene->Holdem.winner();
  scene->clearHand();
  scene->setCaseInt(0);
  scene->nextState();

}
}

void Window::check()
{
int currentcase = scene->getCaseInt();
if (scene->Holdem.AI.choice != 'r' && scene->Holdem.AI.choice != 'b') {
  scene->check();
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  scene->setCaseInt(++currentcase);
  scene->nextState();
}
}
