CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o item.o avl.o
BIN = main

all: $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c item.h
	$(CC) -c $(FLAGS) main.c

item.o: item.c item.h
	$(CC) -c $(FLAGS) item.c

avl.o: avl.c avl.h
	$(CC) -c $(FLAGS) avl.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)

run:
	./$(BIN)