#include <stdio.h>
#include <stdlib.h>

#include "../Includes/set.h"

/* Um conjunto vai ser composto por uma árvore com os elementos e seu identificador (nome) */
struct set
{
    char* nome;
    AVL* arvore;
};

/* Alocando memória para um set */
SET *set_criar(char* nome)
{
    assert(nome != NULL);

    SET* novo_set = (SET*)malloc(sizeof(SET));
    assert(novo_set != NULL);

    novo_set->arvore = avl_criar();
    novo_set->nome = nome;

    return novo_set;
}

/* Verifica se certo elemento pertence a determinado conjunto */
bool set_pertence(SET *A, elem elemento)
{
    return (avl_busca(A->arvore, elemento) != NULL);
}

/* Insere um elemento no conjunto */
void set_inserir(SET *s, elem elemento)
{
    avl_inserir(s->arvore, item_criar(elemento));
}

/* Remove um elemento do conjunto */
void set_remover(SET *s, elem elemento)
{
    avl_remover(s->arvore, elemento);
}

/* Apaga memória destinada a um set */
void set_apagar(SET **s)
{
    if(*s == NULL) return;

    free((*s)->nome);
    (*s)->nome = NULL;

    avl_apagar(&(*s)->arvore);

    free(*s);
    *s = NULL;
}

/* Exporta o nome de um conjunto para outras bibliotecas */
char* set_getNome(SET* s)
{
    assert(s != NULL);

    return s->nome;
}

/* Imprime os elementos do conjunto no formato em-ordem */
void set_imprimir(SET *s)
{
    avl_emOrdem(s->arvore);
}

/* Realiza a união entre dois sets, retornando um novo com "nome" passado como parâmetro */
SET *set_uniao(SET *A, SET *B, char* nome)
{
    /* Alocamos memória para um novo SET */
    SET* uniao = (SET*)malloc(sizeof(SET));
    assert(uniao != NULL);

    /* Inserimos o nome passado para a função */
    uniao->nome = nome;

    /* Selecionamos a árvore com maior altura como base das comparações, diminuindo número de buscas */
    if(avl_getAltura(A->arvore) > avl_getAltura(B->arvore))
    {
        uniao->arvore = avl_concat(A->arvore, B->arvore);
    }
    else
    {
        uniao->arvore = avl_concat(B->arvore, A->arvore);
    }

    /* Retornamos o conjunto união */
    return uniao;
}

SET *set_interseccao(SET *A, SET *B, char* nome)
{
    /* Alocamos memória para um novo conjunto */
    SET* intersec = set_criar(nome);

    /* Selecionamos a árvore com menor altura como base das comparações, diminuindo número de buscas */
    if(avl_getAltura(A->arvore) < avl_getAltura(B->arvore))
    {
        avl_intersec(intersec->arvore, A->arvore, B->arvore);
    }
    else
    {
        avl_intersec(intersec->arvore, B->arvore, A->arvore);
    }

    /* Retornamos o conjunto intersecção */
    return intersec;
}