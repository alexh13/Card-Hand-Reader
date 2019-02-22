/*
Alex Hughes
2/12/2019
Assignment 4.1

A a program that reads five (or more) cards from the user, then analyzes the cards and prints out the category of hand
that they represent.
*/


#include <iostream>
#include <string>

int hand[5];

using namespace std;

//------------------------------------------ ARRAY PRACTICE ----------------------------------------------------------
// accept an array of integers and a size argument. It should return true if none of the values are negative.
// If any of the values are negative it should return false
bool noNegatives(const int array[], int size) {


}


// accept an array of integers and a size argument. It should replace any negative values with
// the corresponding positive value.
void absoluteValues(int array[], int size) {


}


// accept an array of chars and a size argument. It should return the number of times that the
// character 'e' shows up in the array.
int eCount(const char array[], int size) {


}


// should be similar to eCount, but instead of counting 'e's it should accept a third argument, a target char.
// The function should return the number of times the target char shows up in the array.
int charCount(const char array[], int size, char targetChar) {


}


// accept an array of integers and a size argument. It should return true if the values are sorted in ascending order.
// False if they are not.
bool isSorted(const int array[], int size) {


}


// accept an array of chars and a size argument. It should return true if there are two adjacent elements in the array
// with equal values. If there are not, it should return false.
bool equalNeighbors(const char array[], int size) {


}

// Assignment 4.1
#include <iostream>

int max(const int cards[], const int num);
bool isPair(const int hand[]);
bool is2Pair(const int hand[]);
bool isFullHouse(const int hand[]);

int main() {
    int hand[5] = {1, 4, 4, 13, 13};
    std::cout << (isPair(hand) ? "yes" : "no") << "\n";
    std::cout << (is2Pair(hand) ? "yes" : "no") << "\n";

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
