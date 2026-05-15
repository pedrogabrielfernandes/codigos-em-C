#include <stdio.h>

int main() {
   int vida_jogador = 100;
   int *ponteiro_vida;
   vida_jogador -= 50;
   printf("o jogador sofreu dano! vida atual: %d\n", vida_jogador);
   ponteiro_vida = &vida_jogador;
   *ponteiro_vida = 100;
   printf("power-up coletado! sua vida foi restaurada para: %d\n", *ponteiro_vida);
    return 0;
}
