#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

typedef int elem;

typedef enum tipos tipo_t;

enum tipos
{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
};


typedef struct item ITEM;

ITEM* item_criar(elem valor);
void item_apagar(ITEM** item);
elem get_valor(ITEM* item);
void set_valor(ITEM* item, elem valor);
void item_print(ITEM* item, tipo_t tipo);

#endif