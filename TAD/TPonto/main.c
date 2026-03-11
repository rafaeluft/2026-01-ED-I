





#include "TPonto.h"

int main(){
    TPonto* novo = TPonto_create(3, 5);
    //novo->x = 10;
    TPonto_print(novo);
    return 0;
}