#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>

struct personagem{
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};

Personagem* cria_party (int num_membros){
    Personagem *v = (Personagem *) malloc(num_membros * sizeof(Personagem));
    return v;
}

void registra_membros(Personagem* party, int num_membros){
    printf("digite os dados da sua party: (nome, classe, nivel e hp)\n");
    for (int i = 0; i < num_membros; i++) {
        scanf("%s %s %d %d", party[i].nome, party[i].classe, &party[i].nivel, &party[i].hp);
    }
}

void exibe_relatorio(Personagem* party, int num_membros){
    for (int i = 0; i < num_membros; i++) {
        printf("%s, %s, nivel: %d, hp: %d\n", party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}

void libera_party(Personagem* party){
    free(party);
}