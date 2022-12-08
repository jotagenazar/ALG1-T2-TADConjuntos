#ifndef _AVL_H
#define _AVL_H

#include "item.h"

typedef struct avl AVL;

/* Funcoes de manipulacao de memoria: */
AVL* avl_criar();
void avl_apagar(AVL** avl);

/* Printa a árvore no percurso "em ordem" */
void avl_emOrdem(AVL* avl);

/* Exporta a altura de certa árvore para outras bibliotecas */
int avl_getAltura(AVL* avl);

/* Busca um item com o elemento "x" na árvore. Retorna NULL caso não encotre */
ITEM* avl_busca(AVL* avl, elem x);

/* Inserção e remoção de itens na árvore */
void avl_inserir(AVL* avl, ITEM* x);
void avl_remover(AVL* avl, elem x);

/* Retorna a concatenação entre duas árvores, mantendo o formato AVL */
AVL* avl_concat(AVL* A, AVL* B);

/* Cria a intersecção entre duas árvores, mantendo o formato AVL (retorno por passagem de parâmetro) */
void avl_intersec(AVL* intersec, AVL* A, AVL* B);

#endif