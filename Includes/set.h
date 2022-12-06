#ifndef _SET_H
#define _SET_H

#include "avl.h"

/* Os conjuntos serão árvores AVL, garantindo o balanceamento */
typedef AVL SET;

/* Alocação de memória para criação do set */
SET *set_criar(void);

/* Busca por elemento do conjunto, retorna true se "elemento" pertence ao conjunto, caso contrário false */
bool set_pertence(SET *A, elem elemento);

/* Insere elemento no cojunto */
void set_inserir(SET *s, elem elemento);

/* Remove elemento do conjunto */
void set_remover(SET *s, elem elemento);

/* Desloca memória dedicada a um conjunto */
void set_apagar(SET **s);

/* Imprime um conjunto em ordem crescente */
void set_imprimir(SET *s);

/* Retorna o conjunto união entre A e B */
SET *set_uniao(SET *A, SET *B);

/* Retorna o conjunto intersecção entre A e B */
SET *set_interseccao(SET *A, SET *B);
  
#endif