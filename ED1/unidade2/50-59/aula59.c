#include <stdio.h>

typedef struct {
  int id;
  char nome[50];
  int hp;
  int ataque;
} monstro;

void ler(monstro *v) {
  scanf("%d %s %d %d", &v->id, v->nome, &v->hp, &v->ataque);
}

int busca(monstro *v, int i, int f, int id) {
  int meio = (i + f) / 2;
  if (i > f) {
    return -1;
  }
  if (v[meio].id == id) {
    return meio;
  }
  if (v[meio].id > id) {
    return busca(v, i, meio - 1, id);
  }
  return busca(v, meio + 1, f, id);
}

void menu() {
  printf("======== Escolha uma opção ==========\n");
  printf("0 - sair\n");
  printf("1- pesquisar\n");
  printf("=====================================\n");
}

int main() {
  int n;
  printf("digite um número de monstros a ser catalogados:\n");
  scanf("%d", &n);
  monstro v[n];
  printf("catalogue abaixo os inimigos:\n");
  for (int i = 0; i < n; i++) {
    ler(&v[i]);
  }
  int op;
  menu();
  scanf("%d", &op);
  while (op != 0) {
    if (op == 1) {
      int id = 0;
      printf("qual id você quer buscar?\n");
      scanf("%d", &id);
      int idx = busca(v, 0, n - 1, id);
      if (idx >= 0) {
        printf("Monstro encontrado: %s\nID: %d\nHP: %d\nATK: %d\n", v[idx].nome,
               v[idx].id, v[idx].hp, v[idx].ataque);
      } else {
        printf("jogador não encontrado\n");
      }
    }
    menu();
    scanf("%d", &op);
  }
  return 0;
}
