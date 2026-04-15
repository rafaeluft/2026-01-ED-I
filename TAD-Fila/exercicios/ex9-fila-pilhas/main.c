#include <stdio.h>
#include "Queue.h"
#include "TStack.h"

int main(){
    Queue* fila1 = Queue_create();
    if(fila1 == NULL){
        printf("Erro ao instanciar a fila.\n");
        return 1;
    }
    /*Stack* V[3] = {Stack_create(), 
                    Stack_create(), 
                    Stack_create()};
    for(int i=0; i<3; i++){
        if(!Queue_enqueue(fila1, (void*)V[i]))
            printf("Erro ao inserir o elemento %i\n", i);
    }
    void* temp;
    while(Queue_dequeue(fila1, &temp)){
        printf("Stack removida da Fila: %p\n", temp);
        Stack* teste = (Stack*) temp;
        Stack_push(teste, 10);
        int temp;
        while(Stack_pop(teste, &temp))
            printf("%p: pop (%d)\n", teste, temp);
    }*/
    char V[3][32] = {"David", 
                    "Ricardo", 
                    "Maria Eduarda"};
    for(int i=0; i<3; i++){
        if(!Queue_enqueue(fila1, (void*)V[i]))
            printf("Erro ao inserir o elemento %i\n", i);
    }
    void* temp;
    while(Queue_dequeue(fila1, &temp)){
        printf("Stack removida da Fila: %s\n", (char*)temp);
    }

    
    return 0;
}