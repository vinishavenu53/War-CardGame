//
// Created by vinis on 11/15/2018.
//
//
// EE 312 Project 9 -- The Game of War

/* Student information for project:
 *
 *
 * On my honor, Vinisha Venugopal, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Vinisha Venugopal
 * email address: vinishvenu@utexas.edu
 * UTEID: vv6523
 * Section 5 digit ID: 16205
 * Number of slip days used on this assignment: 0
 */
#include<cstdlib>
#include<time.h>
#include <algorithm>

#include "Deck.h"

Deck::Deck(){
    top = 0;
    deckSize =52;
    int value[13] ={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int suit[4] = {0,1,2,3};
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 14; j++){
            myDeck.push_back(Card(i,j));
        }
    }

}

void Deck::shuffle(){
    srand(62);
    Card hold;
    for(int i = 0; i < SHUFFLE; i++){
        int ind1 = 0, ind2 = 0;
        ind1 = rand()%(deckSize+top);
        ind2 = rand()%(deckSize+top);
        hold = myDeck[ind1];
        myDeck[ind1] = myDeck[ind2];
        myDeck[ind2] = hold;

    }

}


Card& Deck::dealCard(){
    vector<Card>::iterator it = myDeck.begin()+top;
    Card hold;
    hold = (*it);
    top++;
    deckSize--;
    return (*it);
}


int Deck::getTop() {
    return top;
}

int Deck::getDeckSize() {
    return deckSize;
}

string Deck::toString(){ // to use the ostream function
    vector<Card>::iterator it = myDeck.begin();
    string deckString;
    for(it; it != myDeck.end(); it++){
        deckString = it->toString();
    }
    return deckString;
}
