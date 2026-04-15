#include "Queue.h"
#define MAX 5
#include <stdlib.h>


struct _queue{
    unsigned int qty, head, tail;
    void* data[MAX];
};
/**
 * Cria instâncias da fila;
 * @return Queue* Ponteiro para uma fila válida 
 * ou NULL caso não consiga memória para alocação
 */
Queue* Queue_create(){
    Queue* nova = malloc(sizeof(Queue));
    if(nova){
        nova->qty = 0;
        nova->tail = 0;
        nova->head = 0;
    }
    return nova;
}
/**
 * Tenta realizar a inserção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param void* variável inteira cujo valor será armazenado na Fila
 * @return bool informando se a operação pode ser realizada.
 */
bool Queue_enqueue(Queue* fila, void* info){
    if(fila == NULL || Queue_is_full(fila))
        return false;
    fila->data[fila->tail] = info;
    fila->tail = (fila->tail+1) % MAX;
    fila->qty++;
    return true;
}
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
bool Queue_dequeue(Queue* fila, void** pinfo){
    if(fila == NULL || Queue_is_empty(fila))
        return false;
    
    *pinfo = fila->data[fila->head];
    fila->head = (fila->head+1) % MAX;
    fila->qty--;
    return true;
}
/**
 * Checa se a fila está cheia;
 * @param Queue* instância da fila
 * @return bool informando se está cheia.
 */
bool Queue_is_full(Queue* fila){
    if(fila){
        return fila->qty == MAX;
    }
    return true;
}
/**
 * Checa se a fila está vazia;
 * @param Queue* instância da fila
 * @return bool informando se está vazia.
 */
bool Queue_is_empty(Queue* fila){
    if(fila){
        return fila->qty == 0;
    }
    return true;
}
/**
 * Retorna a quantidade de elementos atualmente na fila
 * @param Queue* instância da fila
 * @return unsigned int : Quantidade de elementos presentes na fila.
 */
unsigned int Queue_get_qty(Queue* fila){
    return (fila)? fila->qty : 0;
}