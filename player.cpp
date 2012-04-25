#include "player.h"


player::player ()
{
  chips = 1000;
}

player::~player()
{
delete this;
}



double
player::Rank ()
{
  //them from smallest to greatest in value // these are ordered in the findhigh function
  for (int i = 0; i < 5; i++)
    combined.push_back (community[i]);
  for (int i = 0; i < 2; i++)
    combined.push_back (holecards[i]);
  Card Pair = pair ();
  if (Pair.value != -1)
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
  return rank;
}


int
player::bet (int bettotal)
{
  if (bettotal > chips)
    betamount = chips;		// cant bet more than you have
  chips -= betamount;
  potsize += betamount;
  return chips;
}

int
player::findhigh (int high)
{
// sort:
  int j;
  Card temp(0);
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
  return combined[7 - high].value;
}


Card player::pair ()
{
  Card high(0);
  high.value = -1;
  double
    tempRank = 0;
  for (int i = 0; i < 6; i++)
    {
      if (combined[i].value == combined[i + 1].value)
	high = combined[i];
    }
  if (high.value != -1)
    tempRank = 1 + double (high.value) /
  100 + double (findhigh (3)) /
  10000 + double (findhigh (4)) /
  1000000 + double (findhigh (5)) /
    100000000;
  else
  tempRank = double (findhigh (1)) /
  100 + double (findhigh (2)) /
  10000 + double (findhigh (3)) /
  1000000 + double (findhigh (4)) /
  100000000 + double (findhigh (5)) /
    10000000000;

  if (tempRank > rank)
    rank = tempRank;
  return high;
}

int
player::twopair (Card pair)
{
  double tempRank = 0;
  Card high;
  high.value = -1;
  for (int i = 0; i < 6; i++)
    {
      if ((combined[i].value == combined[i + 1].value)
	  && (combined[i].value != pair.value))
	high = combined[i];
    }
  if (high.value == -1)
    return 0;			// two pair not found
  else
    {
      if (high.value > pair.value)
	tempRank =
	  2 + double (high.value) / 100 + double (pair.value) / 10000 +
	double (findhigh (5)) / 1000000;
      else
      tempRank =
	2 + double (pair.value) / 100 + double (high.value) / 10000 +
	double (findhigh (5)) / 1000000;
    }
  if (tempRank > rank)
    rank = tempRank;
  return 1;
}

int
player::trips ()
{
  double tempRank = 0;
  Card high;
  high.value = -1;
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
      else
	tempRank = 3 + double (high.value) / 100 + double (findhigh (4)) / 10000 + double (findhigh (5)) / 1000000;	// othercards() wont work, digits off
      if (tempRank > rank)
	rank = tempRank;
      return 1;
}


  int player::quads ()
  {
    double tempRank = 0;
    Card high;
    high.value = -1;
    for (int i = 0; i < 4; i++)
      {
	if (combined[i].value == combined[i + 1].value &&  combined[i + 1].value==
	    combined[i + 2].value && combined[i + 2].value == combined[i + 3].value)
	  high = combined[i];
      }
    if (high.value == 0)
      return 0;
    else {
      tempRank =
	7 + double (high.value) / 100 + double (findhigh (5)) / 10000; }
    if (tempRank > rank)
      rank = tempRank;
    return 1;
  }

  int player::straight ()
  {
    double tempRank = 0;
    int total = 1;
    Card high;
    high.value = -1;
    for (int i = 0; i < 3; i++)
      {
	if (combined[i].value == combined[i + 1].value - 1)
	  {
	    total++;
	    high = combined[i + 1];
	  }
	else if (total < 5 && combined[i].value != combined[i + 1].value)
	  total = 1;
      }				// does nothing of adjacent cards are equal
    if (total > 4)
      tempRank = 4 + double (high.value / 100);
    else
    return 0;

    if (tempRank > rank)
      rank = tempRank;
    return 1;

  }

  int player::flush ()
  {
    double tempRank = 0;
    int total;
    Card high;
    for (int i = 0; i < 4; i++)
      {
	total = 0;
	for (int i = 0; i < 7; i++)
	  {
	    if (combined[i].suit == i)
	      {
		total++;
		high = combined[i];
	      }
	  }
	if (total > 4)
	  tempRank = 5 + double (high.value / 100);
      }
    if (tempRank < 5)
      return 0;
    if (tempRank > rank)
      {
	rank = tempRank;
      }
    return 1;
  }

  int player::fullhouse (Card Pair)
  {
    double tempRank = 0;
    if (twopair (Pair) && trips ())
      tempRank = 6.1;
    else return 0;
    if (tempRank > rank)
      rank = tempRank;
    return 1;
  }


