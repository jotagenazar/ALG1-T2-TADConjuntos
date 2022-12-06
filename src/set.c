#include <stdio.h>
#include <stdlib.h>

#include "../Includes/set.h"

struct set
{
    char* nome;
    AVL* arvore;
};


SET *set_criar(char* nome)
{
    assert(nome != NULL);

    SET* novo_set = (SET*)malloc(sizeof(SET));
    assert(novo_set != NULL);

    novo_set->arvore = avl_criar();
    novo_set->nome = nome;

    return novo_set;
}

bool set_pertence(SET *A, elem elemento)
{
    return (avl_busca(A->arvore, elemento) != NULL);
}

void set_inserir(SET *s, elem elemento)
{
    avl_inserir(s->arvore, item_criar(elemento));
}

void set_remover(SET *s, elem elemento)
{
    avl_remover(s->arvore, elemento);
}

void set_apagar(SET **s)
{
    if(*s == NULL) return;

    free((*s)->nome);
    (*s)->nome = NULL;

    avl_apagar(&(*s)->arvore);

    free(*s);
    *s = NULL;
}

void set_imprimir(SET *s)
{
    avl_emOrdem(s->arvore);
}


char* set_getNome(SET* s)
{
    assert(s != NULL);

    return s->nome;
}

SET *set_uniao(SET *A, SET *B, char* nome)
{
    SET* uniao = set_criar(nome);

    if(avl_getAltura(A->arvore) > avl_getAltura(B->arvore))
    {
        uniao->arvore = avl_concat(A->arvore, B->arvore);
    }
    else
    {
        uniao->arvore = avl_concat(B->arvore, A->arvore);
    }

    return uniao;
}

SET *set_interseccao(SET *A, SET *B, char* nome)
{
    SET* intersec = set_criar(nome);

    if(avl_getAltura(A->arvore) > avl_getAltura(B->arvore))
    {
        intersec->arvore = avl_intersec(A->arvore, B->arvore);
    }
    else
    {
        intersec->arvore = avl_intersec(B->arvore, A->arvore);
    }

    return intersec;
}