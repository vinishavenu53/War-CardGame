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

#ifndef WAR_DECK_H
#define WAR_DECK_H

#include<string>
#include<vector>
#include "Card.h"

int const SHUFFLE = 0;
using namespace std;

class Deck {
    private:
        vector<Card> myDeck;
        int top;
        int deckSize;
    public:
        Deck();
        void shuffle();
        Card& dealCard();
        int getTop();
        int getDeckSize();
        string toString();

};


#endif //WAR_DECK_H
