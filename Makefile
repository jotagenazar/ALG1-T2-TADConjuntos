CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o set.o avl.o item.o
BIN = main

all: $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c Includes/set.h
	$(CC) -c $(FLAGS) main.c

set.o: src/set.c Includes/set.h Includes/avl.h
	$(CC) -c $(FLAGS) src/set.c

avl.o: src/avl.c Includes/avl.h Includes/item.h
	$(CC) -c $(FLAGS) src/avl.c

item.o: src/item.c Includes/item.h
	$(CC) -c $(FLAGS) src/item.c
 
valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)

run:
	./$(BIN)