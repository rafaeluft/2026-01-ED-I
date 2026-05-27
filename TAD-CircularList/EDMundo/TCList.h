#ifndef TCLIST_H
#define TCLIST_H
#include <stdbool.h>
/**
TAD Lista circular simplesmente encadeada.
*/
typedef struct _list TCList;
/**
 * Cria instâncias da TCList;
 */
TCList* TCList_create();
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TCList_insert(TCList*, int);
/**
 * Rodar por n vezes e excluir.
 * @param TCList* lista 
 * @param int numero de vezes que a lista vai circular para excluir
 */
void TCList_circ_n_delete(TCList*, int);
/**
 * Imprime a lista do início para o fim.
 */

void TCList_print(TCList*);

/**
 * Retorna a quantidade atual da lista
 */
unsigned int TCList_get_qty(TCList*);
/**
 * Retorna o valor do nó localizado no início da lista
 */
bool TCList_get_inicio_info(TCList*, int*);
#endif