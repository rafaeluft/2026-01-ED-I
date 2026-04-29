#include "TLList.h"
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
    return NULL;
}

TLList* TLList_create(){
    TLList* nova = malloc(sizeof(TLList));
    if(nova != NULL){
        nova->inicio = NULL;
    }
    return nova;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert_begin(TLList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = malloc(sizeof(TNo));
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    //Iniciando o campo info do no com o info do parametro da funcao
    novo->info = info;
    //Fazendo a ligação do novo no com o inicio da lista (se for null, o prox sera null, apenas nesta ocasiao)
    novo->prox = lista->inicio;	
    //Atualizando o inicio para o novo nó recém inserido
    lista->inicio = novo;
    return true;
}
bool TLList_insert_end(TLList* lista, int info){
    //TODO: Implementar a função que insere no fim da lista
    puts("Funcao nao implementada...");
    return false;
}
/**
 * Imprime a lista do início para o fim.
 */
void TLList_print(TLList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}
