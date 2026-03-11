





#include "TPonto.h"

int main(){
    TPonto* novo = TPonto_create(3, 5);
    //novo->x = 10;
    TPonto_print(novo);
    float x;
    TPonto_get_x(novo, &x);
    printf("O valor resgatado da variável x eh: %f\n", x);
    return 0;
}