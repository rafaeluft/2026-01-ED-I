#include "TCList.h"
#include <stdio.h>

int main(){
    TCList* lista1 = TCList_create();

    int N, M;
    scanf("%d %d", &N, &M);
    //Inicializar a lista
    for(int i=1; i<=N; i++)
        TCList_insert(lista1, i);
    
    while(TCList_get_qty(lista1)>1){
        TCList_circ_n_delete(lista1, M);
        //TCList_print(lista1);
    }
    int pos;
    if(TCList_get_inicio_info(lista1, &pos))
        printf("%d\n", pos);    
    return 0;
}