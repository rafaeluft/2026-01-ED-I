#include "Racional.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    Racional* f1 = R_create(1,2);
    Racional* f2 = R_create(3,4);
    printf("Conteudo da fracao 1: ");
    R_print(f1);
    printf("\nConteudo da fracao 2: ");
    R_print(f2);

    Racional* soma = R_soma(f1, f2);
    printf("\nResultado da soma: ");
    R_print(soma);

    Racional* multi = R_multi(f1, f2);
    printf("\nResultado da multiplicação: ");
    R_print(multi);

    Racional* f3 = R_create(2,4);
    bool iguais = R_iguais(f1, f3);
    printf("\n1/2 eh igual a 2/4? %s\n", (iguais)?"sim":"nao");
    iguais = R_iguais(f1, f2);
    printf("1/2 eh igual a 3/4? %s\n", (iguais)?"sim":"nao");
    return 0;
}

