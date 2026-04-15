#include "TStack.h"
#include<stdlib.h>




typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}
struct _stack{
    TNo* topo;
};

Stack* Stack_create(){
    Stack* nova = malloc(sizeof(Stack));
    if(nova){
        nova->topo = NULL;
    }
    return nova;
}
/**
 * Tenta a inserção de um inteiro em uma stack.
 * @param Stack* ponteiro para uma stack instanciada
 * @param int inteiro a ser inserido na Stack
 * @return bool informando do sucesso da operação
 */
bool Stack_push(Stack* pilha, int info){
    if(pilha!=NULL){
        TNo* novo = TNo_createNFill(info);
        if(novo == NULL)
            return false;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        return true;
    }
    return false;
}
/**
 * Tenta a remoção do elemento do topo da pilha
 * @param Stack* ponteiro para uma stack instanciada
 * @param int* ponteiro para a variável inteira que receberá o valor do topo
 * @return bool informando do sucesso da operação
 */
bool Stack_pop(Stack* pilha, int* pvalue){
    if(pilha== NULL || pilha->topo == NULL)
        return false;
    *pvalue = pilha->topo->info;
    TNo* aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return true;
}
/**
 * Libera os recursos da pilha.
 * @param Stack*
 */
void Stack_destroy(Stack* pilha){
    if(pilha!=NULL){
        TNo *aux;
        while(pilha->topo){
            aux = pilha->topo;
            pilha->topo = pilha->topo->prox;
            free(aux);
        }
        free(pilha);
    }
}
/**
 * Consulta se a pilha está vazia
 */
bool Stack_is_empty(Stack* pilha){
    if(pilha!=NULL){
        return pilha->topo != NULL;
    }
    return true;
}
/**
 * Consulta se a pilha está cheia
 */
bool Stack_is_full(Stack* pilha){
    if(pilha != NULL)
        return false;
    return true;
}
