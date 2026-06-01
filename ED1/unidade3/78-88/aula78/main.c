#include <stdio.h>
#include "combate.h"

int main (){
    int atk, sword, hp;
    printf("digite o ataque basico incial,  o bônus da espada e vida inicial do inimigo:\n");
    scanf("%d %d %d", &atk, &sword, &hp);
    int atk_total = calcular_atk(atk, sword);
    int hp_restante = aplicar_dano(hp, atk_total);
    printf("o ataque total do herói é: %d\n", atk_total);
    printf("a vida restante do inimigo é: %d\n", hp_restante);
    return 0;
}
