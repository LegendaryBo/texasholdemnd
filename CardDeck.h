//texas holdem deck

#ifndef CARDDECK_H 
#define CARDSDECK_H

#include <deque>
#include <iomanip>
#include <iostream>
#include "Card.h"
using namespace std;

class CardDeck {

public:

CardDeck();

void shuffle();

Card deal();

int count;

deque<Card> deck;

vector<const char *> fileNames;


};

CardDeck::CardDeck(){

//Spades section
fileNames.push_back("aceSpades.png");
fileNames.push_back("twoSpades.png");
fileNames.push_back("threeSpades.png");
fileNames.push_back("fourSpades.png");
fileNames.push_back("fiveSpades.png");
fileNames.push_back("sixSpades.png");
fileNames.push_back("sevenSpades.png");
fileNames.push_back("eightSpades.png";
fileNames.push_back("nineSpades.png");
fileNames.push_back("tenSpades.png");
fileNames.push_back("jackSpades.png");
fileNames.push_back("queenSpades.png");
fileNames.push_back("kingSpades.png");

//Hearts Section
fileNames.push_back("aceHearts.png");
fileNames.push_back("twoHearts.png");
fileNames.push_back("threeHearts.png");
fileNames.push_back("fourHearts.png");
fileNames.push_back("fiveHearts.png");
fileNames.push_back("sixHearts.png");
fileNames.push_back("sevenHearts.png");
fileNames.push_back("eightHearts.png");
fileNames.push_back("nineHearts.png");
fileNames.push_back("tenHearts.png");
fileNames.push_back("jackHearts.png");
fileNames.push_back("queenHearts.png");
fileNames.push_back("kingHearts.png");

//Clubs section

fileNames.push_back("aceClubs.png");
fileNames.push_back("twoClubs.png");
fileNames.push_back("threeClubs.png");
fileNames.push_back("fourClubs.png");
fileNames.push_back("fiveClubs.png");
fileNames.push_back("sixClubs.png");
fileNames.push_back("sevenClubs.png");
fileNames.push_back("eightClubs.png");
fileNames.push_back("nineClubs.png");
fileNames.push_back("tenClubs.png");
fileNames.push_back("jackClubs.png");
fileNames.push_back("queenClubs.png");
fileNames.push_back("kingClubs.png");

//Diamonds section

fileNames.push_back("aceDiamonds.png");
fileNames.push_back("twoDiamonds.png");
fileNames.push_back("threeDiamonds.png");
fileNames.push_back("fourDiamonds.png");
fileNames.push_back("fiveDiamonds.png");
fileNames.push_back("sixDiamonds.png");
fileNames.push_back("sevenDiamonds.png");
fileNames.push_back("eightDiamonds.png");
fileNames.push_back("nineDiamonds.png");
fileNames.push_back("tenDiamonds.png");
fileNames.push_back("jackDiamonds.png");
fileNames.push_back("queenDiamonds.png");
fileNames.push_back("kingDiamonds.png");

                for(int i = 0; i<52; i++){   
                        Card crd(i, fileNames[i]);
                        deck.push_back(crd);
                }
        
}

void
CardDeck::shuffle ()
{
count = 0;
  random_shuffle (deck.begin (), deck.end ());  
}
Card 
CardDeck::deal(){

Card temp;

temp = deck[count];
count++;
deck.pop_front();
return temp;

}
#endif
