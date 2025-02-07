CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX = g++

all: test

test: test.o Node.o Set.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp Node.h Set.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Node.o: Node.cpp Node.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Set.o: Set.cpp Set.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o test
