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
#include "Card.h"

using namespace std;

Card::Card(){
    //suit = rand()%((3 - 0) +1 )+ 0;
    suit = 0 + (rand()%3);
    //value  = rand()%((13 - 1) +1 ) +1;
    value = 1 + (rand()%13);
}
Card::Card(int suit, int value){
    Card::suit = suit;
    Card::value = value;
}

int Card::getValue(){
    return value;
}
int Card::getSuit(){
    return suit;
}
string Card::toString() const{
    string suit1;
    string value1;

    suit1 = getSuitAsString();
    value1 = getValueAsString();
    string of= " of ";
    string combo = value1 + of + suit1;
    return combo;
}
string Card::getSuitAsString() const{
    string suit1;
    int num = suit;
    if(num == 0){
        suit1 = "Clubs";
    }
    if(num == 1){
        suit1 = "Diamonds";
    }
    if(num == 2){
        suit1 = "Hearts";
    }
    if(num == 3){
        suit1 = "Spades";
    }
    return suit1;
}
string Card::getValueAsString() const{
    string value1;
    int num = value;
    if(num == 1){
        value1 = "Ace";
    }
    if(num == 2){
        value1 = "2";
    }
    if(num == 3){
        value1 = "3";
    }
    if(num == 4){
        value1 = "4";
    }
    if(num == 5){
        value1 = "5";
    }
    if(num == 6){
        value1 = "6";
    }
    if(num == 7){
        value1 = "7";
    }
    if(num == 8){
        value1 = "8";
    }
    if(num == 9){
        value1 = "9";
    }
    if(num == 10){
        value1 = "10";
    }
    if(num == 11){
        value1 = "Jack";
    }
    if(num == 12){
        value1 = "Queen";
    }
    if(num == 13){
        value1 = "King";
    }
    return value1;
}
bool Card::sameSuit(Card& other){
    if(this->getSuit() == other.getSuit()) return true;
    else return false;
}
bool Card::sameValue(Card& other){
    if(this->getValue() == other.getValue()) return true;
    else return false;
}

//Though not part of the class, define the operator ==  and the operator << for Cards.
//bool operator ==(Card& c1, Card& c2);
//ostream& operator <<(ostream& output, const Card& c);

bool operator==(Card& c1, Card& c2){
    if(c1.getValue()==c2.getValue()) return true;
    else return false;
}

ostream& operator <<(ostream& output, const Card& c){
    output << c.toString();
}