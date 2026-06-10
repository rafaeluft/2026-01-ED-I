#ifndef TGLIST_H
#define TGLIST_H
#include <stdbool.h>

//Políticas de inserção, usadas na criação da lista
#define NO_FIM 0
#define NO_INICIO 1
#define ORDENADA 2

typedef struct _list TGList;
/**
 * Cria instâncias da TGList;
 * @param char Tipo de Política de Inserção 
 *  Aceita os valores NO_INICIO, NO_FIM, ORDENADA
 */
TGList* TGList_create(char);
/**
 * Política de inserção da lista. 
 * Obedece ao parâmetro passado na criação da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TGList_insert(TGList*, int);

/**
 * Imprime a lista do início para o fim.
 */
void TGList_print(TGList*);

#endif