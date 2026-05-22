#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[50];
  int kills;
} jogador;

int main() {
  int n;
  printf("digite a quantidade de jogadores na partida\n");
  scanf("%d", &n);
  jogador *v = malloc(n * sizeof(jogador));
  for (int i = 0; i < n; i++) {
    scanf("%s %d", v[i].nome, &v[i].kills);
  }
  for (int i = 0; i < n; i++) {
    int imaior = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j].kills > v[imaior].kills) {
        imaior = j;
      }
    }
    jogador temp;
    temp = v[i];
    v[i] = v[imaior];
    v[imaior] = temp;
  }
  for (int i = 0; i < n; i++) {
    printf("%s, kills: %d\n", v[i].nome, v[i].kills);
  }
  free(v);
  return 0;
}
