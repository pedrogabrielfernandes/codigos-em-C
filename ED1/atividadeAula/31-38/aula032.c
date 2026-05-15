#include <stdio.h>

typedef struct{
    int posX;
    int posY;
    int moedas;
}personagem;

void atualizarPersonagemComPonteiro (personagem *j){
    j->posX = 10;
    j->posY = 5;
    j -> moedas++;
}

int main (){
    personagem jogador = {
      .posX = 0,
      .posY = 0,
      .moedas = 0
    };
    printf("posição inicial: (%d, %d) - moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);
    atualizarPersonagemComPonteiro(&jogador);
    printf("posição final: (%d, %d) - moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);
    return 0;
}
