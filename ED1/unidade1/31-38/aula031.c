#include <stdio.h>

typedef struct{
    int pontos;
    float pos_x;
    float pos_y;
}coletavel;

int main (){
    coletavel gemarara;
    printf("digite o número de pontos da gema:\n");
    scanf("%d", &gemarara.pontos);
    printf("digite os valores da posição x e y:\n");
    scanf("%f %f", &gemarara.pos_x, &gemarara.pos_y);
    printf("coletável criado!\n");
    printf("valor: %d\n", gemarara.pontos);
    printf("posição: (%f, %f)\n", gemarara.pos_x, gemarara.pos_y);
    return 0;
}
