#include <stdio.h>
#include <stdlib.h>

#include "../Includes/user.h"

/* Printa todas as opções fornecidas pelo programa e retorna a opção desejada pelo usuário */
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
    printf("8. Criar Intersecção \n");
    printf("9. Verificar se elemento pertence \n\n");

    scanf("%d", &operacao);
    scanf("%*c");

    return operacao;

}

/* Leitura sob-medida dos caracteres dos nomes presentes nas buscas/inserções de conjuntos na lista */
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

/* Printa determinado conjunto presente na lista de conjuntos */
void user_printarConjunto(LISTA* lista_conjuntos)
{
        /* Direciona o usuário para inserção dos dados corretamente */
        printf("Insira o nome do conjunto a ser printado: ");
        char* nome = ler_nome();

        /* Busca o conjunto de interesse */
        SET* conjunto = lista_buscar(lista_conjuntos, nome);
        free(nome);

        /* Caso não seja encontrado, alertamos o usuário */
        if(conjunto == NULL)
        {
            printf("Conjunto não encontrado! \n");
        }
        /* Caso encontrado, printamos o conjunto */
        else
        {
            set_imprimir(conjunto);
        }

        printf("\n\n\n");
}

/* Printa todos os conjuntos presentes na lista */
void user_printarTodos(LISTA* lista_conjuntos)
{
    lista_printar(lista_conjuntos); 

    printf("\n\n\n");
}

/* Cria um conjunto e insere na lista */
void user_criarConjunto(LISTA* lista_conjuntos)
{
    elem elemento;

    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Inserir o nome do novo conjunto: ");
    char* nome = ler_nome();

    /* Cria um conjunto com o nome determinado */
    SET* conjunto = set_criar(nome);

    /* Leitura elemento a elemento do novo conjunto */
    printf("Inserir os elementos do conjunto: \n");

    char charAtual = fgetc(stdin);

    while(charAtual != '\n')
    {
        ungetc(charAtual, stdin);
        
        scanf("%d", &elemento);
        set_inserir(conjunto, elemento);

        charAtual = fgetc(stdin);
    }
    
    /* Insere o novo conjunto na lista */
    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

/* Remove um conjunto determinado da lista */
void user_removerConjunto(LISTA* lista_conjuntos)
{
    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Inserir o nome do conjunto a ser removido: ");
    char* nome = ler_nome();

    /* Remove o conjunto determinado pelo usuário */
    lista_remover(lista_conjuntos, nome);

    free(nome);

    printf("\n\n\n");
}

/* Insere um elemento em um conjunto determinados pelo usuário */
void user_inserirElemento(LISTA* lista_conjuntos)
{
    elem elemento;

    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Inserir o nome do conjunto para inserir elemento: ");
    char* nome = ler_nome();   

    /* Busca o conjunto de interesse */
    SET* conjunto = lista_buscar(lista_conjuntos, nome);
    free(nome);             

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(conjunto == NULL)
    {
        printf("Conjunto não encontrado! \n");
    }
    /* Caso contrario, lemos e inserimos o novo elemento no conjunto */
    else
    {
        printf("Insira o elemento: ");
        scanf("%d", &elemento);

        set_inserir(conjunto, elemento);                    
    }

    printf("\n\n\n");
}

/* Remove um elemento em um conjunto determinados pelo usuário */
void user_removerElemento(LISTA* lista_conjuntos)
{
    elem elemento;

    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Inserir o nome do conjunto para remover elemento: ");
    char* nome = ler_nome();   

    /* Busca pelo conjunto de interesse */
    SET* conjunto = lista_buscar(lista_conjuntos, nome);
    free(nome);             

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(conjunto == NULL)
    {
        printf("Conjunto não encontrado! \n");
    }
    /* Caso contrário, lemos e deletamos o elemento de interesse do conjunto */
    else
    {
        printf("Insira o elemento: ");
        scanf("%d", &elemento);

        set_remover(conjunto, elemento);                    
    }

    printf("\n\n\n");
}

/* Operação união entre dois conjuntos, resultando em um terceiro determinados pelo usuário */
void user_uniao(LISTA* lista_conjuntos)
{
    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Insira o nome do primeiro conjunto: ");
    char* nome = ler_nome();

    /* Busca pelo primeiro conjunto de interesse */
    SET* A = lista_buscar(lista_conjuntos, nome);
    free(nome);

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(A == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do segundo conjunto: ");
    nome = ler_nome();

    /* Busca pelo segundo conjunto de interesse */
    SET* B = lista_buscar(lista_conjuntos, nome);
    free(nome);

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(B == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do conjunto uniao: ");
    nome = ler_nome();

    /* Cria um novo conjunto união */
    SET* conjunto = set_uniao(A, B, nome);

    /* Insere o conjunto união na lista */
    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

/* Operação união entre dois conjuntos, resultando em um terceiro determinados pelo usuário */
void user_interseccao(LISTA* lista_conjuntos)
{
    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Insira o nome do primeiro conjunto: ");
    char* nome = ler_nome();

    /* Busca pelo primeiro conjunto de interesse */
    SET* A = lista_buscar(lista_conjuntos, nome);
    free(nome);

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(A == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do segundo conjunto: ");
    nome = ler_nome();

    /* Busca pelo segundo conjunto de interesse */
    SET* B = lista_buscar(lista_conjuntos, nome);
    free(nome);

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(B == NULL)
    {
        printf("Conjunto não encontrado!\n");

        printf("\n\n\n");
        return;
    }

    printf("Insira o nome do conjunto intersecção: ");
    nome = ler_nome();

    /* Cria um novo conjunto intersecção */
    SET* conjunto = set_interseccao(A, B, nome);

    /* Insere o conjunto intersecção na lista */
    lista_inserir(lista_conjuntos, conjunto);

    printf("\n\n\n");
}

void user_elementoPertence(LISTA* lista_conjuntos)
{
    elem elemento;

    /* Direciona o usuário para inserção dos dados corretamente */
    printf("Inserir o nome do conjunto para ver se elemento pertence: ");
    char* nome = ler_nome();   

    /* Busca pelo conjunto de interesse */
    SET* conjunto = lista_buscar(lista_conjuntos, nome);            

    /* Caso o conjunto não seja encontrado, alertamos o usuário */
    if(conjunto == NULL)
    {
        printf("Conjunto não encontrado!");
    }
    /* Caso contrário, lemos o elemento de interesse e verificamos se ele pertence ao usuário */
    else
    {
        printf("Insira o elemento: ");
        scanf("%d", &elemento);

        if(set_pertence(conjunto, elemento))
        {
            printf("O elemento inserido pertence ao conjunto '%s' !", nome);
        }
        else
        {
            printf("O elemento inserido não pertence ao conjunto '%s' !", nome);
        }
    }   

    printf("\n\n\n");

    free(nome);  
}

void user_sair(LISTA* lista_conjuntos)
{
    printf("Obrigado por usar o programa!\n");

    /* Desaloca toda memória presente na lista de conjuntos */
    lista_apagar(&lista_conjuntos);

    printf("\n\n\n");
}