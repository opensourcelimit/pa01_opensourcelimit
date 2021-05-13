cards.o: cards.cpp
	g++ -g -c  -std=c++11 cards.cpp
testcards: testcards.cpp cards.o
	g++ -g -o  testcards -std=c++11 testcards.cpp cards.o
main: main.cpp cards.o
	g++ -g -o main --std=c++11 main.cpp cards.o

clean:
	rm cards.o
