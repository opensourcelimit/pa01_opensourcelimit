// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  runAll();
  return 0;
}
void removeHead(){
Cardlist Alice;
Alice.append('h','q');
Alice.append('h','k');
Alice.append('h','2');
Alice.append('h','3');

Alice.outputCards();
cout << "After Remove first card" << endl;
Alice.remove('h','q');
Alice.outputCards();


}
void test_getHead(){

Cardlist Alice;
Alice.append('h','q');
Alice.append('h','k');
Alice.append('h','2');
Alice.append('h','3');

Card* headHolder;
headHolder = Alice.getHead();

cout << *headHolder;


}
void runAll(){
  test_append();
  //test_equal();
  test_card();
  test_remove();
}
void test_remove(){
    START_TEST("test_remove");
    removeHead();
    END_TEST("test_remove");

}

void test_append(){
  START_TEST("test_append");
 test_append_empty_list();
 // test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
 // test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
    Cardlist Alice;
    Alice.append('h','q');
    Alice.outputCards();
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}
/*
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  LinkedList l1, l2;
  assertEquals(l1.head,l2.head);
}
*/
void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
  Card first{'h','4'};
  Card second{'h','2'};
  Card third{'h','2'};
  cout << "is " << first << " equals to" << second << "?" << endl;
  assertEquals(false, first == second, "heart of 4 = Queen of 2?");
  assertEquals(true, second == third, "heart of 2 = heart 0f 2?");
}




