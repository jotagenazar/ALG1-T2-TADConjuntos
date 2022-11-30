#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"

struct item{
    int valor;
};

ITEM* item_criar(int valor){
    ITEM* p = (ITEM*)malloc(sizeof(ITEM));
    assert(p != NULL);

    p->valor = valor;

    return p;
}

void item_apagar(ITEM** item){
    assert(item != NULL);
    assert(*item != NULL);

    free(*item);
}

int get_valor(ITEM* item){
    assert(item != NULL);
    return item->valor;
}

void set_valor(ITEM* item, int valor){
    assert(item != NULL);
    item->valor = valor;
}

void item_print(ITEM* item){
    printf("%i ", item->valor);
}