CXX=g++

CXXFLAGS=-std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

all: move-check game-check

tests:
	./testCases.sh
	./testMove.sh
	./testGame.sh

move-check: Move.o move-check.o
	${CXX} $^ -o move-check

game-check: Move.o Board.o game-check.o
	${CXX} $^ -o game-check


clean:
	rm -f *.o
	rm move-check
	rm game-check
