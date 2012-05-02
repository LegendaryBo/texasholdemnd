//texas holdem deck

#ifndef CARDDECK_H 
#define CARDDECK_H

#include <deque>
#include <iomanip>
#include <string>
#include <iostream>
#include "Card.h"
#include <vector>
 #include <algorithm>
using namespace std;

class CardDeck {

public:

CardDeck();

void shuffle();

Card deal();

int count;

deque<Card> deck;

vector<const char*> fileNames;
 

};


#endif