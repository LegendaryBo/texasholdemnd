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

class player
{
public:
   player ();
  ~player ();
  double Rank ();		// rank function that takes player cards and community cards 
  string name;
  virtual void decision () = 0;	// different decision processes for human vs computer
  int bet (int);		// number of chips out on the table for the given Round of 
  int chips;
  char state;			// stores last decision for Round, 'n' if they haven't acted
  int betamount;		// get from button or computer
  deque < Card > holecards;
  double rank;
  char choice;

private:
  int findhigh (int);		// returns the 1st,2nd,... highest card 
  Card pair ();			// returns one of the Cards in the pair, if pair is found
  int twopair (Card);		// runs pair and looks for a different one 
  int trips ();			// returns one of the Cards in the set, if set is found
  int quads ();			// returns one of the Cards, if quads are found
  int straight ();
  int flush ();
  int fullhouse (Card);		// runs trips() and twopair(), if both then there is
   deque < Card > combined;	// combining player cards with community cards and ordering

};



// USER DERIVED CLASS-------------------------------------------
  class user:public player
  {
public:
    user() {
	name = "user";
	}
    void decision ()
    {
choice = 'x';
      if (highbet > 0)
	{
//	  display ('r', 'c', 'f');	// sets these options as visible to user
	  do
	    { }
	  while (choice != 'r' && choice != 'c' && choice != 'f');
	}
      else
	{
//	  display ('b', 'p', 0);	// if the other player didn't bet, can check or bet
	  do
	    { }
	  while (choice != 'b' && choice != 'p');
	}
/*
      state = choice;

      switch (choice)
	{
	case 'b':
	  bet (betamount);	// this is the amount stored in the betamount button
	  highbet = betamount;
//	  displaychoice ('b', betamount);	// DRAW CHOICE HERE
	  break;

	case 'c':
	  bet (highbet);
	  highbet = 0;
//	  displaychoice ('c', betamount);	// DRAW CHOICE HERE
	  break;

	case 'f':
//	  displaychoice ('f', 0);	// DRAW CHOICE HERE
	  break;

	case 'r':
	  bet (highbet);
	  bet (betamount);
	  highbet = betamount;
//	  displaychoice ('r', betamount);	// DRAW CHOICE HERE
	break;
	 case 'p':
//	  displaychoice ('p', 0);	// DRAW CHOICE HERE
	  break;
	}
*/
    }				// end function

  };



// COMPUTER DERIVED CLASS ------------------------------------------------
  class computer:public player
  {
public:
    computer() {
     name = "computer";
	}
    char AImove (char option)	// either (r,c,f) or (b,p,0)
    {
      srand (time (NULL));
      int number = rand () % 100;
      if (option == 'r')
	{
	  if (rank < 1.05)
	    {
	      if (number < 10)
		choice = 'c';
	      else if (number < 35)
		{
		  choice = 'b';
		  betamount = 2.5 * highbet;
		}
	      else
		  choice = 'f';
	    }
	  else if (rank < 3)
	    {
	      if (number < 75)
		{
		  if (highbet > 100 && number < 20)
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
		    betamount = 2.5 * highbet;
		}
	    }
	  else
	    {
	      if (number < 50 && Round != 4)
		choice = 'c';
	      else if (Round != 4)
		{
		  choice = 'r';
		  betamount = 2.5 * highbet;
		}
	      else
		{
		  choice = 'r';
		  betamount = chips;
		}
	    }
	}

      else if (option == 'b')
	{
	  if (rank < 1.05)
	    {
	      if (number < 30)
		{
		  choice = 'b';
		  betamount = 4 * bigblind;
		}
	      else if (number < 50)
		{
		  choice = 'b';
		  betamount = 2 * bigblind;
		}
	      else
		choice = 'p';
	    }
	  else if (rank < 3)
	    {
	      if (number < 50)
		{
		  choice = 'b';
	      betamount = 4 * bigblind;}
	      else if (number < 60)
		{
		  choice = 'b';
		  betamount = 6 * bigblind;
		}
	      else
		choice = 'p';
	    }
	  else
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
		  betamount = chips;
		}
	    }

	}
      return choice;

    }				// end AImove()


    void decision ()
    {
      char choice;

      if (highbet > 0)
	{
	  choice = AImove ('r');
	}
      else
	{
	  choice = AImove ('b');
	}

      state = choice;

      switch (choice)
	{
	case 'b':
	  bet (betamount);	// this is the amount stored in the betamount button
	  highbet = betamount;
//	  displaychoice ('b', betamount);	// DRAW CHOICE HERE
	  break;

	case 'c':
	  bet (highbet);
	  highbet = 0;
//	  displaychoice ('c', betamount);	// DRAW CHOICE HERE
	  break;

	case 'f':
//	  displaychoice ('f', 0);	// DRAW CHOICE HERE
	  break;

	case 'r':
	  bet (highbet);
	  bet (betamount);
	  highbet = betamount;
//	  displaychoice ('r', betamount);	// DRAW CHOICE HERE
	break;
	 case 'p':
//	  displaychoice ('p', 0);	// DRAW CHOICE HERE
	  break;
	}


    }



  };				// end class  deque < Card > holecards; // card class
#endif
