#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = TLList_create();
    TLList* lista2 = TLList_create();
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!TLList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista1);
    for(i = 4; i>=0; i--)
        if(!TLList_insert(lista2, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista2);
    //exemplo de uso da concatenate exercicio 1
    TLList *lista_conc = TLList_conca_func_tad(lista1, lista2);
    TLList_print(lista_conc);
    return 0;
}