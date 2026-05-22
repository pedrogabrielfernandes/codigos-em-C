#include <stdio.h>

struct jogador{
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};

int main (){
    struct jogador heroi;
    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;

    printf("início da fase! posição: %.1f\n", heroi.pos_x);
    printf("pontos: %d\n", heroi.pontuacao);
    printf("pulo duplo: não\n");

    heroi.pontuacao = 10;
    heroi.tem_pulo_duplo = 1;
    printf("itens coletados! posição: %.1f\n", heroi.pos_x);
    printf("pontos: %d\n", heroi.pontuacao);
    printf("pulo duplo: sim\n");
    return 0;
}
