#include "TGList.h"
#include <stdio.h>
#include <string.h>

int cmp_float(const void* f1,const  void *f2){
    float *pf1 = (float*) f1;
    float *pf2 = (float*) f2;

    return (*pf1 > *pf2) ? -1: (*pf1 < *pf2)? 1:0;
}

int cmp_int(const void* f1,const  void *f2){
    int *pf1 = (int*) f1;
    int *pf2 = (int*) f2;

    return (*pf2 - *pf1);
}

int cmp_str(const void* s1,const  void *s2){
    char* ss1 = (char*) s1;
    char* ss2 = (char*) s2;

    return strcmp(ss2, ss1);
}
void print_float(const void* pinfo){
    float *p = (float*) pinfo;
    printf("(%0.2f)-> ", *p);
}

void print_int(const void* pinfo){
    int *p = (int*) pinfo;
    printf("(%d)-> ", *p);
}

void print_s(const void* pinfo){
    char* ps = (char*) pinfo;
    printf("%s ", ps);
}
int main(){
    //A lista_floats agora é ordenada 
    TGList* lista_ints = TGList_create(
        ORDENADA, 
        print_int, 
        sizeof(int), 
        cmp_int
    );

    int Vint[] = {4, 1, 3, 6, 5};
    for(int i = 0; i<5; i++){
        if(!TGList_insert(lista_ints, &Vint[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, Vint[i]);
    }
    puts("Lista de inteiros (ordenados)");
    TGList_print(lista_ints);

    //Inteiros
    TGList* lista_floats = TGList_create(
        ORDENADA, 
        print_float, 
        sizeof(float), 
        cmp_float
    );

    float V[] = {4.3, 1.2, 3.45, 6.678, 5.7778};
    for(int i = 0; i<5; i++){
        if(!TGList_insert(lista_floats, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%f\n", i, V[i]);
    }
    puts("Lista de floats ordenados");
    TGList_print(lista_floats);

    TGList* lista3 = TGList_create(ORDENADA, print_s, 64, cmp_str);
    char strings[3][64] = {"Edmundo", "Adriana", "Leandro"}, i;
    for(i = 0; i<3; i++)
        if(!TGList_insert(lista3, strings[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%s\n", i, strings[i]);
    puts("Lista de strings:");
    TGList_print(lista3);
    return 0;
}