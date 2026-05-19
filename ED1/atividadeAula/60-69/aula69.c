#include <stdio.h>

void intercalar(int n, int v1[], int m, int v2[], int r[]) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n && j < m) {
    if (v1[i] < v2[j]) {
      r[k] = v1[i];
      i++;
    } else {
      r[k] = v2[j];
      j++;
    }
    k++;
  }
  while (i < n) {
    r[k] = v1[i];
    i++;
    k++;
  }
  while (j < m) {
    r[k] = v2[j];
    j++;
    k++;
  }
}

int main() {
  int n, m;
  printf("digite o numero de inimigos de v1:\n");
  scanf("%d", &n);
  int v1[n];
  printf("digite o nivel de ameaça de v1:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v1[i]);
  }
  printf("digite o numero de inimigos de v2:\n");
  scanf("%d", &m);
  int v2[m];
  printf("digite o nivel de ameaça de v2:\n");
  for (int j = 0; j < m; j++) {
    scanf("%d", &v2[j]);
  }
  int r[n + m];
  intercalar(n, v1, m, v2, r);
  printf("imprimindo o vetor:\n");
  for (int k = 0; k < n + m; k++) {
    printf("%d ", r[k]);
  }
  printf("\n");
  return 0;
}
