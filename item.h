#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

typedef struct item ITEM;

ITEM* item_criar(int valor);
void item_apagar(ITEM** item);
int get_valor(ITEM* item);
void set_valor(ITEM* item, int valor);
void item_print(ITEM* item);

#endif