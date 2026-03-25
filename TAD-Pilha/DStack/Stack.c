#include "Stack.h"
#include <stdlib.h>

typedef struct _no {
    int info;
    struct _no *prox;
}TNo;

struct _stack{
    unsigned int qty;
    TNo* topo;
};
/**
 * Cria instâncias da pilha estática
 * de tamanho finito;
 * @return Stack* ponteiro para a pilha
 */
Stack* Stack_create(){
    Stack* novo = malloc(sizeof(Stack));
    if(novo != NULL){
        novo->qty = 0;
        novo->topo = NULL;
    }
    return novo;
}
/**
 * Tenta inserir um elemento inteiro na pilha;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para uma pilha
 * @param int o valor do inteiro para ser inserido na pilha
 */
bool Stack_push(Stack* pilha, int info){
    //1. Alocar a estrutura auxiliar TNo;
    TNo* novo = malloc(sizeof(TNo));
    if(novo == NULL) //Stack overflow
        return false;
    //2. Armazenar a info dentro do no
    novo->info = info;
    //3. Fazer a ligação;
    //3.1. Faço o link para o topo atual
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->qty++;
    return true;
}
/**
 * Tenta remover um elemento da pilha.
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_pop(Stack* pilha, int* pinfo){
    //*pinfo = a informação (inteiro) do topo
    if(pilha->topo == NULL)//Pilha vazia
        return false;
    *pinfo = pilha->topo->info;
    TNo* topo_antigo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    //Liberar a memória
    free(topo_antigo);
    pilha->qty--;
    return true;
}

/**
 * Tenta acessar o elemento do topo sem desempilhar;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_head(Stack* pilha, int* pinfo){
    if(pilha->topo == NULL)//Pilha vazia
        return false;
    *pinfo = pilha->topo->info;
    return true;

}
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
unsigned int Stack_len(Stack* pilha){
    return pilha->qty;
}
/**
 * Retorna se a pilha está atualmente vazia.
 * @param Stack* instância da pilha
 * @return bool informando se está vazia
 */
bool Stack_is_empty(Stack* pilha){
    return pilha->qty == 0;
}
/**
 * Retorna se a pilha está atualmente cheia.
 * @param Stack* instância da pilha
 * @return bool informando se está cheia
 */
bool Stack_is_full(Stack* pilha){
    //Por simplicidade vamos assumir que a memória vai ditar isso
    return false;
}

