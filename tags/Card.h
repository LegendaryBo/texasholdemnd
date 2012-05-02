// texas holdem, cards

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;

class Card{

public:

Card(int = 0, const char* = "card");
 
const char *cardname;    //image file                   

int value;   // kings, aces, sixes, etc

int number;  //number of card in deck

int suit;   //diamond, clubs etc

};


#endif