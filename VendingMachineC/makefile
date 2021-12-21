CC=gcc
CFLAGS=-I.
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mainmake: main.o list.o 
	$(CC) -o vending_machine main.o list.o 
