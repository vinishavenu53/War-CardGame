//
// Created by vinis on 11/18/2018.
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
#ifndef WAR_HAND_H
#define WAR_HAND_H


#include<string>
#include<vector>
#include "Card.h"

using namespace std;

class Hand {
private:
    int size;
    int top;
    vector<Card> myHand;
public:
    Hand();
    int getSize();
    string toString();
    int getTop();
    bool isEmpty();
    void addCard(Card& c);
    Card& getNext();
};

#endif //WAR_HAND_H
