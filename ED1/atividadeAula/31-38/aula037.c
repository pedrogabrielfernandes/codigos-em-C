#include <stdio.h>

typedef struct{
    int vida;
    int pontuacao;
}atributos;

typedef struct{
    char nome [50];
    atributos stats;
}personagem;

int main (){
    personagem jogador;
    printf("qual o nome do seu personagem?\n");
    scanf(" %[^\n]", jogador.nome);
    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;
    printf("Status Inicial -> Nome: %s | Vida: %d | Pontuacao: %d\n",
        jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    printf("o jogador coletou uma moeda!\n");
    jogador.stats.pontuacao += 10;
    printf("o jogador caiu em uma armadilha, o jogador recebeu dano!\n");
    jogador.stats.vida -=25;
    printf("Status Final -> Nome: %s | Vida: %d | Pontuacao: %d\n",
        jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    return 0;
}
