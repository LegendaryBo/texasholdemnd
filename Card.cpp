#include "Card.h"

Card::Card(int n, const char *i)
{
  number = n;
  value = n%13;
  suit = n/13;
  cardname = i;
}

