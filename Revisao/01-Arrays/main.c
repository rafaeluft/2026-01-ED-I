#include<stdio.h>
#define MAX 10




int main(){
    int V[MAX], x;
    //Entrada dos dados
    for(int i=0; i<MAX; i++)
        scanf("%d", &V[i]);
    scanf("%d", &x);

    //Processamento e saída
    for(int i=0; i<MAX; i++)
        if(V[i] % x == 0)
            printf("%d ", V[i]);
    putchar('\n');
    return 0;
}