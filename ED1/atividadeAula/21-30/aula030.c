#include <stdio.h>
#include <string.h>

struct jogador{
  char nome[50];
  int vidas;
  int pontuacao;
};

int main (){
    struct jogador player1 = {
        .vidas = 3,
        .pontuacao = 0
    };
    char nome_digitado[50];
    printf("digite o nome do seu personagem:\n");
    scanf("%[^\n]", nome_digitado);
    strcpy(player1.nome, nome_digitado);
    printf("personagem criado! bem vindo, %s!\n", player1.nome);
    printf("vidas: %d, Pontuação: %d\n", player1.vidas, player1.pontuacao);
    return 0;
}
