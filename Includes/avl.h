#ifndef _AVL_H
#define _AVL_H

#include "item.h"

typedef struct avl AVL;

/*Funcoes de manipulacao de memoria:*/
AVL* avl_criar();
void avl_apagar(AVL** avl);

/*Funcoes de print/percurso:*/
void avl_emOrdem(AVL* avl, tipo_t tipo);

/*Funcoes de busca:*/
ITEM* avl_busca(AVL* avl, elem x);

/*Funcoes de insercao e remocao:*/
void avl_inserir(AVL* avl, ITEM* x);
void avl_remover(AVL* avl, elem x);


AVL* avl_concat(AVL* A, AVL* B);
AVL* avl_intersec(AVL* A, AVL* B);

#endif