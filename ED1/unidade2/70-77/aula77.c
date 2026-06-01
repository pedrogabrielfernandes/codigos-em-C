#include <stdio.h>

typedef struct {
  int id;
  int pontos;
} jogador;

int particao(int e, int d, jogador v[]) {
  jogador pivo = v[d];
  int j = e - 1;
  int i;
  for (i = e; i < d; i++) {
    if (v[i].pontos >= pivo.pontos) {
      j++;
      jogador temp = v[j];
      v[j] = v[i];
      v[i] = temp;
    }
  }
  jogador temp = v[j + 1];
  v[j + 1] = v[d];
  v[d] = temp;
  return j + 1;
}

void quickSort(int i, int f, jogador v[]) {
  if (i < f) {
    int p = particao(i, f, v);
    quickSort(i, p - 1, v);
    quickSort(p + 1, f, v);
  }
}

int main() {
  int n;
  printf("valor de n:\n");
  scanf("%d", &n);
  jogador v[n];
  printf("preencha o vetor\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].id, &v[i].pontos);
  }
  quickSort(0, n - 1, v);
  for (int i = 0; i < n; i++) {
    printf("%d- %d\n", v[i].id, v[i].pontos);
  }
  return 0;
}
