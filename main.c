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
            /* Opçao 1: busca um conjunto da lista e printar */
            case 1: user_printarConjunto(lista_conjuntos); break;
            
            /* Opção 2: printar todos os conjuntos da lista */
            case 2: user_printarTodos(lista_conjuntos); break;

            /* Opção 3: criar um novo conjunto e inserir na lista */
            case 3: user_criarConjunto(lista_conjuntos); break;

            /* Opção 4: remover um conjunto da lista */
            case 4: user_removerConjunto(lista_conjuntos); break;

            /* Opção 5: inserir elemento em um conjunto específico da lista */
            case 5: user_inserirElemento(lista_conjuntos); break;

            /* Opção 6: remover elemento de um conjunto específico da lista */
            case 6: user_removerElemento(lista_conjuntos); break;

            /* Opção 7: união entre dois conjuntos da lista, resultando em um terceiro conjunto */
            case 7: user_uniao(lista_conjuntos); break;

            /* Opção 8: intersecção entre dois conjuntos da lista, resultando em um terceiro conjunto */
            case 8: user_interseccao(lista_conjuntos); break;

            /* Opção 9: verifica se um elemento pertence a um conjunto determinados pelo usuário */
            case 9: user_elementoPertence(lista_conjuntos); break;

            /* Opção 0: sair do programa */
            case 0: user_sair(lista_conjuntos); break;

            default: printf("Insira uma opção válida!\n\n\n\n"); break;
        }

    } while(operacao != 0);
    

    return EXIT_SUCCESS;
}