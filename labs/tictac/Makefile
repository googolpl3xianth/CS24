CXX=g++

CXXFLAGS=-std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

all: move-check game-check

moveTest1: moveTest1.o Move.o
	${CXX} $^ -o $@

move-check: Move.o move-check.o
	${CXX} $^ -o move-check

leakCheckMove:
	valgrind --leak-check=full -- ./move-check

game-check: Move.o Board.o game-check.o
	${CXX} $^ -o game-check

leakCheckGame:
	valgrind --leak-check=full -- ./game-check

clean:
	rm -f *.o
	rm move-check
	rm game-check
