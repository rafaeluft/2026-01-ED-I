#include "TCList.h"
#include <stdio.h>

int main(){
    TCList* lista1 = TCList_create();
    TCList* lista2 = TCList_create();
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!TCList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TCList_print(lista1);
    for(i = 4; i>=0; i--)
        if(!TCList_insert(lista2, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TCList_print(lista2);
    return 0;
}