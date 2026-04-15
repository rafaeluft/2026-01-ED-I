#ifndef TSTACK_H
#define TSTACK_H
#include <stdbool.h>

typedef struct _stack Stack;

Stack* Stack_create();
/**
 * Tenta a inserção de um inteiro em uma stack.
 * @param Stack* ponteiro para uma stack instanciada
 * @param int inteiro a ser inserido na Stack
 * @return bool informando do sucesso da operação
 */
bool Stack_push(Stack*, int);
/**
 * Tenta a remoção do elemento do topo da pilha
 * @param Stack* ponteiro para uma stack instanciada
 * @param int* ponteiro para a variável inteira que receberá o valor do topo
 * @return bool informando do sucesso da operação
 */
bool Stack_pop(Stack*, int*);
/**
 * Libera os recursos da pilha.
 * @param Stack*
 */
void Stack_destroy(Stack*);
/**
 * Consulta se a pilha está vazia
 */
bool Stack_is_empty(Stack*);
/**
 * Consulta se a pilha está cheia
 */
bool Stack_is_full(Stack*);

#endif