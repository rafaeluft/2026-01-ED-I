#include "Queue.h"
#include<stdlib.h>

typedef struct _no {
    int info;
    struct _no *prox;
}TNo;

struct _queue{
    TNo* end;
    unsigned int qty;
};
Queue* Queue_create(){
    Queue* nova = malloc(sizeof(Queue));
    if(nova!=NULL){
        nova->end = NULL;
        nova->qty = 0;
    }
    return nova;
}
/**
 * Tenta realizar a inserção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param int variável inteira cujo valor será armazenado na Fila
 * @return bool informando se a operação pode ser realizada.
 */
bool Queue_enqueue(Queue* fila, int info){

    if(fila == NULL) return false;

    TNo* novo = malloc(sizeof(TNo));
    if(novo == NULL) return false;
    novo->info = info;
    novo->prox = novo;
    //fila nao esta vazia    
    if(fila->end != NULL)
    {
        novo->prox = fila->end->prox;
        fila->end->prox = novo;
    }
    fila->end = novo;
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
bool Queue_dequeue(Queue* fila, int* pinfo){
    if(fila==NULL || Queue_is_empty(fila))
        return false;
    TNo* oldBegin = fila->end->prox;
    *pinfo = oldBegin->info;
    fila->end->prox = oldBegin->prox;
    free(oldBegin);
    fila->qty--;
    //Deletei o último?
    if(fila->qty==0)
        fila->end = NULL;
    return true;
}
/**
 * Checa se a fila está cheia;
 * @param Queue* instância da fila
 * @return bool informando se está cheia.
 */
bool Queue_is_full(Queue* fila){
    //O correto seria fazer uma prereserva de memória!
    //Conforme discutido em aula.
    return false;
}
/**
 * Checa se a fila está vazia;
 * @param Queue* instância da fila
 * @return bool informando se está vazia.
 */
bool Queue_is_empty(Queue* fila){
    //Novamente cabe uma discussão aqui...
    if(fila==NULL || fila->qty == 0) return true;

    return false;
}
/**
 * Retorna a quantidade de elementos atualmente na fila
 * @param Queue* instância da fila
 * @return unsigned int : Quantidade de elementos presentes na fila.
 */
unsigned int Queue_get_qty(Queue* fila){
    if(fila)
        return fila->qty;
    return 0;
}