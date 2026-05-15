#include <stdio.h>

int main() {
  int n;
  printf("n:\n");
  scanf("%d", &n);
  int v[n];
  printf("preencha o vetor:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i < n; i++) {
    int imenor = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[imenor]) {
        imenor = j;
      }
    }
    int temp = v[i];
    v[i] = v[imenor];
    v[imenor] = temp;
  }
  printf("lista ordenada:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
