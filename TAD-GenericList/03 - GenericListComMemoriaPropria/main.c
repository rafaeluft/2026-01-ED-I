#include "TGList.h"
#include <stdio.h>


void print_float(void* pinfo){
    float *p = (float*) pinfo;
    printf("(%0.2f)-> ", *p);
}

void print_int(void* pinfo){
    int *p = (int*) pinfo;
    printf("(%d)-> ", *p);
}

void print_s(void* pinfo){
    char* ps = (char*) pinfo;
    printf("%s ", ps);
}
int main(){
    //A lista1 só insere no início
    TGList* lista1 = TGList_create(NO_INICIO, print_float, sizeof(float));
    //A lista2 só insere no fim
    TGList* lista2 = TGList_create(NO_FIM, print_float, sizeof(float));
    //int V[] = {1, 2, 3, 4, 5}, i;
    float V[] = {1.3, 2.2, 3.45, 4.678, 5.7778};
    for(int i = 0; i<5; i++){
        if(!TGList_insert(lista1, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%f\n", i, V[i]);
        if(!TGList_insert(lista2, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%f\n", i, V[i]);
    }
    puts("Lista 1 (politica de insercao no inicio):");
    TGList_print(lista1);
    puts("Lista 2 (politica de insercao no fim):");
    TGList_print(lista2);

    //Problema: Quando eu alterava o valor na main, estava refletindo na lista! 
    V[0] = 0.0;
    //Não mais...
    puts("Lista 1 (politica de insercao no inicio):");
    TGList_print(lista1);
    puts("Lista 2 (politica de insercao no fim):");
    TGList_print(lista2);

    TGList* lista3 = TGList_create(NO_FIM, print_s, 64);
    char strings[3][64] = {"ED-I", "eh facil", "demais!"}, i;
    for(i = 0; i<3; i++)
        if(!TGList_insert(lista3, strings[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%s\n", i, strings[i]);
    puts("Lista de strings:");
    TGList_print(lista3);
    return 0;
}