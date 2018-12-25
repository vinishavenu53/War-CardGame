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
#include "Hand.h"


using namespace std;

Hand::Hand(){
    top=-1; //top =0 index 0
    size=0;
}

int Hand::getSize(){
    return size;
}

string Hand::toString(){ //
    string hold;
    vector<Card>::iterator it = myHand.begin();
    for(it; it != myHand.end(); it++){
        hold = hold + "\n" + it->toString();
    }
    return hold;
}

int Hand::getTop(){
    return top;
}

bool Hand::isEmpty() {
   if(size <= 0){
       return false;
   }
    return true;
}

void Hand::addCard(Card &c) {
    //myHand.insert(myHand.end(), c);
    myHand.push_back(c);
    size++;
}

Card& Hand::getNext() {
    top++;
    size--;

    return myHand[top];
}