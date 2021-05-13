#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }
 
  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  
  //Test input from file
  Player Alice;
  Player Bob;
 
 // Read each file and store cards
 
  
  while (getline (cardFile1, line) && (line.length() > 0)){
    Alice.playerHand.append(line.at(0),line.at(2));  
  }
   cardFile1.close();



  while (getline (cardFile2, line) && (line.length() > 0)){
   Bob.playerHand.append(line.at(0),line.at(2));
  }
  cardFile2.close();
  // Start the game
  
  //Set the name of player objects and have their
  //current card point to the head of the linked list
  //that was made to hold their cards

  Alice.setupGame("Alice");
  Bob.setupGame("Bob");
 

  Alice.game(Alice.current, Bob);
  cout << endl;

  //Output end hand of both players
  Alice.Hand();
  cout << endl;

  Bob.Hand();
  
  return 0;
}
