#include <stdio.h>

int main (){
    float x;
    float *px;
    px = &x;
    printf("digite o valor da cordenada x: \n");
    scanf("%f", &x);
    printf("posição no portal do eixo x: %f\n", x);
    printf("endereço do portal para teletransporte: %p\n", px);
    return 0;
}
