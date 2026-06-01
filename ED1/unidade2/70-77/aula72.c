#include <stdio.h>

typedef struct {
  int posicao;
  char nome[50];
} piloto;

void intercala(int e, int m, int d, piloto v[]) {
  int n1 = (m - e) + 1;
  int n2 = d - m;
  int k = e;
  piloto E[n1];
  piloto D[n2];
  int i, j;
  for (i = 0; i < n1; i++) {
    E[i] = v[e + i];
  }
  for (j = 0; j < n2; j++) {
    D[j] = v[m + 1 + j];
  }
  i = 0;
  j = 0;
  while (i < n1 && j < n2) {
    if (E[i].posicao < D[j].posicao) {
      v[k] = E[i];
      i++;
    } else {
      v[k] = D[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    v[k] = E[i];
    i++;
    k++;
  }
  while (j < n2) {
    v[k] = D[j];
    j++;
    k++;
  }
}

void mergeSort(int i, int f, piloto v[]) {
  if (i < f) {
    int m = (i + f) / 2;
    mergeSort(i, m, v);
    mergeSort(m + 1, f, v);
    intercala(i, m, f, v);
  }
}

int main() {
  int n;
  printf("digite a quantidade de pilotos:\n");
  scanf("%d", &n);
  piloto v[n];
  printf("digite as posições e os nomes dos pilotos\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %s", &v[i].posicao, v[i].nome);
  }
  mergeSort(0, n - 1, v);
  printf("imprimindo a tabela\n");
  for (int i = 0; i < n; i++) {
    printf("%dº- %s\n", v[i].posicao, v[i].nome);
  }
  return 0;
}
