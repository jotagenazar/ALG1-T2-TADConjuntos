#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "avl.h"

struct no{
    ITEM* item;
    int altura;

    NO* esq;
    NO* dir;
};

struct avl{
    NO* raiz;
};

int max(int a, int b) {return (a > b)? a : b;}

/*Funcoes de manipulacao de memoria:*/

AVL* avl_criar(){
    AVL* p = (AVL*)malloc(sizeof(AVL));
    assert(p != NULL);

    p->raiz = NULL;

    return p;
}

void no_apagar_todos(NO** no){
    /*Apaga todos os nos abbaixo do no chamado.*/
    if(*no != NULL){
        no_apagar_todos(&(*no)->esq);
        no_apagar_todos(&(*no)->dir);
        item_apagar(&(*no)->item);
        (*no)->item = NULL;
        free(*no);
        *no = NULL;
    }
}

void avl_apagar(AVL** avl){
    assert(avl != NULL);
    no_apagar_todos(&(*avl)->raiz);
    free(*avl);
}

/*Funcoes de caracteristicas da arvore:*/

bool avl_vazia(AVL* avl){
    if(avl->raiz == NULL) return true;
    return false;
}

int no_altura(NO* no){
    /*Esta funcao analisa todas as ramificacoes da
    arvore recursivamente e retorna sempre a maior
    altura.*/
    if(no == NULL) return 0;

    int alt_esq = 1 + no_altura(no->esq);
    int alt_dir = 1 + no_altura(no->dir);

    if(alt_esq > alt_dir) return alt_esq;
    return alt_dir;
}

int avl_altura(AVL* avl){
    return no_altura(avl->raiz);
}

int get_balanceamento(NO* no){
    if(no == NULL) return 0;

    return (no_altura(no->esq)- no_altura(no->dir));
}

/*Funcoes de print/percurso:*/

void no_print(NO* no){
    /*Esta funcao recursiva printa os elementos de
    uma arvore. O elemento pai eh printado e, logo
    apos e entre parentesis sao printados os filhos.
    Se o filho nao existe, eh printado um '_'.
        1
      3   
    A arvore acima eh printada como: 1(3,_).
    */
    if(no != NULL){
        printf("%i(", get_valor(no->item));
        no_print(no->esq);
        printf(",");
        no_print(no->dir);
        printf(")");
    }
    else{
        printf("_");
    }
}

void avl_print(AVL* avl){
    no_print(avl->raiz);
    printf("\n");
}

void no_preOrdem(NO* no){
    if(no == NULL) return;

    item_print(no->item);
    no_preOrdem(no->esq);
    no_preOrdem(no->dir);
}

void avl_preOrdem(AVL* avl){
    assert(avl != NULL);

    no_preOrdem(avl->raiz);
    printf("\n");
}

void no_emOrdem(NO* no){
    if(no == NULL) return;

    no_emOrdem(no->esq);
    item_print(no->item);
    no_emOrdem(no->dir);
}

void avl_emOrdem(AVL* avl){
    assert(avl != NULL);

    no_emOrdem(avl->raiz);
    printf("\n");
}

void no_posOrdem(NO* no){
    if(no == NULL) return;

    no_posOrdem(no->esq);
    no_posOrdem(no->dir);
    item_print(no->item);
}

void avl_posOrdem(AVL* avl){
    assert(avl != NULL);

    no_posOrdem(avl->raiz);
    printf("\n");
}

/*Funcoes de busca:*/

NO* no_busca(NO* no, int x){
    if(no == NULL) return NULL;

    int elem_no = get_valor(no->item);

    if(x == elem_no) return no;

    if(x < elem_no) return no_busca(no->esq, x);

    return no_busca(no->dir, x); 
}

ITEM* avl_busca(AVL* avl, int x){
    NO* aux = no_busca(avl->raiz, x);
    
    if(aux != NULL) return aux->item;

    return NULL;
}

/*Funcoes de rotacao:*/

NO *rotacao_DD(NO *desb) {
    /*Rotacao Simples a direita.*/
    NO *aux;
    aux = desb->esq;
    desb->esq = aux->dir;
    aux->dir = desb;
    return(aux);
}

NO *rotacao_EE(NO *desb) {
    /*Rotacao Simples a esquerda.*/
    NO *aux;
    aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;
    return(aux);
}

/*Funcoes de insercao e remocao:*/

NO* no_criar(ITEM* x){
    /*Cria um no folha.*/
    NO* no = (NO*)malloc(sizeof(NO));
    assert(no != NULL);

    no->item = x;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;

    return no;
}

NO* no_inserir(NO* no, ITEM* x){
    
    /*Insercao comum de uma ABB:*/
    if(no == NULL) return no_criar(x);

    int elem_no = get_valor(no->item);
    int elem_item= get_valor(x);

    if(elem_item < elem_no){
        no->esq = no_inserir(no->esq, x);
    }
    else if(elem_item > elem_no){
        no->dir = no_inserir(no->dir, x);
    }
    else{
        printf("O elemento ja esta na arvore\n");
        return no;
    }

    /*Atualizando altura do no:*/
    no->altura = no_altura(no);

    /*Checando o fator de balanceamento deste no
    para ver se ele precisa ser balanceado:*/
    int fb = get_balanceamento(no);

    /*Checando os casos de desbalanceamento e 
    realizando as rotacoes adequadas:*/
    if(fb > 1 && elem_item < get_valor(no->esq->item)){
        /*Rotacao simples a direita.*/
        return rotacao_DD(no);
    }

    if(fb < -1 && elem_item > get_valor(no->dir->item)){
        /*Rotacao simples a esquerda.*/
        return rotacao_EE(no);
    }

    if(fb > 1 && elem_item > get_valor(no->esq->item)){
        /*Rotacao dupla esquerda direita.*/
        no->esq = rotacao_EE(no->esq);
        return rotacao_DD(no);
    }

    if(fb < -1 && elem_item < get_valor(no->dir->item)){
        /*Rotacao dupla direita esquerda.*/
        no->dir = rotacao_DD(no->dir);
        return rotacao_EE(no);
    }

    return no;
}

void avl_inserir(AVL* avl, ITEM* x){
    assert(avl != NULL);
    assert(x != NULL);

    avl->raiz = no_inserir(avl->raiz, x);
}

int avl_max_valor(NO* no){
    while(no->dir != NULL){
        no = no->dir;
    }

    return get_valor(no->item);
}

void no_apagar(NO** no){
    assert(no != NULL);

    item_apagar(&(*no)->item);
    (*no)->esq = NULL;
    (*no)->dir = NULL;
    free(*no);
    *no = NULL;
}

NO* no_remover(NO* no, int x){

    /*Percorrendo a arvore ateh achar o elemento.*/
    if(no == NULL) return NULL;

    int elem_no = get_valor(no->item);

    if(x < elem_no) no_remover(no->esq, x);

    else if(x > elem_no) no_remover(no->dir, x);

    else{
        /*Neste else, chegamos no elemento a ser
        removido.*/

        if(no->esq == NULL || no->dir == NULL){
            /*O elemento esta em uma folha ou possui
            apenas um filho (o aux).*/
            NO* aux = no->esq ? no->esq : no->dir;

            if(aux == NULL){
                /*O elemento eh uma folha.*/
                aux = no;
                no = NULL;
            }
            else{
                /*O elemento possui um filho.*/
                NO* temp = no;
                no = aux;
                aux = temp;
            }

            /*Apagando o no.*/
            no_apagar(&aux);            
        }
        else{
            /*O no possui dois filhos.*/
            
            /*Pegando o maior valor da subarvore da
            esquerda:*/
            int maior = avl_max_valor(no->esq);

            /*Setando o no a ser deletado com esse valor:*/
            set_valor(no->item, maior);

            /*Deletando o elemento:*/
            no->esq = no_remover(no->esq, maior);
        }
    }
}