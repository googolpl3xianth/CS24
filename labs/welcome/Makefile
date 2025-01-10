all: caprot

caprot:
	g++ caprot.cpp -o caprot -std=c++17 -g -Wall -Wextra -Werror -Wno-unsed-parameter

leakcheck:
	valgrind --leak-check=full -- ./caprot 0

clean:
	rm caprot
