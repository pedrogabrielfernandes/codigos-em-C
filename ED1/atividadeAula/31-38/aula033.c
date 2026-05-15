#include <stdio.h>

typedef struct {
    int x;
    int y;
}posicao;

void mover_personagem (posicao *mover, int movimento_x, int movimento_y){
    mover->x += movimento_x;
    mover->y += movimento_y;
}

int main(){
    posicao posicao_jogador = {
        .x = 0,
        .y = 0
    };
    int movimento_x = 10;
    int movimento_y = 5;
    posicao *ponteiro_posicao;
    ponteiro_posicao = &posicao_jogador;
    printf("posição inicial: X = %d Y = %d\n", posicao_jogador.x, posicao_jogador.y);
    mover_personagem(ponteiro_posicao, movimento_x, movimento_y);
    printf("posição final: X = %d Y = %d\n", posicao_jogador.x, posicao_jogador.y);
    return 0;
}
