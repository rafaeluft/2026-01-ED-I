





#ifndef TPONTO_H
#define TPONTO_H
typedef struct _ponto TPonto;
/**
 * Cria instâncias de TPonto;
 * @param float x da coordenada x
 * @param float y da coordenada y
 * @return TPonto* instância para um TPonto
 */
TPonto* TPonto_create(float, float);
/**
 * Imprime um TPonto preenchido.
 */
void TPonto_print(TPonto*);
/**
 * Acessa a coordenada x do Ponto e 
 * copia para a variável passada por parâmetro (via ponteiro)
 */
void TPonto_get_x(TPonto*, float*);

#endif