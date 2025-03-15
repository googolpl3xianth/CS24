CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -O3

all: bomber

bomber: main.o Map.o Point.o
	${CXX} $(CXXFLAGS) -o bomber $+

bomber.o: main.cpp Point.h Map.h Errors.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm *.o bomber
