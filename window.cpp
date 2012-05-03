//window.cpp
//Authors: Kevin Jacobs, Matt Brittan, Scott Aufderheide
/*Description: This program opens a QT window to display the dock widgets 
(where all the buttons are held) and also holds the DiagramScene where the 
actual game scene is displayed. The dock widget is controlled/manipulated
through this scene, while the DiagramScene is simply displayed, and mainly
manipulated through its own class; however, a few calls are made to 
DiagramScene functions within the buttons functions. On that note, whenever
buttons are clicked, they call an action that updates graphics and calls
functions within DiagramScene.cpp. This will be shown below (in comments)*/ 

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
  setWindowTitle(tr("Texas Hold 'Em"));
  resize(1258, 500);

  //Declares new DiagramScene to display game
  //Actually displays it through a QGraphicsView which holds a QGraphicsScene
  scene = new DiagramScene(this);
  graphicsScene = scene->getScene();
  graphicsView = new QGraphicsView(graphicsScene);
  setCentralWidget(graphicsView);
  
  //Creates all widgets
  createButtonsandEdits();
  createLayout();
  createDockWindows();
  createActions();

  //Updates the count of chips to start the game 
  updateCompChips();
  updateHumanChips();
  updatePot();
}

//Creates buttons and the text boxes to display chip interaction
void Window::createButtonsandEdits()
{
  //Blank QLineEdit used for formatting
  lineEditBlank = new QLineEdit();
  lineEditBlank -> setVisible(false);

  //Used to set font for labels to display headers
  QFont f( "Arial", 11, QFont::Bold);

  //Header for player section
  lineEditPlayer = new QLabel();
  lineEditPlayer -> setText("Player");
  lineEditPlayer -> setAlignment(Qt::AlignCenter);
  lineEditPlayer -> setFont(f);

  //Header for computer section
  lineEditComputer = new QLabel();
  lineEditComputer -> setText("Computer");
  lineEditComputer -> setAlignment(Qt::AlignCenter);
  lineEditComputer -> setFont(f);
  
  //Betting button and line edit
  betButton = new QPushButton("Bet");
  lineEditBet = new QLineEdit;
  lineEditBet->setText("50");

  //Raise button and line edit
  raiseButton = new QPushButton("Raise");
  lineEditRaise = new QLineEdit;
  
  callButton = new QPushButton("Call");
 
  foldButton = new QPushButton("Fold");

  checkButton = new QPushButton("Check");
  
  //Human chips labels
  lineEditHumanChips = new QLabel;
  lineEditHumanChips->setText(" Chips Remaining: ");
  lineEditHumanChipCount = new QLabel;
     
  compActionButton = new QPushButton("Make Computer Action!");
  lineEditCompShow = new QLineEdit;
  
  //Comp chips labels
  lineEditCompChips = new QLabel;
  lineEditCompChips -> setText(" Chips Remaining: ");
  lineEditCompChipCount = new QLabel;
  
  //Pot chips labels
  lineEditPotChips = new QLabel;
  lineEditPotChips -> setText(" Pot Chip Count: ");
  lineEditShowPot = new QLabel;
}

//Creates a layout to store the buttons neatly in
//Adds multiple buttons/line edits to a row using addRow
void Window::createLayout()
{
  layout = new QFormLayout;
  
  layout->addRow(lineEditPlayer);
  layout->addRow(lineEditBlank);
  layout->addRow(betButton, lineEditBet);
  layout->addRow(raiseButton, lineEditRaise);
  layout->addRow(callButton, lineEditBlank);
  layout->addRow(checkButton, lineEditBlank);
  layout->addRow(foldButton, lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditHumanChips, lineEditHumanChipCount);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditComputer);
  layout->addRow(lineEditBlank);
  layout->addRow(compActionButton);
  layout->addRow(lineEditCompShow);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditCompChips, lineEditCompChipCount);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditBlank);
  layout->addRow(lineEditPotChips, lineEditShowPot);
}

//Creates a dock window to create interactivity with buttons
void Window::createDockWindows()
{
  QWidget *wi = new QWidget;
  wi->setLayout(layout);
  
  QDockWidget *dw = new QDockWidget(this);
  dw->setWidget(wi);
  addDockWidget(Qt::LeftDockWidgetArea, dw);
}

//Creates actions
//Every time a button is "clicked", connects to a function that runs
void Window::createActions()
{
  connect(betButton, SIGNAL(clicked()), this, SLOT(bet()));
  connect(raiseButton, SIGNAL(clicked()), this, SLOT(raise()));
  connect(callButton, SIGNAL(clicked()), this, SLOT(call()));
  connect(foldButton, SIGNAL(clicked()), this, SLOT(fold()));
  connect(checkButton, SIGNAL(clicked()), this, SLOT(check()));
  connect(compActionButton, SIGNAL(clicked()), this, SLOT(updateCompAction()));
}

//Shows the user what the computer's move was whenever the "Make Computer Move"
//button is clicked
void Window::updateCompAction()
{
  char str[60];
  int AIbet = scene->Holdem.AI.betamount;
  char choice = scene->Holdem.AI.choice;

  
  updatePot();
  updateCompChips();
  updateHumanChips();
  
if(scene->Holdem.AI.chips <=0) { choice = 'h'; scene->setCaseInt(20); }
else if (scene->Holdem.human.chips <=0) { choice = 'a'; scene->setCaseInt(20); } 

  //Decides what to display in computer move text box
  if (choice=='b') sprintf(str, "Computer bets %d", AIbet);
  else if (choice =='f') sprintf(str, "Computer folds!");
  else if (choice == 'p') sprintf(str, "Computer checks!");
  else if (choice == 'r') sprintf(str, "Computer raises %d", AIbet);
  else if (choice == 'c') sprintf(str, "Computer calls");
  else if (choice == 'w') sprintf(str, "Welcome to the game! Click again!");
  else if (choice == 'h') sprintf(str, "You win! Game over");
  else if (choice == 'a') sprintf(str, "AI wins! Game over");

  if (scene->getCaseInt() == -1) potsize = 0;
  updatePot();
  lineEditCompShow->setText(str);
  scene->update();
  graphicsScene->update();
  graphicsView->update();
  
  //Moves to next state if necessary
  //Function in DiagramScene
  if(scene->getCaseInt() == -1) scene->nextState ();
  else if(scene->getCaseInt() == 8) scene->nextState();
  
}

//Updates the text string for pot chips
void Window::updatePot()
{
  char str[50];
  int pot = potsize;
  sprintf(str, "  %d", pot);

  lineEditShowPot -> setText(str);
}
 
//Updates text string for comp chips
void Window::updateCompChips()
{
  char str[50];
  int chips = scene->Holdem.AI.chips;
  sprintf(str, "  %d", chips);

  lineEditCompChipCount -> setText(str);
}

//Updates text box for human chips
void Window::updateHumanChips()
{
  char str[50];
  int chips = scene->Holdem.human.chips;
  sprintf(str, "  %d", chips);

  lineEditHumanChipCount->setText(str);
}

//Function called when bet button's clicked
//calls bet() function in DiagramScene, updates graphics
void Window::bet()
{ 
  //if functions as safeguard
  if(scene->Holdem.AI.choice != 'r' && scene->Holdem.AI.choice != 'b') 
    {
      scene->bet(lineEditBet->text().toInt());
      updateHumanChips();
      scene->update();
      graphicsScene->update();
      graphicsView->update();
    }
}

//Called when raise button clicked
//Calls DiagramScene raise() function, updates chip textboxes
void Window::raise()
{
  int raiseamount;    
  if(scene->Holdem.AI.choice == 'r' || scene->Holdem.AI.choice == 'b') 
    {
      raiseamount = lineEditRaise->text().toInt();
      if(raiseamount > highbet) 
    {
      scene->raise(raiseamount);
      updateHumanChips();
      scene->update();
      graphicsScene->update();
      graphicsView->update();
    }// end check if raise is valid
    }// end check if available option
}// end function

//Called when call button clicked
//Calls DiagramScene call function, updates chips and updates scene
void Window::call()
{
if(scene->Holdem.AI.choice == 'r' || scene->Holdem.AI.choice == 'b') {
  scene->call();
  updateHumanChips();
  scene->update();
  graphicsScene->update();
  graphicsView->update();
}
}

//Same as others
void Window::fold()
{
  if(scene->Holdem.AI.choice != 'p')
    {
      scene->Holdem.human.choice='f';
      updateHumanChips();
      graphicsScene->update();
      graphicsView->update();
    }
}

//Same as others
void Window::check()
{
  if (scene->Holdem.AI.choice != 'r' && scene->Holdem.AI.choice != 'b') 
    {
      scene->check();
      updateHumanChips();
  }
}

void Window::closeEvent(QCloseEvent *event)
{
  delete graphicsScene;
  delete graphicsView;
  delete this;    
}

