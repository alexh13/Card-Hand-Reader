/*
Alex Hughes
2/12/2019
Assignment 4.1

A a program that reads five (or more) cards from the user, then analyzes the cards and prints out the category of hand
that they represent.
*/


#include <iostream>
using namespace std;


const int cardNumLen = 8, cardHandLen = 5;


int max(const int cards[], const int num);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsStraight(const int hand[]);
bool checkRun(const int cards[], const int start);


int main() {
    int numArr[cardHandLen] = {0};

    cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n" << endl;

    for (int i = 0; i < cardHandLen; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> numArr[i];
    }
    

    if (containsFullHouse(numArr))
        cout << "Full House!" << endl;
    else if (containsStraight(numArr))
        cout << "Straight!" << endl;
    else if (containsThreeOfaKind(numArr))
        cout << "Three of a kind!" << endl;
    else if (containsTwoPair(numArr))
        cout << "Two Pair!" << endl;
    else if (containsPair(numArr))
        cout << "One Pair!" << endl;
    else {
        cout << "High!" << endl;
    }

    return 0;
}


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


bool containsThreeOfaKind(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 3;
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


bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}


bool containsStraight(const int hand[]) {
    int cards[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0}, run = 0;
    countCards(hand, cards);
    for(int i = 0; i < 13; i++) {
        if(checkRun(cards, i)) {
            return true;
        }
    }
    return false;
}


bool checkRun(const int cards[], const int start) {
    int run = 0;
    for(int i = start; i < start + 5; i++) {
        if(cards[i] == 0) {
            return false;
        }
    }
    return true;
}
