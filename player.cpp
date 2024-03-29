// Kevin Jacobs, Matt Brittan, Scott Aufderheide
// player.cpp
// this file contains a bet function and all other functions are called from rank() which deals with the strength of the player's hand
#include "player.h"

Player::Player ()
{
  chips = 1000; // initialize number of chips for each player
}

Player::~Player ()
{
  delete this;
}


// assigns a rank from ~0.030201 (very low cards) to 8(straight flush)
// for example a pair of 5's with an 8, 7, and queen would be 1.05120807
// two pair would be 2.(5th best card) and so on 
double
Player::Rank ()
{
  rank = 0;
  //takes all cards (player + community) and orders them from smallest to greatest in value
  for (int i = 0; i < 5; i++)
    combined.push_back (community[i]);
  for (int i = 0; i < 2; i++)
    combined.push_back (holecards[i]);
// sort cards:
  int j;
  Card temp (0);
  for (int i = 0; i < 7; i++)
    {
      j = i;
      while (j > 0 && combined[j - 1].value > combined[j].value)
    {
      temp = combined[j];
      combined[j] = combined[j - 1];
      combined[j - 1] = temp;
      j--;
    }
    }
  Card Pair = pair ();  // check for pair
  if (Pair.value != -1) // if there is a pair, check for other possibilities
    {
      twopair (Pair);
      trips ();
      quads ();
      fullhouse (Pair);
    }
  straight ();  
  flush ();
  if (straight () && flush ())
  rank = 8; 
  combined.clear ();
  return rank; // each function checks if the rank assigned by that function is greater than the previous rank and if it is, the new rank value is assigneed
}

// this function checks to make sure player's bet is valid and moves bet from his stack to the pot
int
Player::bet (int bettotal)
{
  if (bettotal > chips)
    bettotal = chips;        // cant bet more than you have
  betamount = bettotal;
  chips -= betamount;
  potsize += betamount;
  return chips;
}

// returns the value of the nth best card
int
Player::findhigh (int high)
{
  return combined[7 - high].value;
}


Card Player::pair ()
{
  Card
  high (0);
  high.value = -1;
  double
    thirdCard = 0;
  double
    fourthCard = 0;
  double
    fifthCard = 0;
  double
    tempRank = 0;

// go through deque of player's available cards and see if 2 adjacent cards are equal
  for (int i = 0; i < 6; i++)
    {
      if (combined[i].value == combined[i + 1].value)
    high = combined[i];
    }
// if pair is found, find the best 3 cards that aren't included in the pair
  if (high.value != -1)
    {
      if (findhigh (1) == high.value)
    {
      thirdCard = findhigh (3);
      fourthCard = findhigh (4);
      fifthCard = findhigh (5);
    }
      else if (findhigh (2) == high.value)
    {
      thirdCard = findhigh (1);
      fourthCard = findhigh (4);
      fifthCard = findhigh (5);
    }
      else if (findhigh (3) == high.value)
    {
      thirdCard = findhigh (1);
      fourthCard = findhigh (2);
      fifthCard = findhigh (5);
    }
      else if (findhigh (4) == high.value)
    {
      thirdCard = findhigh (1);
      fourthCard = findhigh (2);
      fifthCard = findhigh (3);
    }
      tempRank = 1 + double (high.value) /
      100 + double (thirdCard) /
      10000 + double (fourthCard) /
      1000000 + double (fifthCard) /
    100000000;
    }
  else
    tempRank = double (findhigh (1)) /
  100 + double (findhigh (2)) /
  10000 + double (findhigh(3)) /
  1000000 + double (findhigh(4)) /
  100000000 + double (findhigh(5)) /
    10000000000;

  if (tempRank > rank)
    rank = tempRank;
  return high;
}

// find a 2nd pair that is different from the first pair found (Pair)
int
Player::twopair (Card pair)
{
  double tempRank = 0;
  double fifthcard = 0;
  Card high;
  high.value = -1;
  for (int i = 0; i < 6; i++)
    {
      if ((combined[i].value == combined[i + 1].value)
      && (combined[i].value != pair.value))
    high = combined[i];
    }
  if (high.value == -1)
    return 0;            // two pair not found
  else
    {
      for (int i = 1; i < 6; i++)
    {
      if (findhigh (i) != high.value && findhigh (i) != pair.value)
        fifthcard = findhigh (i);
    }
      if (high.value > pair.value)
    tempRank =
      2 + double (high.value) / 100 + double (pair.value) / 10000 +
    double (fifthcard) / 1000000;
      else
      tempRank =
    2 + double (pair.value) / 100 + double (high.value) / 10000 +
    double (fifthcard) / 1000000;
    }
  if (tempRank > rank)
    rank = tempRank;
  return 1;
}

// looks for 3 adjacent cards to be equal
int
Player::trips ()
{
  double tempRank = 0;
  Card high;
  high.value = -1;
  double fourthcard = -1;
  double fifthcard = -1;
  for (int i = 1; i < 6; i++)
    {
      if (combined[i - 1].value == combined[i].value
      && combined[i].value == combined[i + 1].value)
    {
      high = combined[i];
    }
    }
  if (high.value == -1)
    return 0;
// if trips are found, find 2 next best cards
  else
    {
      for (int i = 1; i < 6; i++)
    {
      if (fourthcard == -1 && findhigh (i) != high.value)
        fourthcard = findhigh (i);
      else if (findhigh (i) != fourthcard && fourthcard != -1 && findhigh (i) != high.value)
        fifthcard = findhigh (i);
    }
      tempRank = 3 + double (high.value) / 100 + (fourthcard) / 10000 + (fifthcard) / 1000000;    // othercards() wont work, digits off
      if (tempRank > rank)
    rank = tempRank;
      return 1;
    }
}

// looks for 4 adjacent cards to be equal
int
Player::quads ()
{
  double tempRank = 0;
  Card high;
  double fifthcard = -1;
  high.value = -1;
  for (int i = 0; i < 4; i++)
    {
      if (combined[i].value == combined[i + 1].value
      && combined[i + 1].value == combined[i + 2].value
      && combined[i + 2].value == combined[i + 3].value)
    high = combined[i];
    }
  if (high.value == -1)
    return 0;
  else
    {
if(findhigh(1) == high.value) fifthcard = findhigh(5);
else fifthcard = findhigh(1);
      tempRank =
    7 + double (high.value) / 100 + double (fifthcard) / 10000;
    }
  if (tempRank > rank)
    rank = tempRank;
  return 1;
}

// looks for 5 cards that are within 1 of eachother
int
Player::straight ()
{
  double tempRank = 0;
  int total = 1;
  Card high;
  high.value = -1;
  bool AcePresent = 0;
for(int i = 0; i < 7; i++) {
if(combined[i].value == 12) AcePresent = 1;
}

  for (int i = 0; i < 6; i++)
    {
      if (combined[i].value == combined[i + 1].value - 1)
    {
      total++;
      high = combined[i + 1];
    }
// this is so that A2345 is recognized as a straight
      else if (combined[i].value == 3 && AcePresent && (combined[i-1].value == 2 || combined[i-1].value == 3)) {
      total++;
      high.value = 12;
      AcePresent = 0;
    }
      else if (total < 5 && combined[i].value != combined[i + 1].value)
    total = 1;
      else if (total > 4 && combined[i].value != combined[i+1].value) break;
    }    

  if (total > 4)
    tempRank = 4 + double (high.value) / 100;
  else
  return 0;

  if (tempRank > rank)
    rank = tempRank;
  return 1;

}

// check if there are 5 cars of same suit
int
Player::flush ()
{
  double tempRank = 0;
  int total;
  Card high;
  for (int i = 0; i < 4; i++)
    {
      total = 0;
      for (int j = 0; j < 7; j++)
    {
      if (combined[j].suit == i)
        {
          total++;
          high = combined[j];
        }
    }
      if (total > 4)
    {tempRank = 5 + double (high.value) / 100; break;}
    }
  if (tempRank < 5)
    return 0;

      rank = tempRank;

  return 1;
}

// if there is 2 pair and trips, must be full house
int
Player::fullhouse (Card Pair)
{
  double tempRank = 0;
  if (twopair (Pair) && trips ())
    tempRank = 6.1;
  else
    return 0;
  if (tempRank > rank)
    rank = tempRank;
  return 1;
}
