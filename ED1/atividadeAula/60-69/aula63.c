#include <stdio.h>

int main() {
  int v[6] = {120, 125, 130, 142, 150};
  int tempo;
  printf("digite o seu novo tempo:\n");
  scanf("%d", &tempo);
  int i;
  if (tempo > v[5 - 1]) {
    for (int i = 0; i < 5; i++) {
      printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
  }
  for (i = 5 - 1; i >= 0 && tempo <= v[i]; i--) {
    v[i + 1] = v[i];
  }
  v[i + 1] = tempo;
  for (int i = 0; i < 5; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
