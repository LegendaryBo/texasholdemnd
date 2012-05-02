#include "game.h"

game::game ()
{
  position.push_back (&AI);
  position.push_back (&human);
  bigblind = 10;
}

game::~game ()
{
delete this;
}

// runs newhand until user wants to stop or game is over
void
game::rungame ()
{
  play = 1;

 while (play == 1 && human.chips > 0 && AI.chips > 0)
    {
      newhand ();
    }

}

void
game::newhand ()
{
  reset ();
  dealallcards ();
  if (preflop ())
    if (flop ())
      if (turn ())
    river ();
      else
    winner ();
    else
      winner ();
  else
    winner ();

}

void
game::reset ()
{
  potsize = 0;
  highbet = 0;
  community.clear ();
  human.choice = 'x';        // means they haven't made a move yet
  AI.choice = 'x';
  human.betamount = 0;
  AI.betamount = 0;
  human.holecards.clear ();
  AI.holecards.clear ();
  Deck.shuffle ();
}

void
game::dealallcards ()
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

int
game::preflop ()
{
  Round = 0;
  position[0]->bet (bigblind);
  position[1]->bet (bigblind);

// Round of betting, skipping two players who posted blinds and asking them last
  position[0]->decision ();
  position[1]->decision ();

  int turn = 1;
  while (position[turn]->state == 'r' || position[turn]->state == 'b')
    {
      if (turn == 1)
    turn = 0;        // flip to other player
      else if (turn == 0)
    turn = 1;
      position[turn]->decision ();
// check if all in and other person calls, if calls all in ... if so see next cards and break out of loop , could do this in if statement below
    }

// check if only one player is left
  if (human.state == 'f' || AI.state == 'f')
    return 0;
  else
    return 1;
}


int
game::flop ()
{
  Round = 1;
 // display (2);

// Round of betting, skipping two players who posted blinds and asking them last
  position[0]->decision ();
  position[1]->decision ();

  int turn = 1;
  while (position[turn]->state == 'r' || position[turn]->state == 'b')
    {
      if (turn == 1)
    turn = 0;        // flip to other player
      else if (turn == 0)
    turn = 1;
      position[turn]->decision ();
// check if all in and other person calls, if calls all in ... if so see next cards and break out of loop , could do this in if statement below
    }

// check if only one player is left
  if (human.state == 'f' || AI.state == 'f')
    return 0;
  else
    return 1;
}


int
game::turn ()
{
  Round = 2;
//  display (3);d

// Round of betting, skipping two players who posted blinds and asking them last
  position[0]->decision ();
  position[1]->decision ();

  int turn = 1;
  while (position[turn]->state == 'r' || position[turn]->state == 'b')
    {
      if (turn == 1)
    turn = 0;        // flip to other player
      else if (turn == 0)
    turn = 1;
      position[turn]->decision ();
// check if all in and other person calls, if calls all in ... if so see next cards and break out of loop , could do this in if statement below
    }

// check if only one player is left
  if (human.state == 'f' || AI.state == 'f')
    return 0;
  else
    return 1;
}

int
game::river ()
{
  Round = 3;
//  display (4);

// Round of betting, skipping two players who posted blinds and asking them last
  position[0]->decision ();
  position[1]->decision ();

  int turn = 1;
  while (position[turn]->state == 'r' || position[turn]->state == 'b')
    {
      if (turn == 1)
    turn = 0;        // flip to other player
      else if (turn == 0)
    turn = 1;
      position[turn]->decision ();
// check if all in and other person calls, if calls all in ... if so see next cards and break out of loop , could do this in if statement below
    }

// check if only one player is left
  if (human.state == 'f' || AI.state == 'f')
    return 0;
  else
    return 1;

}



// simply sees which player has highest rank, gives winner(s) chips
void
game::winner ()
{
if(AI.choice == 'f') human.chips += potsize;
else if (human.choice == 'f') AI.chips += potsize;
else if (human.Rank () > AI.Rank ())
    human.chips += potsize;
else if (AI.Rank () > human.Rank ())
    AI.chips += potsize;
else if (AI.Rank () == human.Rank ())
    {
      AI.chips += potsize / 2;
      human.chips += potsize / 2;
    }

}

