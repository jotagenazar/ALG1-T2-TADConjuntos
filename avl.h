#ifndef _AVL_H
#define _AVL_H

#include <stdbool.h>
#include "item.h"

typedef struct avl AVL;
typedef struct no NO;

/*Funcoes de manipulacao de memoria:*/
AVL* avl_criar();
void avl_apagar(AVL** avl);

/*Funcoes de caracteristicas da arvore:*/
bool avl_vazia(AVL* avl);
int avl_altura(AVL* avl);

/*Funcoes de print/percurso:*/
void avl_print(AVL* avl);
void avl_preOrdem(AVL* avl);
void avl_emOrdem(AVL* avl);
void avl_posOrdem(AVL* avl);

/*Funcoes de busca:*/
ITEM* avl_busca(AVL* avl, int x);

/*Funcoes de insercao e remocao:*/
void avl_inserir(AVL* avl, ITEM* x);

#endif