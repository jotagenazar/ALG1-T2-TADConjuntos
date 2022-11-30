#include <stdio.h>
#include <stdlib.h>

#include "Includes/set.h"

int main()
{

    SET* A = set_criar();

    set_inserir(A, 2);
    set_inserir(A, 3);
    set_inserir(A, 5);
    set_inserir(A, 7);
    set_inserir(A, 11);
    set_inserir(A, 13);
    set_inserir(A, 17);
    set_inserir(A, 19);
    set_inserir(A, 23);
    set_inserir(A, 29);
    set_inserir(A, 31);
    set_inserir(A, 37);
    set_inserir(A, 41);

    set_imprimir(A, INT);

    SET* B = set_criar();
    set_inserir(B, 1);
    set_inserir(B, 3);
    set_inserir(B, 5);
    set_inserir(B, 7);
    set_inserir(B, 9);
    set_inserir(B, 11);
    set_inserir(B, 13);
    set_inserir(B, 15);
    set_inserir(B, 17);
    set_inserir(B, 19);
    set_inserir(B, 21);
    set_inserir(B, 23);

    set_imprimir(B, INT);

    SET* UNIAO = set_uniao(A, B);

    set_imprimir(UNIAO, INT);


    SET* INTERSEC = set_interseccao(A, B);

    set_imprimir(INTERSEC, INT);

    set_apagar(&A);
    set_apagar(&B);
    set_apagar(&UNIAO);
    set_apagar(&INTERSEC);

    return EXIT_SUCCESS;
}