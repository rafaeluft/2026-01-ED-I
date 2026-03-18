#ifndef RACIONAL_H
#define RACIONAL_H
#include <stdbool.h>
typedef struct _racional Racional;
/**
 * Cria instâncias de números racionais;
 * @param int : numerador
 * @param int : denominador
 * @return Racional*
 */
Racional* R_create(int,int);
/**
 * Realiza a soma de duas frações
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return Racional* uma instância de uma nova fração contendo o resultado da soma
 */
Racional* R_soma(Racional*, Racional*);
/**
 * Realiza a multiplicação de duas frações
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return Racional* uma instância de uma nova fração contendo o resultado da operação.
 */
Racional* R_multi(Racional*, Racional*);
/**
 * Checa se duas frações são iguais
 * @param Racional* primeira fração
 * @param Racional* segunda fração
 * @return bool informando se são iguais
 */
bool R_iguais(Racional*, Racional*);
//Outras funções
/**
 * Imprime a fração;
 * @param Racional* instância para uma fração
 */
void R_print(Racional*);

#endif