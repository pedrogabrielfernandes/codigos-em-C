#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} jogador;

struct No{
    jogador dado;
    struct No* prox;
};

typedef struct No no;

typedef struct{
    no * inicio;
    no * fim;
} fila;

void menu(){
    printf("========== escolha uma opção ==========\n");
    printf("1 - inserir\n");
    printf("2 - mostrar fila\n");
    printf("3 - sair\n");
    printf("=======================================\n");
}

void inserir_fila(fila *f, jogador j){
    no * novo = malloc(sizeof(no));
    novo->dado = j;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void ler(jogador *j){
    printf("digite o id e o nome do seu jogador:\n");
    scanf("%d %s", &j->id, j->nome);
}

void mostrar(fila *f){
    no * pi;
    if (f->inicio == NULL) {
        printf("a fila de matchmaking está vazia.\n");
        return;
    }
    for (pi = f->inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
}

int main(){
    fila f;
    f.inicio = NULL;
    f.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3) {
        if (op == 1) {
            jogador j;
            ler(&j);
            inserir_fila(&f, j);
        }
        if (op == 2) {
            mostrar(&f);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}