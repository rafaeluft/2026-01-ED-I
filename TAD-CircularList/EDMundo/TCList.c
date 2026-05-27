#include "TCList.h"
#include<stdio.h>
#include <stdlib.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    unsigned int qty;
};
//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL)
    {
        novo->prox = NULL;
        novo->info = info;
    }
    return novo;
}

TCList* TCList_create(){
    TCList* nova = malloc(sizeof(TCList));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->qty = 0;
    }
    return nova;
}

/**
 * Rodar por n vezes e excluir.
 * @param TCList* lista 
 * @param int numero de vezes que a lista vai circular para excluir
 */
void TCList_circ_n_delete(TCList* lista, int moeda){
    TNo* aux = lista->inicio;
    //Vamos parar em um anterior ao que sera excluido
    for(int i=1; i<moeda; i++)
        aux = aux->prox;
    
    //Excluir o aux->prox
    TNo* excluir = aux->prox;
    //Ligando o prox no prox do no a ser excluido
    aux->prox = excluir->prox;
    free(excluir);
    lista->qty--;
    //Mudando o inicio da lista
    lista->inicio = aux->prox;
    //printf("Vou excluir o %d\n", aux->prox->info);
}
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TCList_insert(TCList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) 
        return false; 
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else{
        TNo *aux = lista->inicio;
        //Quem eh o ultimo?
        while(aux->prox != lista->inicio)
            aux = aux->prox;
        //Aux eh o ultimo elemento da lista
        aux->prox = novo;
    }
    novo->prox = lista->inicio;
    lista->qty++;
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TCList_print(TCList* lista){
    TNo* aux = lista->inicio;
    if(aux!=NULL)
        do{
            printf("%d->", aux->info);
            aux = aux->prox;
        }while(aux!=lista->inicio);
    putchar('\n');
}

/**
 * Retorna a quantidade atual da lista
 */
unsigned int TCList_get_qty(TCList* lista){
    if(lista!= NULL)
        return lista->qty;
    return 0;
}
/**
 * Retorna o valor do nó localizado no início da lista
 */
bool TCList_get_inicio_info(TCList* lista , int* pvalor){
    if(lista!=NULL && lista->inicio != NULL){
        *pvalor = lista->inicio->info;
        return true;
    }
    return false;
}