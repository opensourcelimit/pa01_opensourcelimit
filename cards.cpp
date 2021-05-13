//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h
#include <iostream>
#include "cards.h"

using namespace std;
 void Player::Hand(){
   cout << name <<"'s" <<" Hand\n";
   playerHand.outputCards();



 }
 void Player::setupGame(string pname)
 {  
     name = pname; 
     current = playerHand.getHead();

 }
 

 bool Player::searchCard(char suit, char rank)
 {
     if(playerHand.search(suit, rank))
     {
         return true;

     }
         return false;

 }

 void Player::game(Card* current, Player &opp)
 {
        //Base case, current will be null when one player
        //has cross examined their entire hand leaving no
        //further comparisons to be made
        //
        if( current == nullptr )
        {
            return;
        }
        
        // Ask opponent to search for card with same suit and rank as
        // askers current card, if true opponent has that card and it should be removed
        // from the askers hand and the opponents hand
        if( opp.searchCard( current->suit ,current->rank))
        {
            Card* curNext = current->next; //curNext is used to preserve access to next card in hand after removing current

            if( *(opp.current) == *current) //check to see if we need to update opponents current card if its the card that will be removed
            {
                opp.current = opp.current->next;
            }
            //Output player who picked card, and card to be removed from both hands
            cout << name <<" picked matching card " << *current << endl;
            
            //Remove matching card from players and opponents hand, update current players next.
           opp.playerHand.remove(current->suit, current->rank);
           playerHand.remove(current->suit, current->rank);
            

           
            current = current->next;
            //Now that matching card has been found, its time to switch player turns, opponent calls game.
            opp.game(opp.current,*this);
        }
        
        else
        {
        //if current card did not match opponents current card, check the next card in the linked list.    
        current= current->next;
        game(current, opp);
    
        }       
}




Card* Cardlist::search(char suit, char rank){
    Card* traverse = head;
   
    while(traverse){
    if(traverse->suit == suit && traverse->rank == rank)
    {
        return traverse;

    }
    else
    {
        traverse = traverse->next;
   
    }



    }
    
    return nullptr;

}

void Cardlist::remove(Card* removeThis){
    Card* traverse = head;
    Card* previous;

    if(traverse == removeThis){
        head = removeThis->next;
        delete removeThis;
        return;


    }
    while(traverse->next){
        previous = traverse;
        traverse = traverse->next;
        if(traverse == removeThis){
            previous->next = traverse->next;
            delete traverse;
            return;

        }

    }

    return;

}
//public remove function, search for input suit and rank
//if found call remove on the first card node that contains that suit and rank.
void Cardlist::remove(char suit, char rank)
{
    remove(search(suit,rank));



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

//Remove function removes a card from a doubly linked list
//
/*
void Cardlist::remove(Card* removeThis){
   if(removeThis)
{
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
*/


