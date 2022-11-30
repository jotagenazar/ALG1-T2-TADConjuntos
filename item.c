#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"

struct item{
    elem valor;
};

ITEM* item_criar(elem valor){
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

elem get_valor(ITEM* item){
    assert(item != NULL);
    return item->valor;
}

void set_valor(ITEM* item, elem valor){
    assert(item != NULL);
    item->valor = valor;
}

void item_print(ITEM* item, tipo_t tipo){

    switch (tipo)
    {
        case INT:
            printf("%d ", (int)item->valor);
            break;
        
        case FLOAT:
            printf("%.2f ", (float)item->valor);
            break;

        case DOUBLE:
            printf("%.2lf ", (double)item->valor);
            break;

        case CHAR:
            printf("%c ", (char)item->valor);
            break;

        default:
            return;
    }
    
}