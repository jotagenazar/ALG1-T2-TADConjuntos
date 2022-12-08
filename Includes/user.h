#ifndef USER_H
#define USER_H

#include "lista.h"

/* Print do menu de operações fornecidas pelo programa */
int menu();

/* Recebe dados do usuário e printa o conjunto de interesse na formatação adequada */
void user_printarConjunto(LISTA* lista_conjuntos);

/* Printa todos os conjuntos da lista na formatação adequada */
void user_printarTodos(LISTA* lista_conjuntos);

/* Recebe dados do usuário, cria o novo conjunto e insere na lista */
void user_criarConjunto(LISTA* lista_conjuntos);

/* Recebe dados do usuário e remove o conjunto de interesse da lista */
void user_removerConjunto(LISTA* lista_conjuntos);

/* Recebe dados do usuário e insere um elemento desejado em um conjunto desejado da lista */
void user_inserirElemento(LISTA* lista_conjuntos);

/* Recebe dados do usuário e remove um elemento desejado em um conjunto desejado da lista */
void user_removerElemento(LISTA* lista_conjuntos);

/* Recebe dados do usuário para unir dois conjuntos de interesse, inserindo o resultado na lista */
void user_uniao(LISTA* lista_conjuntos);

/* Recebe dados do usuário para intersectar dois conjuntos de interesse, inserindo o resultado na lista */
void user_interseccao(LISTA* lista_conjuntos);

void user_elementoPertence(LISTA* lista_conjuntos);

/* Desaloca toda memória e sai do programa */
void user_sair(LISTA* lista_conjuntos);

#endif // USER_H