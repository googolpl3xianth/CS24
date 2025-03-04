CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

all: counter list

counter: main.o Counter.o Iterator.o List.o Index.o
	${CXX} $(CXXFLAGS) -o $@ $+

counter.o: main.cpp Counter.h List.h Index.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

list: tList.o List.o
	${CXX} $(CXXFLAGS) -o $@ $+

list.o: tList.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f *.o counter list
