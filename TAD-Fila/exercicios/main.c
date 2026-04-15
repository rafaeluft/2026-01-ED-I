#include <stdio.h>
#include "../Queue.h"
#include "../TStack.h"
//Ex 01 Faz a reversao em elementos da fila
void reverse(Queue* fila){
    Stack* pilha = Stack_create();
    int temp;
    while(Queue_dequeue(fila, &temp)){
        if(!Stack_push(pilha, temp))
            break;
    }
    while(Stack_pop(pilha, &temp))
        if(!Queue_enqueue(fila, temp))
            break;
}
//Ex 02 
void remove_negativos(Queue* fila){
    //TODO...
}
//Ex 03
void fusao_em_ordem_cres(Queue* f1, Queue* f2, Queue *result){
//TODO...    
}
//Ex 04 
void print_queue(Queue* fila){
    Queue* aux = Queue_create();
    int temp;
    puts("O conteudo da fila eh: ");
    while(Queue_dequeue(fila, &temp)){
        printf("%d,", temp);
        //Guardando o elemento em uma fila auxiliar
        Queue_enqueue(aux, temp);
    }
    while(Queue_dequeue(aux, &temp)){
        //Devolvendo o elemento para a fila original
        Queue_enqueue(fila, temp);
    }
    
}
int main(){
    Queue* fila1 = Queue_create();
    Queue* fila2 = Queue_create();
    if(fila1 == NULL){
        printf("Erro ao instanciar a fila.\n");
        return 1;
    }
    int V[6] = {3, 2, 1, -4, -5, -6};
    for(int i=5; i>=0; i--){
        if(!Queue_enqueue((i%2) ? fila1:fila2, V[i]))
            printf("Erro ao inserir o elemento V[%i]=%i\n", i, V[i]);
    }
    //Ex 04
    print_queue(fila1);
    //Ex 02 Remover os negativos
    remove_negativos(fila1);
    print_queue(fila1);
    //Ex 01
    reverse(fila1);

    //Para ex 03
    Queue* result = Queue_create();
    fusao_em_ordem_cres(fila1, fila2, result);
    print_queue(result);

    int temp;
    while(Queue_dequeue(fila1, &temp)){
        printf("Elemento removido da Fila: %d\n", temp);
    }
    return 0;
}