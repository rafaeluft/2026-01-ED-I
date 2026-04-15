#include "../Stack.h"
#include <stdio.h>
#include <stdbool.h>
int main(){
    char op; int valor;
    Stack *princ = Stack_create();
    Stack *sec = Stack_create();
    int temp;
    bool found = false;

    do{
        scanf("%c %d\n", &op, &valor);
        switch(op){
            case 'i': if(!Stack_push(princ, valor))
                        printf("overflow\n");
                        break;
            case 'r': 
                found = false;
                while(Stack_pop(princ, &temp)){
                    printf("%d,", temp);
                    if(temp == valor){
                        found = true;
                        break;
                    }
                    Stack_push(sec, temp);
                }
                if(!found)
                    printf("underflow");
                putchar('\n');
                //Retornando os valores para o est principal
                while(Stack_pop(sec, &temp))
                    Stack_push(princ, temp);
                break;
        }
        //printf("%c %d\n", op, valor);
    }while(valor != 0);
    return 0;
}