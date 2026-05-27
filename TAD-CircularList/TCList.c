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
//TODO: Modifique as funções para funcionar como uma lista circular
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TCList_insert(TCList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) 
        return false; 
    TNo** aux = &(lista->inicio);
    while(*aux!=NULL)
        aux = &(*aux)->prox;
    *aux = novo;
    return true;
}
//TODO: Modifique as funções para funcionar como uma lista circular
/**
 * Imprime a lista do início para o fim.
 */
void TCList_print(TCList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}
