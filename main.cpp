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


const int cardNumLen = 8, cardHandLen = 5;


// declared functions
int max(const int cards[], const int num);
void countCards(const int hand[], int cards[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
string checkHand(const int hand[]);
void runGame();


// Main Program
int main() {
    runGame();

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


bool containsFourOfaKind(const int hand[]) {
    int cards[13] = {0};
    countCards(hand, cards);
    return max(cards, 13) == 4;
}


bool containsStraight(const int hand[]) {
    iint cards[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0}, run = 0;
    countCards(hand, cards);
    for(int i = 0; i < 13; i++) {
        if(checkRun(hand, i)) {
            return true;
        }
    }
    return false;
}


bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}




void runGame() {
    int numArr[cardHandLen] = {0};

    cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n" << endl;

    for (int i = 0; i < cardHandLen; i++) {
        cout << "Card " << i + 1 << ": ";
        int num;
        cin >> num;
    }

    if (containsFourOfaKind(hand))
        return "Four of a kind!";
    else if (containsFullHouse(hand))
        return "Full House!";
    else if (containsStraight(hand))
        return "Straight!";
    else if (containsThreeOfaKind(hand))
        return "Three of a kind!";
    else if (containsTwoPair(hand))
        return "Two Pair!";
    else if (containsPair(hand))
        return "One Pair!";
    else {
        return "High!";
    }


}

