#include <stdio.h>

int busca(int v[], int i, int f) {
  int e, d;
  if (i == f) {
    return v[i];
  }
  if (i < f) {
    int m = (i + f) / 2;
    e = busca(v, i, m);
    d = busca(v, m + 1, f);
  }
  if (e > d) {
    return e;
  } else {
    return d;
  }
}

int main() {
  int n;
  printf("quantidade de fragmentos:\n");
  scanf("%d", &n);
  int v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int r = busca(v, 0, n - 1);
  printf("o fragmento com o maior nível é: %d\n", r);
  return 0;
}
