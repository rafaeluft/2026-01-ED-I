#include "Racional.h"
#include <stdlib.h>
#include <stdio.h>

struct _racional{
    int num, den;
};

/**
 * Cria instâncias de números racionais;
 * @param int : numerador
 * @param int : denominador
 * @return Racional*
 */
Racional* R_create(int num,int den){
    Racional* nova = malloc(sizeof(Racional));
    if(nova){
        nova->num = num;
        nova->den = den;
    }
    return nova;
}
/**
 * Realiza a soma de duas frações
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return Racional* uma instância de uma nova fração contendo o resultado da soma
 */
Racional* R_soma(Racional* f1, Racional* f2){
    if(f1->den == f2->den){
        return R_create(f1->num+f2->num, f1->den);
    }else{
        int d = f1->den * f2->den;
        int n = f1->num*f2->den + f2->num * f1->den;
        return R_create(n, d);
    }
}
/**
 * Realiza a multiplicação de duas frações
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return Racional* uma instância de uma nova fração contendo o resultado da operação.
 */
Racional* R_multi(Racional* f1, Racional* f2){
    return R_create(f1->num*f2->num, f1->den*f2->den);
}
/**
 * Checa se duas frações são iguais
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return bool informando se são iguais
 */
bool R_iguais(Racional* f1, Racional* f2){
    return f1->num * f2->den == f2->num*f1->den;
}

/**
 * Imprime a fração;
 * @param Racional* instância para uma fração
 */
void R_print(Racional* f){
    printf("%d/%d", f->num, f->den);
}