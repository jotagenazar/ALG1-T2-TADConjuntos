#ifndef USER_H
#define USER_H

#include "lista.h"

int menu();

char* ler_nome();

void user_printarConjunto(LISTA* lista_conjuntos);

void user_printarTodos(LISTA* lista_conjuntos);

void user_criarConjunto(LISTA* lista_conjuntos);

void user_removerConjunto(LISTA* lista_conjuntos);

void user_inserirElemento(LISTA* lista_conjuntos);

void user_removerElemento(LISTA* lista_conjuntos);

void user_uniao(LISTA* lista_conjuntos);

void user_interseccao(LISTA* lista_conjuntos);

void user_sair(LISTA* lista_conjuntos);

#endif // USER_H