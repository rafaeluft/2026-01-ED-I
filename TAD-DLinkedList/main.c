#include "TDList.h"
#include <stdio.h>

int main(){
    TDList* lista1 = TDList_create();
    int V[] = {1, 2, 3, 4, 5}, i;
    
    for(i = 0; i<5; i++)
        if(!TDList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);

    TDList_print(lista1);
    TDList_reverse_print(lista1);
    return 0;
}