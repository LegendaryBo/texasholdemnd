#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include "CardDeck.h"
#include "Card.h"
#include "player.h"



class game
{

public:
  game ();			//input is number of players
   ~game ();
  CardDeck Deck;		// need to add dealtop() member function to CardDeck
  deque < player* > position;	// can be ignored for now, but position of players rotates
  user human;
  computer AI;
  void winner ();		// if more than 1 player remains, uses rank function for each
  void newhand ();		// shuffles deck, clears potsize, clears community cards
  void rungame ();
  int play;			// when 1 game keeps going, when 0 games ends
  void dealallcards();
  void dealpreflop ();
  void dealflop ();
  void dealturn ();
  void dealriver ();
  int preflop ();		// returns 1 if more than 1 player remains
  int flop ();			// returns 1 if more than 1 player remains
  int turn ();			// returns 1 if more than 1 player remains
  int river ();			// returns 1 if more than 1 player remains
  void reset ();		// clear community/player cards, potsize=0; rotates position
};

#endif
