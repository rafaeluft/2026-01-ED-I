#include "TGList.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    void* info; //A lista agora carrega ponteiros para objetos...
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    char policy;//Política de inserção
    void (*ptr_func)(const void*);
    unsigned int obj_size; //Tamanho do objeto(em bytes)
    //A função de comparação
    int (*cmp_func)(const void*, const void*);
};


//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(void* info, unsigned int obj_size){
    TNo* novo = malloc(sizeof(TNo));
    //Se for NULL, nao conseguimos memória
    if(novo != NULL){ 
        novo->info = malloc(obj_size);
        if(novo->info==NULL)
        {
            free(novo);
            novo = NULL;
        }else{
            //novo->info = info;
            memcpy(novo->info, info, obj_size);
            novo->prox = NULL;
        }
    } 
    return novo;
}
//Headers das funções
bool TGList_insert_begin(TGList* lista, void* info);
bool TGList_insert_end(TGList* lista, void* info);
bool TGList_insert_ordenado(TGList*, void* info);

TGList* TGList_create(char policy, void (*ptr_func)(const void*), unsigned int obj_size, int (*cmp_func)(const void*, const void*)){
    //if(policy) posso testar se os valores estão de acordo...
    TGList* nova = malloc(sizeof(TGList));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->policy = policy;
        nova->ptr_func = ptr_func;
        nova->obj_size = obj_size;
        nova->cmp_func = cmp_func;
    }
    return nova;
}
bool TGList_insert(TGList* lista, void* info){

    switch(lista->policy){
        case NO_INICIO: return TGList_insert_begin(lista, info); break;
        case NO_FIM: return TGList_insert_end(lista, info); break;
        case ORDENADA: return TGList_insert_ordenado(lista, info); break;
    }
    return false;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TGList_insert_begin(TGList* lista, void* info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info, lista->obj_size);
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    //Fazendo a ligação do novo no com o inicio da lista (se for null, o prox sera null, apenas nesta ocasiao)
    novo->prox = lista->inicio;	
    //Atualizando o inicio para o novo nó recém inserido
    lista->inicio = novo;
    return true;
}
bool TGList_insert_end(TGList* lista, void* info){
    TNo* novo = TNo_createNFill(info, lista->obj_size);
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{//a lista nao estah vazia
        TNo* aux = lista->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        //Aux é o ultimo elemento da lista
        aux->prox = novo;
    }
    return true;
}
/** Faz a inserção ordenada da lista */
bool TGList_insert_ordenado(TGList* lista, void* info){
    TNo* novo = TNo_createNFill(info, lista->obj_size);
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{//a lista nao estah vazia
        //if o novo elemento é menor do que o início
        if(lista->cmp_func(lista->inicio->info, info) < 0)
        {
            printf("Inseri um menor do que o inicio!;");
            novo->prox = lista->inicio;
            lista->inicio = novo;
        }else{
            TNo* aux = lista->inicio;
            while(aux->prox){
                if(lista->cmp_func(aux->prox->info, info) < 0)
                    break;
                aux = aux->prox;
            }
            //Eu parei pq cheguei a null (ultimo elemento)
            //ou eu parei pq cheguei num elemento tal que o prox->info > info
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TGList_print(TGList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        lista->ptr_func(aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}
