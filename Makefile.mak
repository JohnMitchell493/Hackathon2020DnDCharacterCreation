CC = character
MN = main
CX = g++
WAE = -Wall -Werror
OBJF = -g
EXEC = -c
G = $(CX) $(OFI) $(WAE)
GC = $(CX) $(OFI) $(EFI) $(WAE)

all: $(CC)

$(MN): $(CC).o $(MN).o
	$(G) $(MN).o $(CC).o -o $(MN)

$(MN).o: $(MN).cpp
	$(GC) $(MN).cpp -o $(MN).o

$(CC).o: $(CC).cpp $(CC).h
	$(GC) $(CC).cpp -o $(CC).o

PHONY: clean all memcheck

run: all
	./main

clean:
	rm -rf $(MN) *.o

memcheck: all
	valgrind ./main