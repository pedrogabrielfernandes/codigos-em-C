#include <stdio.h>

typedef struct {
  char nome[50];
  int pontos;
} jogador;

void ler(jogador *p) { scanf("%s %d", p->nome, &p->pontos); }

int main() {
  int n;
  printf("digite a quantidade de jogadores:\n");
  scanf("%d", &n);
  jogador v[n];
  int i, j;
  printf("preencha os dados dos jogadores:\n");
  for (i = 0; i < n; i++) {
    ler(&v[i]);
  }
  for (i = 1; i < n; i++) {
    jogador x = v[i];
    for (j = i - 1; j >= 0 && x.pontos < v[j].pontos; j--) {
      v[j + 1] = v[j];
    }
    v[j + 1] = x;
  }
  printf("imprimindo em ordem decresente:\n");
  for (i = n - 1; i >= 0; i--) {
    printf("%d %s\n", v[i].pontos, v[i].nome);
  }
  return 0;
}
