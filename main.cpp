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
bool containsHighCard(const int hand[]) {

}


bool  containsPair(const int hand[]) {

}

bool  containsTwoPair(const int hand[]) {

}

bool  containsThreeOfaKind(const int hand[]) {

}

bool  containsStraight(const int hand[]) {

}

bool  containsFullHouse(const int hand[]) {

}

bool  containsFourOfaKind(const int hand[]) {

}


int main() {
    int hand[] = {2, 5, 3, 2, 9};

    if (containsPair(hand)) {
        cout << "contains a pair" << endl;
    }
}