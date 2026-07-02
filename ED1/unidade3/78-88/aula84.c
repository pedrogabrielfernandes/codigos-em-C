#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char status[100];
  char titulo[100];
} Missao;

struct no {
  struct no *prox;
  Missao dado;
};

typedef struct {
  struct no *inicio;
} lista;

void inserir(lista *l, Missao dado) {
  struct no *novo = (struct no *)malloc(sizeof(struct no));
  novo->dado = dado;
  novo->prox = l->inicio;
  l->inicio = novo;
}

void ler(Missao *a) {
  printf("digite as informações abaixo: (id, titulo e status)\n");
  scanf("%d %s %s", &a->id, a->titulo, a->status);
}

void menu() {
  printf("=========== escolha a opção =============\n");
  printf("1- cadastrar na lista\n");
  printf("2- imprimir lista\n");
  printf("3- pesquisar\n");
  printf("4- sair\n");
  printf("=========================================\n");
}

void imprimir(lista l) {
  struct no *pi;
  for (pi = l.inicio; pi != NULL; pi = pi->prox) {
    printf("id: %d, titulo: %s, status: %s\n", pi->dado.id, pi->dado.titulo,
           pi->dado.status);
  }
}

struct no *pesquisar(lista l, int id) {
  struct no *pi;
  for (pi = l.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox)
    ;
  return pi;
}

int main() {
  lista l;
  l.inicio = NULL;
  int op;
  menu();
  scanf("%d", &op);
  while (op != 4) {
    if (op == 1) {
      Missao a;
      ler(&a);
      inserir(&l, a);
    }
    if (op == 2) {
      imprimir(l);
    }
    if (op == 3) {
      int id;
      printf("digite o id que você deseja pesquisar:\n");
      scanf("%d", &id);
      struct no *r = pesquisar(l, id);
      if (r != NULL) {
        printf("id: %d\n", r->dado.id);
        printf("titulo: %s\n", r->dado.titulo);
        printf("status: %s\n", r->dado.status);
      } else {
        printf("missão não encontrada!\n");
      }
    }
    menu();
    scanf("%d", &op);
  }
  return 0;
}
