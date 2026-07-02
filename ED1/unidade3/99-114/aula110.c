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
    printf("3 - remover jogador / iniciar partida\n");
    printf("4 - sair\n");
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

jogador remover(fila *f){
    jogador removido;
    removido.id = -1;
    if (f->inicio == NULL) {
        printf("a fila já está vazia.\n");
        return removido;
    }
    no *pi = f->inicio;
    removido = pi->dado;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(pi);
    return removido;
}

int main(){
    fila f;
    f.inicio = NULL;
    f.fim = NULL;
    int op;
    do{
        menu();
        scanf("%d", &op);
        if(op == 1){
            jogador j;
            ler(&j);
            inserir_fila(&f, j);
        }
        if(op == 2){
            mostrar(&f);
        }
        if(op == 3){
            jogador j = remover(&f);
            if(j.id != -1){
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n",
                j.nome, j.id);
            }
        }
    }while(op != 4);
    return 0;
}