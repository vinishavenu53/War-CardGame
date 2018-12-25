//
// Created by vinis on 11/18/2018.
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
#include<iostream>

#include "Deck.h"
#include "Hand.h"


using namespace std;

int main() {

    Hand player1;
    Hand player2;
    vector<Card> p1;
    vector<Card> p2;
    Deck myDeck;
    //myDeck.Deck();
    myDeck.shuffle();

    //vector<Card>::iterator it = myDeck.getTop();
    //Card var = myDeck.dealCard();
    while(player1.getSize() != 26 && player2.getSize() !=  26){
        //Card var = myDeck.dealCard();
        player1.addCard(myDeck.dealCard()); //getNext... probably not that is for Hand
        //player1.size++; //increase size..........is this needed... how does increase in size updated
        player2.addCard(myDeck.dealCard());
        //player2.size++;//...........same as above
    }

    cout << "Hand of Player 1:";
    cout <<player1.toString()<< endl;
    cout << "\nHand of Player 2:";
    cout <<player2.toString() << endl;

    int rounds = 0;
    int wars =0;

    while(player1.getSize() >= 0 || !player2.getSize()>=0 || rounds<5000){
        rounds++;
        //int index1 = player1.getTop();
      //  int index2 = player2.getTop();

        Card hold1 = player1.getNext();

        Card hold2 = player2.getNext();

        if(hold1.getValue() == 1 && hold2.getValue() != 1){
            player1.addCard(hold1);
            player1.addCard(hold2);
        }

        else if( hold2.getValue() == 1 && hold1.getValue() != 1){
            player2.addCard(hold2);
            player2.addCard(hold1);
        }

        else if(hold1.getValue() > hold2.getValue()){
            player1.addCard(hold1);
            player1.addCard(hold2); //hold2
        }
        else if(hold1.getValue() < hold2.getValue()){
            player2.addCard(hold2);
            player2.addCard(hold1);
        }
        else if(hold1.getValue() == hold2.getValue()) {
            wars++;

            //if(( player1.getSize() !=0 || player2.getSize() != 0)) {
                while (hold1.getValue() == hold2.getValue()) {
                    if(( player1.getSize() <=0 || player2.getSize() <= 0)) break;
                    //int vari = player1.getSize();
                    p1.insert(p1.begin(),hold1);
                    p2.insert(p2.begin(),hold2);

                    hold1 = player1.getNext(); //face down
                    p1.insert(p1.begin(),hold1);

                    hold2 = player2.getNext(); //face down
                    p2.insert(p2.begin(),hold2);

                    if(( player1.getSize() <=0 || player2.getSize() <= 0)) break;

                    hold1 = player1.getNext();
                    hold2 = player2.getNext();

                    if(( player1.getSize() <=0 || player2.getSize() <= 0)) break;

                    if(hold1.getValue() ==1 && hold2.getValue() != 1){
                        p1.insert(p1.begin(),hold1);
                        p2.insert(p2.begin(),hold2);

                        while (!p1.empty()) {
                            player1.addCard(p1[0]);
                            p1.erase(p1.begin());
                        }
                        while (!p2.empty()) {
                            player1.addCard(p2[0]);
                            p2.erase(p2.begin());
                        }
                    }

                    else if (hold1.getValue() > hold2.getValue()) {
                        p1.insert(p1.begin(),hold1);
                        p2.insert(p2.begin(),hold2);

                        while (!p1.empty()) {
                            player1.addCard(p1[0]);
                            p1.erase(p1.begin());
                        }
                        while (!p2.empty()) {
                            player1.addCard(p2[0]);
                            p2.erase(p2.begin());
                        }

                    }
                    else if(hold2.getValue() ==1 && hold1.getValue() != 1){
                        p1.insert(p1.begin(),hold1);
                        p2.insert(p2.begin(),hold2);

                        while (!p2.empty()) {
                            player2.addCard(p2[0]);
                            p2.erase(p2.begin());
                        }
                        while (!p1.empty()) {
                            player2.addCard(p1[0]);
                            p1.erase(p1.begin());
                        }
                    }
                    else if (hold1.getValue() < hold2.getValue()) {
                        p1.insert(p1.begin(),hold1);
                        p2.insert(p2.begin(),hold2);

                        while (!p2.empty()) {
                            player2.addCard(p2[0]);
                            p2.erase(p2.begin());
                        }
                        while (!p1.empty()) {
                            player2.addCard(p1[0]);
                            p1.erase(p1.begin());
                        }

                    }
                }

        }
        if(player1.getSize() <= 0 || player2.getSize() <=0) break;

    }

    string winner;
    if(rounds < 5000) {
        if(player2.isEmpty()) winner = "\nPlayer 1"; //if the vector is empty
        if(player1.isEmpty()) winner = "\nPlayer 2";
        cout << winner << " lost after " << rounds << " rounds." << endl;
        cout << "There were " << wars << " wars." << endl;
    }
    else{
        cout << "The game was a draw after 5000 rounds." <<endl;
        cout << "There were 52 wars." << endl;
    }
}