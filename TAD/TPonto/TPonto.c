#include "TPonto.h"
#include <stdlib.h>
#include <stdio.h>

struct _ponto{
    float x, y;
};
/**
 * Cria instâncias de TPonto;
 * @param float x da coordenada x
 * @param float y da coordenada y
 * @return TPonto* instância para um TPonto
 */
TPonto* TPonto_create(float x, float y){
    TPonto *novo = malloc(sizeof(TPonto));
    if(novo!=NULL){
        novo->x = x;
        novo->y = y;
    }
    return novo;
}
/**
 * Imprime um TPonto preenchido.
 */
void TPonto_print(TPonto* ponto){
    if(ponto != NULL){
        printf("(%0.2f, %0.2f)", ponto->x, ponto->y);
    }
}
/**
 * Acessa a coordenada x do Ponto e 
 * copia para a variável passada por parâmetro (via ponteiro)
 */
void TPonto_get_x(TPonto* ponto, float* px){
//Todo...
}
