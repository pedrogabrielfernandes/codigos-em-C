#include <stdio.h>

void bolha_otimizada(int v[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    int trocou = 0;
    for (j = n - 1; j > i; j--) {
      if (v[j] > v[j - 1]) {
        int temp = v[j];
        v[j] = v[j - 1];
        v[j - 1] = temp;
        trocou = 1;
      }
    }
    if (trocou == 0) {
      return;
    }
  }
}

int main() {
  int n;
  printf("digite a quantidades de jogadores:\n");
  scanf("%d", &n);
  int v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  bolha_otimizada(v, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
