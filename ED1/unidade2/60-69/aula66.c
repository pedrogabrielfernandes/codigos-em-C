#include <stdio.h>

int main() {
  int n;
  printf("digite a quantidade de jogadores:\n");
  scanf("%d", &n);
  int v[n];
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = n - 1; j >= 0; j--) {
      if (v[j] > v[j - 1]) {
        int temp = v[j];
        v[j] = v[j - 1];
        v[j - 1] = temp;
      }
    }
  }
  printf("imprimindo o vetor:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
