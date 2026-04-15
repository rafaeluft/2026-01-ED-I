#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct _queue Queue;
/**
 * Cria instâncias da fila;
 * @return Queue* Ponteiro para uma fila válida 
 * ou NULL caso não consiga memória para alocação
 */
Queue* Queue_create();
/**
 * Tenta realizar a inserção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param int variável inteira cujo valor será armazenado na Fila
 * @return bool informando se a operação pode ser realizada.
 */
bool Queue_enqueue(Queue*, int);
/**
 * Tenta realizar a remoção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param int* ponteiro para variável inteira que receberá o valor removido da fila
 * @return bool informando se a operação pode ser realizada.
 * 
 * Uso: int temp;
 * if(Queue_dequeue(instanceOfQueue, &temp))
 *  printf("Deu certo remover da fila. Valor do elemento: %d", temp);
 * else
 *  printf("Nao foi possivel remover da fila (provavelmente está vazia)");
 */
bool Queue_dequeue(Queue*, int*);
/**
 * Checa se a fila está cheia;
 * @param Queue* instância da fila
 * @return bool informando se está cheia.
 */
bool Queue_is_full(Queue*);
/**
 * Checa se a fila está vazia;
 * @param Queue* instância da fila
 * @return bool informando se está vazia.
 */
bool Queue_is_empty(Queue*);
/**
 * Retorna a quantidade de elementos atualmente na fila
 * @param Queue* instância da fila
 * @return unsigned int : Quantidade de elementos presentes na fila.
 */
unsigned int Queue_get_qty(Queue*);
#endif