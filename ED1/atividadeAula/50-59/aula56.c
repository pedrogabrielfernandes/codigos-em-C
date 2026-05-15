#include <stdio.h>

int soma(int n) {
  if (n == 1) {
    return 1;
  }
  return n + soma(n - 1);
}

int main() {
  int n;
  printf("qual o nível do mago?\n");
  scanf("%d", &n);
  int dano = soma(n);
  printf("dano total: %d\n", dano);
  return 0;
}
