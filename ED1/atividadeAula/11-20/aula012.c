#include <stdio.h>
#include <string.h>

int main (){
    char nome_jogador [50];
    printf("digite o seu nome de jogador: ");
    scanf("%[^\n]", nome_jogador);
    if (strlen(nome_jogador) <= 15){
        printf("nome válido! bem vindo ao jogo, %s\n", nome_jogador);
    }
    else {
        printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres\n");
    }
    return 0;
}
