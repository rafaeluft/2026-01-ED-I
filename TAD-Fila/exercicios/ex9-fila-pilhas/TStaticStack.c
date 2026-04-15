#include "TStack.h"
#include <stdlib.h>
#define MAX 5
struct _stack{
    int data[MAX];
    unsigned int qty;
};

Stack* Stack_create(){
    Stack* novaPilha = malloc(sizeof(Stack));
    if(novaPilha != NULL){
        novaPilha->qty = 0;//Pilhas novas possuem 0 elementos
    }
    return novaPilha;
}
/**
 * Tenta a inserção de um inteiro em uma stack.
 * @param Stack* ponteiro para uma stack instanciada
 * @param int inteiro a ser inserido na Stack
 * @return bool informando do sucesso da operação
 */
bool Stack_push(Stack* pilha, int valor){
    if(pilha != NULL && !Stack_is_full(pilha)){
        pilha->data[pilha->qty++] = valor;
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
bool Stack_pop(Stack* pilha, int* pvalor){
    if(pilha!=NULL && !Stack_is_empty(pilha)){
        unsigned int topo = pilha->qty-1;
        *pvalor = pilha->data[topo];
        pilha->qty--;
        return true;
    }
    return false;
}
/**
 * Libera os recursos da pilha.
 * @param Stack*
 */
void Stack_destroy(Stack* pilha){
    free(pilha);
}
/**
 * Consulta se a pilha está vazia
 */
bool Stack_is_empty(Stack* pilha){
    if(pilha!=NULL){
        return pilha->qty == 0;
    }
    return true;
}
/**
 * Consulta se a pilha está cheia
 */
bool Stack_is_full(Stack* pilha){
    if(pilha!=NULL){
        return pilha->qty == MAX;
    }
    return true;
}
