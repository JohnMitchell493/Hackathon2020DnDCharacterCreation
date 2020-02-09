
all: character.h main.cpp
	g++ -g main.cpp -o main -Wall -Wextra -pedantic -std=c++17 -ldl

run: all
	./main

clean:
	rm -rf main *.o
	rm -rf main

memcheck: all
	valgrind ./main
