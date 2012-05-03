// Kevin Jacobs, Matt Brittan, Scott Aufderheide
// game.h
// includes players and deck as objects and contains basic functions that determine where cards should be dealt

#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include "CardDeck.h"
#include "Card.h"
#include "player.h"

extern deque < Card > community; // cards on board
extern int potsize; // size of pot
extern int highbet; // highest current bet
extern int bigblind; // gives computer a relative size of betting
extern int Round; // preflop = 1, flop = 2 ...


class Game
{

public:
  Game (); // constructor
  ~Game ();
  CardDeck Deck;  // the card deck        
  deque < Player* > position;//position of players rotates
  User human; // user 
  Computer AI; // computer
  void winner (); // if more than 1 player remains, uses rank function for each
  void dealallcards(); // deals cards
  void reset (); // clear community/player cards, potsize=0; rotates position
};

#endif
