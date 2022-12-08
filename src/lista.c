#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../Includes/lista.h"

typedef struct no NO;

struct no
{
    SET* set;
    NO* proximo;
};


struct lista
{
    NO *comeco; NO *fim;
};

/* Aloca memória para uma lista */
LISTA* lista_criar()
{
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    assert(lista != NULL);

    lista->comeco = NULL;
    lista->fim = NULL;

    return lista;
}

/* Verifica se a lista está vazia: importante para inserção e remoção */
bool lista_vazia(LISTA* lista)
{
    assert(lista != NULL);

    if(lista->comeco == NULL)
    {
        return true;
    }

    return false;
}

/* Busca um conjunto na lista, de acordo com o nome */
SET* lista_buscar(LISTA* lista, char* nome)
{
    assert(lista != NULL);

    NO* aux = lista->comeco;

    /* Iterando pelos nós da lista */
    while(aux != NULL)
    {
        /* Caso os nomes sejam iguais, retornamos o conjunto */
        if(strcmp(set_getNome(aux->set), nome) == 0)
        {
            return aux->set;
        }  

        aux = aux->proximo;
    }  

    /* Caso não encontrado, retornamos NULL */
    return NULL;
}

/* Inserção de um conjunto na lista */
void lista_inserir(LISTA* lista, SET* x)
{
    assert(lista != NULL);

    /* Alocamos memória para um novo nó */
    NO *novo_no = (NO*)malloc(sizeof(NO));
    assert(novo_no != NULL);

    /* Preenchemos os campos */
    novo_no->set = x;
    novo_no->proximo = NULL;

    /* Se a lista estiver vazia, o começo da lista aponta para o novo nó */
    if(lista_vazia(lista))
    {
        lista->comeco = novo_no;
    }
    /* Caso contrário, inserimos no fim da lista */
    else
    {
        lista->fim->proximo = novo_no;
    }

    /* O fim aponta para o novo nó */
    lista->fim = novo_no;
}

/* Remove um conjunto com certo nome da lista */
void lista_remover(LISTA* lista, char* nome)
{
    assert(lista != NULL);

    NO* ant = NULL;
    NO* aux = lista->comeco;
    NO* prox;

    /* Iterando pela lista */
    while(aux != NULL)
    {
        /* Removemos caso os nomes conhecidam */
        if(strcmp(set_getNome(aux->set), nome) == 0)
        {
            if(aux == lista->comeco)
            {
                lista->comeco = lista->comeco->proximo;
            }
            else if(aux == lista->fim)
            {
                lista->fim = ant;

                set_apagar(&(aux->set));
                free(aux);

                lista->fim->proximo = NULL;

                break;
            }
            else
            {
                ant->proximo = aux->proximo;
            }

            prox = aux->proximo;

            set_apagar(&(aux->set));
            free(aux);

            aux = prox;
        }
        else
        {
            ant = aux;
            aux = aux->proximo;
        }
    }
}

/* Printa todos os conjuntos da lista no formato -> "Nome": "elementos" */
void lista_printar(LISTA* lista)
{
    assert(lista != NULL);

    NO* aux = lista->comeco;
    while(aux != NULL)
    {
        printf("%s: ", set_getNome(aux->set));
        set_imprimir(aux->set);
        printf("\n");

        aux = aux->proximo;
    }
}

/* Apaga todos os nós, e seus componentes, presentes na lista */
void lista_apagar(LISTA** lista)
{
    if(lista == NULL || *lista == NULL) return;

    NO* aux = (*lista)->comeco;
    while(aux != NULL)
    {
        (*lista)->comeco = aux->proximo;

        set_apagar(&(aux->set));
        free(aux);

        aux = (*lista)->comeco;
    }

    free(*lista);
}
