#include "TDList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int info;
    struct _no *prox, *ant;
}TNo;

struct _list{
    TNo* inicio, *fim;
};

TNo* TNo_create_n_fill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL){
        novo->info = info;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    return novo;
}

/**
 * Cria instâncias da TDList;
 */
TDList* TDList_create(){
    TDList* nova = malloc(sizeof(TDList));
    if(nova != NULL){
        nova->fim = NULL;
        nova->inicio = NULL;
    }
    return nova;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TDList_insert_begin(TDList* lista, int info){
    TNo* novo = TNo_create_n_fill(info);
    if(novo == NULL) return false;
    if(lista->inicio == NULL)
        lista->fim = novo;
    else{
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
    }
    lista->inicio = novo;
    return true;
}

/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TDList_insert_end(TDList* lista, int info){
    TNo* novo = TNo_create_n_fill(info);
    if(novo == NULL) return false;
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else{
        novo->ant = lista->fim;
        lista->fim->prox = novo;
    }
    lista->fim = novo;
    return true;
}

/**
 * Imprime a lista do início para o fim.
 */
void TDList_print(TDList* lista){
    for(TNo* aux = lista->inicio; aux; aux = aux->prox)
        printf("%d-> ", aux->info);
    putchar('\n');
}
/**
 * Imprime a lista do fim para o início.
 */
void TDList_reverse_print(TDList* lista){
    TNo* aux = lista->fim;
    while(aux){
        printf("%d-> ", aux->info);
        aux = aux->ant;
    }
    putchar('\n');
}