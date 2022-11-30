#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main(void){
    AVL* avl = avl_criar();

    avl_inserir(avl, item_criar(10));
    avl_print(avl);

    avl_inserir(avl, item_criar(20));
    avl_print(avl);
    
    avl_inserir(avl, item_criar(30));
    avl_print(avl);
    
    avl_inserir(avl, item_criar(40));
    avl_print(avl);
    
    avl_inserir(avl, item_criar(50));
    avl_print(avl);
    
    avl_inserir(avl, item_criar(25));
    avl_print(avl);
    
    avl_emOrdem(avl);

    avl_apagar(&avl);
    return EXIT_SUCCESS;
}