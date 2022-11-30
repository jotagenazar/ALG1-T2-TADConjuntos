#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../Includes/set.h"

SET *set_criar(void)
{
    return avl_criar();
}

bool set_pertence(SET *A, elem elemento)
{
    return (avl_busca(A, elemento) != NULL);
}

void set_inserir(SET *s, elem elemento)
{
    avl_inserir(s, item_criar(elemento));
}

void set_remover(SET *s, elem elemento)
{
    avl_remover(s, elemento);
}

void set_apagar(SET **s)
{
    avl_apagar(s);
}

void set_imprimir(SET *s, tipo_t tipo)
{
    avl_emOrdem(s, tipo);
}

SET *set_uniao(SET *A, SET *B)
{
    return avl_concat(A, B);
}

SET *set_interseccao(SET *A, SET *B)
{
    return avl_intersec(A, B);
}