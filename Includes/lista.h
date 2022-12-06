#ifndef LIST_H
#define LIST_H

#include "set.h"

typedef struct lista LISTA;

LISTA* lista_criar();

void lista_inserir(LISTA* lista, SET* x);

void lista_remover(LISTA* lista, char* nome);

SET* lista_buscar(LISTA* lista, char* nome);

void lista_printar(LISTA* lista);

void lista_apagar(LISTA** lista);

#endif //LIST_H