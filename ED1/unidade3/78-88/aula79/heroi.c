#include "heroi.h"
#include <stdio.h>
#include <stdlib.h>

struct heroi{
  char nome[50]; 
  int hp;
  int atk;
};

Heroi* cria(int n){
    Heroi *h = malloc(n * sizeof(Heroi));
    return h;
}

void ler(Heroi *v, int n){
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", v[i].nome, &v[i].hp, &v[i].atk);
    }
}

void imprime(Heroi *v, int n){
    for (int i = 0; i < n; i++) {
        printf("nome: %s, vida: %d, ataque: %d\n", v[i].nome, v[i].hp, v[i].atk);
    }
}