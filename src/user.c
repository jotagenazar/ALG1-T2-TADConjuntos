#include <stdio.h>
#include <stdlib.h>

#include "../Includes/user.h"

int menu()
{
    int operacao;

    printf("Digite uma das opções abaixo: \n");

    printf("0. Fechar o Programa \n");
    printf("1. Printar um conjunto \n");
    printf("2. Printar todos os conjuntos \n");
    printf("3. Criar conjunto \n");
    printf("4. Remover conjunto \n");
    printf("5. Inserir elemento em um conjunto \n");
    printf("6. Remover elemento de um conjunto \n");
    printf("7. Criar união \n");
    printf("8. Criar Intersecção \n\n");

    scanf("%d", &operacao);
    scanf("%*c");

    return operacao;

}

char* ler_nome()
{
    char* nome = (char*)malloc(sizeof(char));
    assert(nome != NULL);

    int quantidadeCaracteres = 1;
    char caractereAtual;

    scanf("%c", &caractereAtual);
    while(caractereAtual != '\n')
    {
        nome[quantidadeCaracteres - 1] = caractereAtual;
        quantidadeCaracteres++;

        nome = (char*)realloc(nome, sizeof(char) * quantidadeCaracteres);
        assert(nome != NULL);

        scanf("%c", &caractereAtual);
    }

    nome[quantidadeCaracteres - 1] = '\0';

    return nome;
}

void user_printarConjunto(LISTA* lista_conjuntos)
{
        printf("Insira o nome do conjunto a ser printado: ");
        char* nome = ler_nome();

        SET* conjunto = lista_buscar(lista_conjuntos, nome);
        free(nome);

        if(conjunto == NULL)
        {
            printf("Conjunto não encontrado! \n");
        }
        else
        {
            set_imprimir(conjunto);
        }

        printf("\n\n\n");
}

void user_printarTodos(LISTA* lista_conjuntos)
{
    lista_printar(lista_conjuntos); 

    printf("\n\n\n");
}

void user_criarConjunto(LISTA* lista_conjuntos)
{
    elem elemento;

    printf("Inserir o nome do novo conjunto: ");
    char* nome = ler_nome();

    SET* conjunto = set_criar(nome);

    printf("Inserir os elementos do conjunto: \n");

    char charAtual = fgetc(stdin);

    while(charAtual != '\n')
    {
        ungetc(charAtual, stdin);
        
        scanf("%d", &elemento);
        set_inserir(conjunto, elemento);

        charAtual = fgetc(stdin);
    }
    
    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

void user_removerConjunto(LISTA* lista_conjuntos)
{
    printf("Inserir o nome do conjunto a ser removido: ");
    char* nome = ler_nome();

    lista_remover(lista_conjuntos, nome);

    free(nome);

    printf("\n\n\n");
}

void user_inserirElemento(LISTA* lista_conjuntos)
{
    elem elemento;

    printf("Inserir o nome do conjunto para inserir elemento: ");
    char* nome = ler_nome();   

    SET* conjunto = lista_buscar(lista_conjuntos, nome);
    free(nome);             

    if(conjunto == NULL)
    {
        printf("Conjunto não encontrado! \n");
    }
    else
    {
        printf("Insira o elemento: ");
        scanf("%d", &elemento);

        set_inserir(conjunto, elemento);                    
    }

    printf("\n\n\n");
}

void user_removerElemento(LISTA* lista_conjuntos)
{
    elem elemento;

    printf("Inserir o nome do conjunto para remover elemento: ");
    char* nome = ler_nome();   

    SET* conjunto = lista_buscar(lista_conjuntos, nome);
    free(nome);             

    if(conjunto == NULL)
    {
        printf("Conjunto não encontrado! \n");
    }
    else
    {
        printf("Insira o elemento: ");
        scanf("%d", &elemento);

        set_remover(conjunto, elemento);                    
    }

    printf("\n\n\n");
}

void user_uniao(LISTA* lista_conjuntos)
{
    printf("Insira o nome do primeiro conjunto: ");
    char* nome = ler_nome();

    SET* A = lista_buscar(lista_conjuntos, nome);
    free(nome);

    if(A == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do segundo conjunto: ");
    nome = ler_nome();

    SET* B = lista_buscar(lista_conjuntos, nome);
    free(nome);

    if(B == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do conjunto uniao: ");
    nome = ler_nome();

    SET* conjunto = set_uniao(A, B, nome);

    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

void user_interseccao(LISTA* lista_conjuntos)
{
    printf("Insira o nome do primeiro conjunto: ");
    char* nome = ler_nome();

    SET* A = lista_buscar(lista_conjuntos, nome);
    free(nome);

    if(A == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do segundo conjunto: ");
    nome = ler_nome();

    SET* B = lista_buscar(lista_conjuntos, nome);
    free(nome);

    if(B == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do conjunto intersecção: ");
    nome = ler_nome();

    SET* conjunto = set_interseccao(A, B, nome);

    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

void user_sair(LISTA* lista_conjuntos)
{
    printf("Obrigado por usar o programa!\n");
    lista_apagar(&lista_conjuntos);

    printf("\n\n\n");
}