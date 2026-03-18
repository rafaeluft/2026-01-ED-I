#include "Stack.h"
#define N 10
#include <stdlib.h>

struct _stack{
    int data[N];//Armazenar os elementos da pilha
    unsigned int qty;//marcar a quantidade atual de elemntos na pilha
};

/**
 * Cria instâncias da pilha estática
 * de tamanho finito;
 * @return Stack* ponteiro para a pilha
 */
Stack* Stack_create(){
    Stack* novo = malloc(sizeof(Stack));
    if(novo){
        //Toda pilha recém criada tem zero elementos
        novo->qty = 0;
    }
    return novo;
}
/**
 * Tenta inserir um elemento inteiro na pilha;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para uma pilha
 * @param int o valor do inteiro para ser inserido na pilha
 */
bool Stack_push(Stack* pilha, int valor){
    //Saber se a pilha está cheia
    if(Stack_is_full(pilha))
        return false;
    pilha->data[pilha->qty] = valor;
    pilha->qty++;
    return true;
}
/**
 * Tenta remover um elemento da pilha.
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_pop(Stack* pilha, int* pvalor){
    if(Stack_is_empty(pilha))
        return false;
    int topo = pilha->data[pilha->qty -1];
    *pvalor = topo;
    pilha->qty--;
    return true;
}

/**
 * Tenta acessar o elemento do topo sem desempilhar;
 * @return bool informando sobre o sucesso da operação
 * @param Stack* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */
bool Stack_head(Stack* pilha, int* pvalor){
    if(Stack_is_empty(pilha))
        return false;
    int topo = pilha->data[pilha->qty -1];
    *pvalor = topo;
    return true;
}
/**
 * Desaloca os recursos da pilha;
 * @param Stack* instância de uma pilha
 */
void Stack_destroy(Stack* pilha){
    free(pilha);
}

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
    return pilha->qty == N;
}
