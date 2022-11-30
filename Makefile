CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o set.o avl.o item.o
BIN = main

all: $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c set.h
	$(CC) -c $(FLAGS) main.c

set.o: set.c set.h avl.h
	$(CC) -c $(FLAGS) set.c

avl.o: avl.c avl.h item.h
	$(CC) -c $(FLAGS) avl.c

item.o: item.c item.h
	$(CC) -c $(FLAGS) item.c
 
valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)

run:
	./$(BIN)