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
    if(no == NULL) return no;

    int elem_no = get_valor(no->item);

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
            int maior = avl_max_valor(no->esq);

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

void avl_remover(AVL* avl, int x){
    assert(avl != NULL);

    avl->raiz = no_remover(avl->raiz, x);
}