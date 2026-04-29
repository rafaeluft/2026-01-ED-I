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
    //TODO: implementar a create
    return NULL;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert_begin(TLList* lista, int info){
//TODO: Implementar a função de inserção no inicio
return false;
}
/**
 * Imprime a lista do início para o fim.
 */
void TLList_print(TLList* lista){
//TODO: Implementar a print
puts("A função print nao está implementada ainda!");
}