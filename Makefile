CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o user.o lista.o set.o avl.o item.o
BIN = main

all: $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c Includes/user.h
	$(CC) -c $(FLAGS) main.c

user.o: src/user.c Includes/user.h Includes/lista.h
	$(CC) -c $(FLAGS) src/user.c

lista.o: src/lista.c Includes/lista.h Includes/set.h
	$(CC) -c $(FLAGS) src/lista.c

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