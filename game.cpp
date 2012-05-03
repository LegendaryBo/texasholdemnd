// Kevin Jacobs, Matt Brittan, Scott Aufderheide
// game.cpp
// includes basic game functions that deal with the cards on board and determining the hand winner
// also resets basic variables between hands
#include "game.h"

Game::Game ()
{
  position.push_back (&AI); // position vector keeps track of players' posiition
  position.push_back (&human);
  bigblind = 10;
}

Game::~Game ()
{
  delete this;
}

// clears basic variables including each players cards and shuffling deck
void
Game::reset ()
{
  potsize = 0;
  highbet = 0;
  community.clear ();
  human.choice = 'x'; // means they haven't made a move yet
  AI.choice = 'x';
  human.betamount = 0;
  AI.betamount = 0;
  human.holecards.clear ();
  AI.holecards.clear ();
  Deck.shuffle ();
}

// Deals all cards on table... they're just not visible yet
void
Game::dealallcards ()
{
// Deal holecards
  human.holecards.push_back (Deck.deal ());    // Deck.deal returns object of type Card
  human.holecards.push_back (Deck.deal ());    // Can add a function to add card to holecards
  AI.holecards.push_back (Deck.deal ());    // Could reference them as position[1],[2]
  AI.holecards.push_back (Deck.deal ());
  // Deal flop
  community.push_back (Deck.deal ());
  community.push_back (Deck.deal ());
  community.push_back (Deck.deal ());
  // Deal turn
  community.push_back (Deck.deal ());
  // Deal river
  community.push_back (Deck.deal ());
  
  human.rank = human.Rank();
  AI.rank = AI.Rank();
}

// simply sees which player has highest rank, gives winner(s) chips
void
Game::winner ()
{
  if(AI.choice == 'f') human.chips += potsize;
else if (human.choice == 'f') AI.chips += potsize;
 else if (human.Rank () > AI.Rank ())
   human.chips += potsize;
 else if (AI.Rank () > human.Rank ())
   AI.chips += potsize;
 else if (AI.Rank () == human.Rank ())  // case of tie
   {
     AI.chips += potsize / 2;
     human.chips += potsize / 2;
   }
  
}

