#include <stdio.h>

int particao(int e, int d, int v[]) {
  int pivo = v[d];
  int j = e - 1;
  int i;
  for (i = e; i < d; i++) {
    if (v[i] <= pivo) {
      j++;
      int temp = v[j];
      v[j] = v[i];
      v[i] = temp;
    }
  }
  int temp = v[j + 1];
  v[j + 1] = v[d];
  v[d] = temp;
  return j + 1;
}

void quickSort(int i, int f, int v[]) {
  if (i < f) {
    int p = particao(i, f, v);
    quickSort(i, p - 1, v);
    quickSort(p + 1, f, v);
  }
}

int main() {
  int n;
  printf("quantidade de jogadores:\n");
  scanf("%d", &n);
  int v[n];
  printf("informe os MMRs dos jogadores abaixo:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  quickSort(0, n - 1, v);
  printf("imprimindo os MMRs ordenados:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
