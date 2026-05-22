#include <stdio.h>

typedef struct {
  char nome[50];
  int hp;
} monstro;

int main() {
  int n;
  printf("quantos monstros?\n");
  scanf("%d", &n);
  monstro v[n];
  for (int i = 0; i < n; i++) {
    scanf("%s %d", v[i].nome, &v[i].hp);
  }
  monstro menor = v[0];
  for (int i = 0; i < n; i++) {
    if (v[i].hp < menor.hp) {
      menor = v[i];
    }
  }
  printf("Alvo prioritário: %s, HP: %d\n", menor.nome, menor.hp);
  return 0;
}
