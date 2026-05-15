#include <stdio.h>

int soma_vetor(int n, int v[], int i) {
  if (i == n) {
    return 0;
  }
  if (v[i] > 0) {
    return 1 + soma_vetor(n, v, i + 1);
  }
  return soma_vetor(n, v, i + 1);
}

int main() {
  int n;
  printf("quantos cristais o mago tem?\n");
  scanf("%d", &n);
  int v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int r = soma_vetor(n, v, 0);
  printf("%d\n", r);
  return 0;
}
