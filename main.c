#include <stdio.h>
#include <stdlib.h>

#include "Includes/user.h"

int main()
{
    LISTA* lista_conjuntos = lista_criar();

    int operacao;

    do
    {
        operacao = menu();
        
        switch (operacao)
        {
            case 1: user_printarConjunto(lista_conjuntos); break;

            case 2: user_printarTodos(lista_conjuntos); break;

            case 3: user_criarConjunto(lista_conjuntos); break;

            case 4: user_removerConjunto(lista_conjuntos); break;

            case 5: user_inserirElemento(lista_conjuntos); break;

            case 6: user_removerElemento(lista_conjuntos); break;

            case 7: user_uniao(lista_conjuntos); break;

            case 8: user_interseccao(lista_conjuntos); break;

            case 0: user_sair(lista_conjuntos); break;

            default: printf("Insira uma opção válida!\n\n\n\n"); break;
        }

    } while(operacao != 0);
    

    return EXIT_SUCCESS;
}