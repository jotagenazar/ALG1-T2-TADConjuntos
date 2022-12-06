#ifndef _AVL_H
#define _AVL_H

#include "item.h"

typedef struct avl AVL;

/* Funcoes de manipulacao de memoria: */
AVL* avl_criar();
void avl_apagar(AVL** avl);

/* Printa a árvore no percurso "em ordem" */
void avl_emOrdem(AVL* avl);

/* Funcoes de busca: */
ITEM* avl_busca(AVL* avl, elem x);

/* Funcoes de insercao e remocao: */
void avl_inserir(AVL* avl, ITEM* x);
void avl_remover(AVL* avl, elem x);

/* Retorna a concatenação entre duas árvores, mantendo o formato AVL */
AVL* avl_concat(AVL* A, AVL* B);

/* Retorna a intersecção entre duas árvores, mantendo o formato AVL */
AVL* avl_intersec(AVL* A, AVL* B);

#endif