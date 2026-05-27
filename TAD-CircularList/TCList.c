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
    }
    return nova;
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
