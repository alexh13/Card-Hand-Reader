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


#include <iostream>
using namespace std;

const int cardNumLen = 8, cardHandLen = 5;

int max(const int cards[], const int num);
bool isPair(const int hand[]);
bool is2Pair(const int hand[]);
bool is3OfKind(const int hand[]);
bool isFullHouse(const int hand[]);
bool isStraight(const int hand[]);
bool checkRun(const int cards[], const int start);

int main() {
    int numArr[cardHandLen] = {0};

    cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n" << endl;

    for (int i = 0; i < cardHandLen; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> numArr[i];
    }
    
    //int hand[5] = {2, 3, 4, 5, 6};
    std::cout << "Pair:      " << (isPair(numArr) ? "yes" : "no") << "\n";
    std::cout << "2 Pair:    " << (is2Pair(numArr) ? "yes" : "no") << "\n";
    std::cout << "Straight:  " << (isStraight(numArr) ? "yes" : "no") << "\n";
    std::cout << "3 of kind: " << (is3OfKind(numArr) ? "yes" : "no") << "\n";
    std::cout << "Fullhouse: " << (isFullHouse(numArr) ? "yes" : "no") << "\n";

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

bool isPair(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 2;
}

bool is3OfKind(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 3;
}

bool is2Pair(const int hand[]) {
    int cards[13] = {0}, pairs = 0;
    for(int i = 0; i < 5; i++) {
        if(++cards[hand[i] - 1] == 2) {
            pairs++;
        }
    }
    return (pairs == 2) && max(cards, 13) == 2;
}

bool isFullHouse(const int hand[]) {
    return isPair(hand) && is3OfKind(hand);
}

bool isStraight(const int hand[]) {
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
