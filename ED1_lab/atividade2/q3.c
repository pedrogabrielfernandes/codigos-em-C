#include <stdio.h>

void soma(int *a, int *b, int *resultado){
    *resultado = *a+*b;
    printf("resultado da soma: %d\n", *resultado);
}

int main (){
    int x, y;
    int z = 0;
    int *px, *py, *pz;
    px = &x;
    py = &y;
    pz = &z;
    printf("digite dois valores para realizar a soma: \n");
    scanf("%d %d", &x, &y);
    soma (px, py, pz);
    return 0;
}
