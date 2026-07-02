#include "heroi.h"
#include <stdio.h>

int main(){
    Heroi *h;
    int n;
    printf("valor de n:\n");
    scanf("%d", &n);
    cria(n);
    Heroi *v = cria(n);
    ler(v, n);
    imprime(v, n);
    return 0;
}