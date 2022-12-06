#include <stdio.h>
#include <stdlib.h>

#include "Includes/lista.h"

/* Número a ser adicionado indicando fim dos elementos a serem inseridos */
#define FIM_ELEMENTOS 404

int menu()
{
    int operacao;

    printf("Digite uma das opções abaixo: \n");

    printf("0. Fechar o Programa \n");
    printf("1. Printar um conjunto \n");
    printf("2. Printar todos os conjuntos \n");
    printf("3. Criar conjunto \n");
    printf("4. Remover conjunto \n");
    printf("5. Criar união \n");
    printf("6. Criar Intersecção \n\n");

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

int main()
{
    LISTA* lista_conjuntos = lista_criar();
    char* nome;

    SET* conjunto;
    SET* A;
    SET* B;

    elem elemento;

    int operacao;

    do
    {
        operacao = menu();
        
        switch (operacao)
        {
            case 1:
                printf("Insira o nome do conjunto a ser printado: ");
                nome = ler_nome();

                conjunto = lista_buscar(lista_conjuntos, nome);
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
                break;

            case 2: 
                lista_printar(lista_conjuntos); 

                printf("\n\n\n");
                break;

            case 3:
                conjunto = set_criar();

                printf("Inserir o nome do novo conjunto: ");
                nome = ler_nome();

                printf("Inserir os elementos do conjunto: \n");
                scanf("%d", &elemento);
                do
                {
                    set_inserir(conjunto, elemento);

                    scanf("%d", &elemento);
                } while (elemento != FIM_ELEMENTOS);
                
                lista_inserir(lista_conjuntos, conjunto, nome);

                printf("\n\n\n");
                break;

            case 4:
                printf("Inserir o nome do conjunto a ser removido: ");
                nome = ler_nome();

                lista_remover(lista_conjuntos, nome);

                free(nome);

                printf("\n\n\n");
                break;


            case 5:
                printf("Insira o nome do primeiro conjunto: ");
                nome = ler_nome();

                A = lista_buscar(lista_conjuntos, nome);
                free(nome);

                if(A == NULL)
                {
                    printf("Conjunto não encontrado!\n");

                    printf("\n\n\n");
                    break;
                }

                printf("Insira o nome do segundo conjunto: ");
                nome = ler_nome();

                B = lista_buscar(lista_conjuntos, nome);
                free(nome);

                if(B == NULL)
                {
                    printf("Conjunto não encontrado!\n");

                    printf("\n\n\n");
                    break;
                }

                printf("Insira o nome do conjunto uniao: ");
                nome = ler_nome();

                conjunto = set_uniao(A, B);

                lista_inserir(lista_conjuntos, conjunto, nome);

                printf("\n\n\n");
                break;

            case 6:

                printf("Insira o nome do primeiro conjunto: ");
                nome = ler_nome();

                A = lista_buscar(lista_conjuntos, nome);
                free(nome);

                if(A == NULL)
                {
                    printf("Conjunto não encontrado!\n");

                    printf("\n\n\n");
                    break;
                }

                printf("Insira o nome do segundo conjunto: ");
                nome = ler_nome();

                B = lista_buscar(lista_conjuntos, nome);
                free(nome);

                if(B == NULL)
                {
                    printf("Conjunto não encontrado!\n");

                    printf("\n\n\n");
                    break;
                }

                printf("Insira o nome do conjunto intersecção: ");
                nome = ler_nome();

                conjunto = set_interseccao(A, B);

                lista_inserir(lista_conjuntos, conjunto, nome);

                printf("\n\n\n");
                break;

            case 0:
                printf("Obrigado por usar o programa!\n");
                lista_apagar(&lista_conjuntos);

                printf("\n\n\n");
                break;

            default:
                printf("Insira uma opção válida!\n");

                printf("\n\n\n");
                break;
        }

    } while(operacao != 0);
    

    return EXIT_SUCCESS;
}