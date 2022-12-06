#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../Includes/lista.h"

typedef struct no NO;

struct no
{
    SET* set;
    char* nome;

    NO* proximo;
};


struct lista
{
    NO *comeco; NO *fim;
};

LISTA* lista_criar()
{
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    assert(lista != NULL);

    lista->comeco = NULL;
    lista->fim = NULL;

    return lista;
}

bool lista_vazia(LISTA* lista)
{
    assert(lista != NULL);

    if(lista->comeco == NULL)
    {
        return true;
    }

    return false;
}

SET* lista_buscar(LISTA* lista, char* nome)
{
    assert(lista != NULL);

    NO* aux = lista->comeco;

    while(aux != NULL)
    {
        if(strcmp(aux->nome, nome) == 0)
        {
            return aux->set;
        }  

        aux = aux->proximo;
    }  

    return NULL;
}


void lista_inserir(LISTA* lista, SET* x, char* nome)
{
    assert(lista != NULL);

    NO *novo_no = (NO*)malloc(sizeof(NO));
    assert(novo_no != NULL);

    novo_no->set = x;
    novo_no->proximo = NULL;
    novo_no->nome = nome;

    if(lista_vazia(lista))
    {
        lista->comeco = novo_no;
    }
    else
    {
        lista->fim->proximo = novo_no;
    }

    lista->fim = novo_no;
}

void lista_remover(LISTA* lista, char* nome)
{
    assert(lista != NULL);

    NO* ant = NULL;
    NO* aux = lista->comeco;
    NO* prox;

    while(aux != NULL)
    {
        if(strcmp(aux->nome, nome) == 0)
        {
            if(aux == lista->comeco)
            {
                lista->comeco = lista->comeco->proximo;
            }
            else if(aux == lista->fim)
            {
                lista->fim = ant;

                set_apagar(&(aux->set));
                free(aux->nome);
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
            free(aux->nome);
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


void lista_printar(LISTA* lista)
{
    assert(lista != NULL);

    NO* aux = lista->comeco;
    while(aux != NULL)
    {
        printf("%s: ", aux->nome);
        set_imprimir(aux->set);
        printf("\n");

        aux = aux->proximo;
    }
}

void lista_apagar(LISTA** lista)
{
    if(lista == NULL || *lista == NULL) return;

    NO* aux = (*lista)->comeco;
    while(aux != NULL)
    {
        (*lista)->comeco = aux->proximo;

        set_apagar(&(aux->set));
        free(aux->nome);
        free(aux);

        aux = (*lista)->comeco;
    }

    free(*lista);
}
