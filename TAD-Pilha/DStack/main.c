#include "Stack.h"
#include <stdio.h>

int main(){
    
    int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Stack* pilha1 = Stack_create();
    for(int i=0; i<11; i++){
        if(!Stack_push(pilha1, V[i])){
            printf("Stack overflow: \nNao pude inserir o valor V[%i]= %i\n", i, V[i]);
        }
    }

    int temp;
    while(Stack_pop(pilha1, &temp)){
        printf("%d\n", temp);
    }

    return 0;
}