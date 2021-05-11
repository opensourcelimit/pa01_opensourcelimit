//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h
#include <iostream>
#include "cards.h"

using namespace std;


//Remove function removes a card from a doubly linked list
void Cardlist::remove(Card* removeThis){
    Card* suc = removeThis->next;
    Card* pre = removeThis->previous;

    if(suc){
        suc->previous = pre;

    }
    if(pre){
        pre->next = suc;

    }
    if(removeThis == this->tail){
      removeThis->previous->next = nullptr;
     
    }
    if(removeThis == this->head){
        removeThis->next->previous = nullptr;

    }
    delete removeThis;


}


Cardlist::~Cardlist(){
   Card* traverse = head;
   Card* dCard;
   while(traverse){
    dCard = traverse;
    traverse = traverse->next;
    delete dCard;
   }



}




//Adds a card of a given suit and rank to the end of a players hand
void Cardlist::append(char suit, char rank)
{
    Card* newcard = new Card{suit,rank};

    if(!head)
    {
        head = newcard;
        tail = newcard;
        
    }
    else
    {
        tail->next = newcard;
        newcard->previous = tail;
        tail = newcard;

    }

}

//Outputs players entire hand to console
void Cardlist::outputCards() const{
    if(!head){ cout << "empty hand";
    }
    Card* cur = head;
    while(cur){
    cout << *cur << endl;
    cur = cur->next;
    }

}





//Node functions

bool Card::operator==(const Card &secondCard){
    if(suit == secondCard.suit && rank == secondCard.rank)
    {
        return true;
    
    }

    return false;

}

bool Card::operator!=(const Card &secondCard){
    return !(*this == secondCard);

}

ostream& operator<<(ostream& os, const Card &outputCard)
{
    os << outputCard.suit << " " << outputCard.rank;
    return os;
}

