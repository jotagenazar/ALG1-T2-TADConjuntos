#include <stdio.h>
#include <stdlib.h>

#include "../Includes/item.h"

struct item{
    elem valor;
};

/* Alocando memória para um novo item */
ITEM* item_criar(elem valor){
    ITEM* p = (ITEM*)malloc(sizeof(ITEM));
    assert(p != NULL);

    p->valor = valor;

    return p;
}

/* Apagando o item */
void item_apagar(ITEM** item){
    assert(item != NULL);
    assert(*item != NULL);

    free(*item);
}

/* Exportando o elemento presente no item */
elem get_valor(ITEM* item){
    assert(item != NULL);
    return item->valor;
}

/* Alterando o dado presente em determinado item */
void set_valor(ITEM* item, elem valor){
    assert(item != NULL);
    item->valor = valor;
}

/* Printando determinado item */
void item_print(ITEM* item)
{
    assert(item != NULL);

    printf("%d ", (int)item->valor);
    
}