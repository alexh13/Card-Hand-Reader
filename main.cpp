/*
Alex Hughes
2/12/2019
Assignment 4.1

A a program that reads five (or more) cards from the user, then analyzes the cards and prints out the category of hand
that they represent.
*/


#include <iostream>
#include <string>

using namespace std;


// Assignment 4.1
// Testing if there is a number in our lengths array

int max(const int cards[], const int num) {
    int max = 0;
    for(int i = 0; i < num; i++) {
        if(cards[i] > max) {
            max = cards[i];
        }
    }
    return max;
}


void countCards(const int hand[], int cards[]) {
    for(int i = 0; i < 5; i++) {
        ++cards[hand[i] - 1];
    }
}


bool containsPair(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 2;
}

bool containsTwoPair(const int hand[]) {
    int cards[13] = {0}, pairs = 0;
    for(int i = 0; i < 5; i++) {
        if(++cards[hand[i] - 1] == 2) {
            pairs++;
        }
    }
    return (pairs == 2) && max(cards, 13) == 2;
}


bool containsThreeOfaKind(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 3;
}



//bool containsStraight(const int hand[]) {

//}

bool containsFullHouse(const int hand[]) {
    return containsTwoPair(hand) && containsThreeOfaKind(hand);
}

// check for 4 of the same number
//bool containsFourOfaKind(const int hand[]) {

//}


int main() {
    int hand[] = {2, 2, 5, 5, 6};

    if (containsTwoPair(hand)) {
        cout << "contains a two pair" << endl;
    }

    else
        cout << "no" << endl;
}