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

#endif