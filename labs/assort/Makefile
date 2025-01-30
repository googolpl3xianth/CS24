CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX = g++

all: test

test: test.o List.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

List.o: List.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o test
