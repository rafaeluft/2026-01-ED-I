#include "TGList.h"
#include<stdio.h>
#include <stdlib.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    char policy;//Política de inserção
};


//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(int info){
    return NULL;
}
//Headers das funções
bool TGList_insert_begin(TGList* lista, int info);
bool TGList_insert_end(TGList* lista, int info);

TGList* TGList_create(char policy){
    //if(policy) posso testar se os valores estão de acordo...
    TGList* nova = malloc(sizeof(TGList));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->policy = policy;
    }
    return nova;
}
bool TGList_insert(TGList* lista, int info){
    switch(lista->policy){
        case NO_INICIO: return TGList_insert_begin(lista, info);
        case NO_FIM: return TGList_insert_end(lista, info);
    }
    return false;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TGList_insert_begin(TGList* lista, int info){
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
bool TGList_insert_end(TGList* lista, int info){
    TNo* novo = malloc(sizeof(TNo));
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    //Iniciando o campo info do no com o info do parametro da funcao
    novo->info = info;
    novo->prox = NULL;
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else{//a lista nao estah vazia
        TNo* aux = lista->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        //Aux é o ultimo elemento da lista
        aux->prox = novo;
    }
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TGList_print(TGList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}
