#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
  srand(time(NULL));
  int idx = e + (rand() % (d - e + 1));
  int temp = v[idx];
  v[idx] = v[d];
  v[d] = temp;
  int j = e - 1;
  int i;
  int pivo = v[d];
  for (i = e; i < d; i++) {
    if (v[i] <= pivo) {
      j++;
      temp = v[j];
      v[j] = v[i];
      v[i] = temp;
    }
  }
  temp = v[j + 1];
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
  printf("numero de jogadores:\n");
  scanf("%d", &n);
  int v[n];
  printf("preencha o vetor:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  quickSort(0, n - 1, v);
  printf("imprimindo o vetor:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
