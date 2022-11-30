#ifndef _SET_H
#define _SET_H

#include "avl.h"
 
typedef AVL SET;

SET *set_criar(void);
bool set_pertence(SET *A, elem elemento);
void set_inserir(SET *s, elem elemento);
void set_remover(SET *s, elem elemento);
void set_apagar(SET **s);
void set_imprimir(SET *s, tipo_t tipo);
SET *set_uniao(SET *A, SET *B);
SET *set_interseccao(SET *A, SET *B);
  
#endif