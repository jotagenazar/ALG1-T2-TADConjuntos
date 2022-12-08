#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <assert.h>

/* Definição do tipo de dado de cada elemento do item */
/* Mudanças nas máscaras de leitura e print são necessárias caso o tipo de daoo seja alterado */
typedef int elem;

typedef struct item ITEM;

/* Cria um item */
ITEM* item_criar(elem valor);

/* Apaga um item */
void item_apagar(ITEM** item);

/* Retorna o elemento presente no item */
elem get_valor(ITEM* item);

/* Seta certo elemento em um item */
void set_valor(ITEM* item, elem valor);

/* Printa o elemento presente no item */
void item_print(ITEM* item);

#endif