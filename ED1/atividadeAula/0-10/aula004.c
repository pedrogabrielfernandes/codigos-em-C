#include <stdio.h>

void power_up (int *pontuacao_dupla){
    *pontuacao_dupla *= 2;
}

int main (){
    int pontuacao_jogador =1500;
    printf("pontuação antes do power-up: %d\n", pontuacao_jogador);
    power_up(&pontuacao_jogador);
    printf("pontuação após power-up: %d\n", pontuacao_jogador);
    return 0;
}
