#include <stdio.h>

typedef struct {
  int id;
  int nivel;
} naves;

void intercalar(int e, int m, int d, naves v[]) {
  int n1 = (m - e) + 1;
  int n2 = (d - m);
  naves E[n1];
  naves D[n2];
  int i, j;
  int k = e;
  for (i = 0; i < n1; i++) {
    E[i] = v[e + i];
  }
  for (j = 0; j < n2; j++) {
    D[j] = v[m + 1 + j];
  }
  i = 0;
  j = 0;
  while (i < n1 && j < n2) {
    if (E[i].nivel < D[j].nivel) {
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

void mergeSort(int i, int f, naves v[]) {
  if (i < f) {
    int m = (i + f) / 2;
    mergeSort(i, m, v);
    mergeSort(m + 1, f, v);
    intercalar(i, m, f, v);
  }
}

int main() {
  int n;
  printf("defina o tamanho do vetor:\n");
  scanf("%d", &n);
  naves v[n];
  printf("defina id e nivel das naves inimigas:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].id, &v[i].nivel);
  }
  mergeSort(0, n - 1, v);
  printf("imprimindo o vetor:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i].id);
  }
  printf("\n");
  return 0;
}
