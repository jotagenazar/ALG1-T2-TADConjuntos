#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <assert.h>

typedef int elem;

typedef struct item ITEM;

ITEM* item_criar(elem valor);
void item_apagar(ITEM** item);
elem get_valor(ITEM* item);
void set_valor(ITEM* item, elem valor);
void item_print(ITEM* item);

#endif