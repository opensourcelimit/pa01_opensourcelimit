//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

class Card {
    public:
    char suit;
    char rank;
    Card* next = nullptr;
    Card* previous = nullptr;    
   
    Card(char suitInput ='z', char rankInput = 'z'): suit(suitInput), rank(rankInput) {}
    bool operator==(const Card &secondCard);
    bool operator!=(const Card &secondCard);
    friend ostream& operator<<(ostream& os, const Card &outputCard);

 
};

class Cardlist {
private:
    Card* head;
    Card* tail;
public:
    void append(char suit, char rank);
    void outputCards() const;
    void remove(Card* currentNode);
    Cardlist():head(nullptr),tail(nullptr) {}
    ~Cardlist();
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
