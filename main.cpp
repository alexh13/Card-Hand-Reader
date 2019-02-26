/*
Alex Hughes
2/12/2019
Assignment 4.1

A  program that reads five (or more) cards from the user, then analyzes the cards and prints out the category of hand
that they represent. The user runs program and is asked for card numbers, 1 through 5. Once the user enters that data
the program goes through every function to determine the highest possible hand that they have.
*/


#include <iostream>
using namespace std;


const int cardNumLen = 8, cardHandLen = 5;


int max(const int cards[], const int num);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsFourOfAKind(const int hand[]);
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
    else if (containsFourOfAKind(numArr))
        cout << "Four of a kind!" << endl;
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


// helper functions
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


bool checkRun(const int cards[], const int start) {
    for(int i = start; i < start + cardHandLen; i++) {
        if(cards[i] == 0) {
            return false;
        }
    }
    return true;
}


// Hand checking functions
bool containsPair(const int hand[]) {
    int cards[cardNumLen] = {0};
    countCards(hand, cards);
    for(int i = 0; i < cardNumLen; i++) {
        if (cards[i] == 2)
            return true;

    }
    return false;
}


bool containsTwoPair(const int hand[]) {
    int cards[cardNumLen] = {0}, pairs = 0;
    for(int i = 0; i < cardHandLen; i++) {
        if(++cards[hand[i] - 2] == 2) {
            pairs++;
        }
    }
    return (pairs == 2) && max(cards, cardNumLen) == 2;
}


bool containsThreeOfaKind(const int hand[]) {
    int cards[cardNumLen] = {0};
    countCards(hand, cards);
    return max(cards, cardNumLen) == 3;
}


bool containsFourOfAKind(const int hand[]) {
    int cards[cardNumLen] = {0};
    countCards(hand, cards);
    return max(cards, cardHandLen) == 4;
}


bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}


bool containsStraight(const int hand[]) {
    int cards[cardNumLen] = {0};
    countCards(hand, cards);
    for(int i = 0; i < cardNumLen; i++) {
        if(checkRun(cards, i)) {
            return true;
        }
    }
    return false;
}


// Output:
/*
Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 2
Card 3: 3
Card 4: 4
Card 5: 8
One Pair!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 2
Card 3: 3
Card 4: 3
Card 5: 5
Two Pair!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 3
Card 3: 3
Card 4: 3
Card 5: 6
Three of a kind!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 2
Card 3: 2
Card 4: 2
Card 5: 3
Four of a kind!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 3
Card 3: 4
Card 4: 5
Card 5: 6
Straight!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 2
Card 3: 3
Card 4: 3
Card 5: 3
Full House!
 */