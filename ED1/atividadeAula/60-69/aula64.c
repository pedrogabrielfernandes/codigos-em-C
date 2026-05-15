#include <stdio.h>

int main() {
  int n;
  printf("qual a quantidade de fragmentos?\n");
  scanf("%d", &n);
  int v[n];
  int i, j;
  printf("preencha o vetor abaixo:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (i = 0; i < n; i++) {
    int x = v[i];
    for (j = i - 1; j >= 0 && x < v[j]; j--) {
      v[j + 1] = v[j];
    }
    v[j + 1] = x;
  }
  printf("vetores ordenados abaixo:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
