#include "TGList.h"
#include <stdio.h>

int main(){
    //A lista1 só insere no início
    TGList* lista1 = TGList_create(NO_INICIO);
    //A lista2 só insere no fim
    TGList* lista2 = TGList_create(NO_FIM);
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++){
        if(!TGList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
        if(!TGList_insert(lista2, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    }
    puts("Lista 1 (politica de insercao no inicio):");
    TGList_print(lista1);
    puts("Lista 2 (politica de insercao no fim):");
    TGList_print(lista2);
    return 0;
}