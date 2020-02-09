CC = character
MN = main
CX = g++
WAE = -Wall -Werror
OBJF = -g
EXEC = -c
G = $(CX) $(OBJF) $(WAE)
GC = $(CX) $(OBJF) $(EXEC) $(WAE)

all: $(MN)

$(MN): $(MN).o
	$(G) $(MN).o -o $(MN)

$(MN).o: $(MN).cpp $(CC).h
	$(GC) $(MN).cpp -o $(MN).o

PHONY: clean all memcheck

run: all
	./main

clean:
	rm -rf $(MN) *.o

memcheck: all
	valgrind ./main
