#ifndef LIST_H
#define LIST_H

#include "set.h"

typedef struct lista LISTA;

/* Cria uma lista encadeada */
LISTA* lista_criar();

/* Insere um conjunto na lista encadeada */
void lista_inserir(LISTA* lista, SET* x);

/* Remove um conjunto com certo nome na lista encadeada */
void lista_remover(LISTA* lista, char* nome);

/* Busca por um conjunto com certo nome na lista encadeada */
SET* lista_buscar(LISTA* lista, char* nome);

/* Printa todos os conjuntos de uma lista encadeada */
void lista_printar(LISTA* lista);

/* Apaga a lista encadeada */
void lista_apagar(LISTA** lista);

#endif //LIST_H