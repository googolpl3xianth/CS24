CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter
CXX = g++

all: test typo

typo: main.o Heap.o Point.o WordList.o
	${CXX} $(CXXFLAGS) -o typo $+

test: test.o Heap.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

heap.o: Heap.cpp Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

point.o: Point.cpp Point.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

WordList.o: WordList.cpp WordList.h Point.h Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o test typo

