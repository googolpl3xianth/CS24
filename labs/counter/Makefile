CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -O3

all: char-count counter list index

char-count: char-count.o Counter.o Iterator.o List.o Index.o
	${CXX} $(CXXFLAGS) -o $@ $+

char-count.o: char-count.cpp Counter.h List.h Index.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

counter: main.o Counter.o Iterator.o List.o Index.o
	${CXX} $(CXXFLAGS) -o $@ $+

counter.o: main.cpp Counter.h List.h Index.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

list: tList.o List.o
	${CXX} $(CXXFLAGS) -o $@ $+

list.o: tList.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

index: tIndex.o Index.o List.o
	${CXX} $(CXXFLAGS) -o $@ $+

index.o: tIndex.cpp Index.h List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f *.o char-count counter list index
