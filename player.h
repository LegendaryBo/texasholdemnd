// Kevin Jacobs, Matt Brittan, Scott Aufderheide
// player.h 
// contains all variables relevant to each player, as well has the rank of his hand
// computer and human derive from this base class and use polymorphism because they use the decision function differently. The human's decision is actually decided mostly in the actual game

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <string>
#include "Card.h"

extern deque < Card > community;
extern int potsize;
extern int highbet;
extern int bigblind;
extern int Round;

using namespace std;

class Player
{
 public:
  Player ();
  ~Player ();
  double Rank (); // rank function that takes player cards and community cards 
  string name; // name of player
  virtual void decision () = 0;    // different decision processes for human vs computer
  int bet (int); // number of chips out on the table for the given Round of 
  int chips; // player's chips
  char state; // stores last decision for Round, 'n' if they haven't acted
  int betamount; // get from button or computer
  deque < Card > holecards; // players 2 cards
  double rank; // rank of hand
  char choice; // players last choice
  int findhigh (int); // returns the 1st,2nd,... highest card 

private:
  Card pair ();     // returns one of the Cards in the pair, if pair is found
  int twopair (Card); // runs pair and looks for a different one 
  int trips ();     // returns one of the Cards in the set, if set is found
  int quads ();    // returns one of the Cards, if quads are found
  int straight ();
  int flush ();
  int fullhouse (Card); // runs trips() and twopair(), if both then there is
  deque < Card > combined;// combining player cards with community cards and ordering

};



// USER DERIVED CLASS-------------------------------------------
  class User:public Player
  {
public:
    User() {
      name = "user";
      chips = 1000;
    }
    void decision ()
    {
      choice = 'x';
      
      state = choice;
      switch (state)
    {
    case 'b':
      bet (betamount);    // this is the amount stored in the betamount button
      highbet = betamount;
      break;
      
    case 'c':
      bet (highbet);
      highbet = 0;
      
      break;
      
    case 'r':
      bet (highbet);
      bet (betamount);
      highbet = betamount;
      break;
    }

    }                // end function
    
  };



// COMPUTER DERIVED CLASS ------------------------------------------------
class Computer:public Player
{
 public:
  Computer() {
    name = "computer";
    chips = 1000;
  }
  char AImove (char option)    // either (r,c,f) or (b,p,0)
  {
// generate random number from 1 to 100
    srand (time (NULL));
    int number = rand () % 100;
// find strength of hand
    rank = Rank();\
// vary choice/betamount based on available options (call/raise/fold vs check/bet) and strength of hand
    if (option == 'r')
      {
    if (rank < 1.1)   // small hand
      {
        if (number < 25)
          choice = 'c';
        else if (number < 40)
          {
        choice = 'r';
          betamount = 2.5 * highbet;
          }
        else
          choice = 'f';
      }
    else if (rank < 3)  // medium hand
      {
        if (number < 75)
        {
          if (highbet > 100 && number < 30)
            choice = 'f';
          else
            choice = 'c';
        }
        else      
          {
        choice = 'r';
        if (.8 * chips < highbet)
          betamount = chips;
        else
          betamount = 2 * highbet;
          }
      }
    else            // big hand
      {
        if (number < 50 && Round != 4)
          choice = 'c';
        else if (Round != 4)
          {
        choice = 'r';
        betamount = 2 * highbet;
          }
        else
          {
        choice = 'r';
        betamount = chips/2;
          }
      }
      }
    
    else if (option == 'b')
      {
    if (rank < 1.1)     // small hand
      {
        if (number < 20)
          {
        choice = 'b';
        betamount = 4 * bigblind;
          }
        else if (number < 40)
          {
        choice = 'b';
        betamount = 2 * bigblind;
          }
        else
          choice = 'p';
      }
    else if (rank < 3)    // medium hand
      {
        if (number < 35)
          {
        choice = 'b';
        betamount = 4 * bigblind;}
        else if (number < 55)
          {
        choice = 'b';
        betamount = 6 * bigblind;
          }
        else
          choice = 'p';
      }
    else            // big hand
      {
        if (number < 35 && Round != 4)
          choice = 'p';
        else if (number < 70 && Round != 4)
          {
        choice = 'b';
        betamount = 4 * bigblind;
          }
        else if (Round != 4)
          {
        choice = 'b';
        betamount = 6 * bigblind;
          }
        else
          {
        choice = 'b';
        betamount = chips/2;
          }
      }
    
      }
    return choice;
    
  }                // end AImove()
  
  // decision finds AI's decision and then acts upon it
  void decision ()
  {
// find choice
    if (highbet > 0)
      {
    choice = AImove ('r');
      }
    else
      {
    choice = AImove ('b');
      }

    state = choice;
// make apporopriate actions based off of choice
    switch (choice)
    {
    case 'b':
      bet (betamount);    // this is the amount stored in the betamount button
      highbet = betamount;
      break;
      
    case 'c':
      bet (highbet);
      highbet = 0;
      break;
      
    case 'f':
      break;
      
    case 'r':
      bet (highbet);
      bet (betamount);
      highbet = betamount;
      break;
      
    case 'p':
      break;
    }    
  }
  
  
}; 

#endif
