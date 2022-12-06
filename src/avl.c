#include <stdio.h>
#include <stdlib.h>

#include "../Includes/avl.h"

typedef struct no NO;

struct no{
    ITEM* item;
    int altura;

    NO* esq;
    NO* dir;
};

struct avl{
    NO* raiz;
};

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

int avl_getAltura(AVL* avl)
{
    return no_altura(avl->raiz);
}

int get_balanceamento(NO* no){
    if(no == NULL) return 0;

    return no_altura(no->esq) - no_altura(no->dir);
}

/* Função para imprimir a AVL em ordem */
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

/*Funcoes de busca:*/

NO* no_busca(NO* no, elem x){
    if(no == NULL) return NULL;

    elem elem_no = get_valor(no->item);

    if(x == elem_no) return no;

    if(x < elem_no) return no_busca(no->esq, x);

    return no_busca(no->dir, x); 
}

ITEM* avl_busca(AVL* avl, elem x){
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

    elem elem_no = get_valor(no->item);
    elem elem_item= get_valor(x);

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

elem avl_max_valor(NO* no){
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

NO* no_remover(NO* no, elem x){

    /*Percorrendo a arvore ateh achar o elemento.*/
    if(no == NULL) return no;

    elem elem_no = get_valor(no->item);

    if(x < elem_no) no->esq =  no_remover(no->esq, x);

    else if(x > elem_no) no->dir = no_remover(no->dir, x);

    else{
        /*Neste else, chegamos no elemento a ser
        removido.*/

        if(no->esq == NULL || no->dir == NULL){
            /*O elemento esta em uma folha ou possui
            apenas um filho.*/
            NO* filho = no->esq ? no->esq : no->dir;

            if(filho == NULL){
                /*O elemento eh uma folha.*/
                /*Fazendo o filho apontar para o no-folha.*/
                filho = no;
                no = NULL;
            }
            else{
                /*O elemento possui um filho.*/
                /*Copiando o elemento do filho no pai pra
                depois apagar o filho.*/
                set_valor(no->item, get_valor(filho->item));
                no->dir = NULL;
                no->esq = NULL;
            }

            /*Apagando o filho.*/
            no_apagar(&filho);
        }
        else{
            /*O no possui dois filhos.*/
            
            /*Pegando o maior valor da subarvore da
            esquerda:*/
            elem maior = avl_max_valor(no->esq);

            /*Setando o no a ser deletado com esse valor:*/
            set_valor(no->item, maior);

            /*Deletando o maior elemento da subavore da esquerda:*/
            no->esq = no_remover(no->esq, maior);
        }
    }

    if(no == NULL) return no;

    /*Atualizando a altura do no:*/
    no->altura = no_altura(no);

    /*Checando o fator de balanceamento do no
    e de seus filhos.*/
    int fb = get_balanceamento(no);
    int fb_esq = get_balanceamento(no->esq);
    int fb_dir = get_balanceamento(no->dir);

    /*Checando os casos de desbalanceamento:*/
    if(fb > 1 && fb_esq >= 0){
        return rotacao_DD(no);
    }

    if(fb < -1 && fb_dir <= 0){
        return rotacao_EE(no);
    }

    if(fb > 1 && fb_esq < 0){
        no->esq = rotacao_EE(no->esq);
        return rotacao_DD(no);
    }

    if(fb < -1 && fb_dir > 0){
        no->dir = rotacao_DD(no->dir);
        return rotacao_EE(no);
    }

    return no;
}

void avl_remover(AVL* avl, elem x){
    assert(avl != NULL);

    avl->raiz = no_remover(avl->raiz, x);
}

NO* avl_clone(NO* raiz)
{
    if(raiz == NULL) return NULL;

    ITEM* novo_item = item_criar(get_valor(raiz->item));
    NO* novo_no = no_criar(novo_item);
    
    novo_no->esq = avl_clone(raiz->esq);
    novo_no->dir = avl_clone(raiz->dir);

    return novo_no;
}

AVL* avl_copiar(AVL* avl)
{
    AVL* copia = avl_criar();

    copia->raiz = avl_clone(avl->raiz);

    return copia;
}

void _avl_concat(AVL* uniao, NO* raiz)
{
    if(raiz == NULL) return;

    _avl_concat(uniao, raiz->esq);
    _avl_concat(uniao, raiz->dir);

    elem elemento_atual = get_valor(raiz->item);

    /* Caso o elemento ja esteja na união, não adicionamos */
    if((avl_busca(uniao, elemento_atual)) != NULL) return;

    /* Caso contrário, copiamos item e nó, adicionando na árvore união */
    ITEM* novo_item = item_criar(elemento_atual);
    avl_inserir(uniao, novo_item);

}

AVL* avl_concat(AVL* A, AVL* B)
{
    AVL* uniao = avl_copiar(A);

    _avl_concat(uniao, B->raiz);

    return uniao;
}


void _avl_intersec(AVL* intersec, NO* raiz_a, AVL* arvore_b)
{
    if(raiz_a == NULL) return;

    _avl_intersec(intersec, raiz_a->esq, arvore_b);
    _avl_intersec(intersec, raiz_a->dir, arvore_b);

    elem elemento_atual = get_valor(raiz_a->item);

    if((avl_busca(arvore_b, elemento_atual)) == NULL) return;

    ITEM* novo_item = item_criar(elemento_atual);
    avl_inserir(intersec, novo_item);
}

AVL* avl_intersec(AVL* A, AVL* B)
{
    AVL* intersec = avl_criar();

    _avl_intersec(intersec, A->raiz, B);

    return intersec;
}