#include <stdio.h>

typedef struct {
  int id;
  int pontos;
} jogador;

void bolha(int n, jogador v[]) {
  int i, j;
  for (int i = 0; i < n - 1; i++) {
    int trocou = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (v[j].pontos < v[j + 1].pontos) {
        jogador temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
        trocou = 1;
      }
    }
    if (trocou == 0) {
      return;
    }
  }
}

int main() {
  int n;
  printf("digite a quantidades de jogadores:\n");
  scanf("%d", &n);
  jogador v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].id, &v[i].pontos);
  }
  bolha(n, v);
  printf("imprimindo o vetor:\n");
  for (int i = 0; i < n; i--) {
    printf("%d %d\n", v[i].id, v[i].pontos);
  }
  return 0;
}
