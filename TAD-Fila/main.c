#include <stdio.h>
#include "Queue.h"


int main(){
    Queue* fila1 = Queue_create();
    if(fila1 == NULL){
        printf("Erro ao instanciar a fila.\n");
        return 1;
    }
    int V[6] = {1, 2, 3, 4, 5, 6};
    for(int i=0; i<6; i++){
        if(!Queue_enqueue(fila1, V[i]))
            printf("Erro ao inserir o elemento V[%i]=%i\n", i, V[i]);
    }
    int temp;
    while(Queue_dequeue(fila1, &temp)){
        printf("Elemento removido da Fila: %d\n", temp);
    }
    return 0;
}