#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _stack Stack;
/**
 * Cria instâncias da pilha estática
 * de tamanho finito;
 * @return Stack* ponteiro para a pilha
 */
Stack* Stack_create();
/**
 * Tenta inserir um elemento inteiro na pilha;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para uma pilha
 * @param int o valor do inteiro para ser inserido na pilha
 */
bool Stack_push(Stack*, int);
/**
 * Tenta remover um elemento da pilha.
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_pop(Stack*, int*);

/**
 * Tenta acessar o elemento do topo sem desempilhar;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_head(Stack*, int*);
/**
 * Desaloca os recursos da pilha;
 * @param Stack* instância de uma pilha
 */
void Stack_destroy(Stack*);

//Auxiliares
/**
 * Devolve a quantidade de elementos atuais da pilha.
 * @param Stack* instância da pilha
 * @return unsigned int com a quantidade de elementos atuais da pilha;
 */
unsigned int Stack_len(Stack*);
/**
 * Retorna se a pilha está atualmente vazia.
 * @param Stack* instância da pilha
 * @return bool informando se está vazia
 */
bool Stack_is_empty(Stack*);
/**
 * Retorna se a pilha está atualmente cheia.
 * @param Stack* instância da pilha
 * @return bool informando se está cheia
 */
bool Stack_is_full(Stack*);

#endif