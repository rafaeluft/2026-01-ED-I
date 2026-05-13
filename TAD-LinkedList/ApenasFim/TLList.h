#ifndef TLLIST_H
#define TLLIST_H
#include <stdbool.h>

typedef struct _list TLList;
/**
 * Cria instâncias da TLList;
 */
TLList* TLList_create();
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert(TLList*, int);

/**
 * Imprime a lista do início para o fim.
 */
void TLList_print(TLList*);

/**
 * Concatena duas listas em uma terceira usando
 * as funções do TAD.
 * @param TLList* lista1
 * @param TLList* lista2
 * @return TLList* lista3 com o resultado da concatenação
 */
TLList* TLList_conca_func_tad(TLList*, TLList*);

/**
 * Concatena duas listas em uma terceira usando
 * as funções do TAD.
 * @param TLList* lista1
 * @param TLList* lista2
 * @return TLList* lista3 com o resultado da concatenação
 */
TLList* TLList_conca_sem_tad(TLList*, TLList*);

#endif