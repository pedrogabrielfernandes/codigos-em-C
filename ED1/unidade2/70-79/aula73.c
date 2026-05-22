#include <stdio.h>

void particao(int n, int v[]) {
  int s[n];
  int e = 0;
  int d = n - 1;
  int pivo = v[n - 1];
  for (int i = 0; i < n; i++) {
    if (v[i] <= pivo) {
      s[e] = v[i];
      e++;
    } else {
      s[d] = v[i];
      d--;
    }
  }
  for (int i = 0; i < n; i++) {
    v[i] = s[i];
  }
}

int main() {
  int n;
  printf("digite a quantidades de itens:\n");
  scanf("%d", &n);
  int v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  particao(n, v);
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
