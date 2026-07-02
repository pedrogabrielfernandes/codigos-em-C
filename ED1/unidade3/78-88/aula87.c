#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
} jogador;

struct no{
    jogador dado;
    struct no *prox;
};

typedef struct{
    struct no *inicio;
} lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1 - adcionar jogador no fim da fila\n");
    printf("2 - iniciar partida\n");
    printf("3- mostrar fila de espera\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(jogador *h){
    printf("Digite o ID e o nome do jogador ou guarda costas:\n");
    scanf("%d %s", &h->id, h->nome);
}

void imprimir(lista l){
    struct no *pi;
    for(pi = l.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
}

void inserir_fim(lista *l, jogador dado){
    struct no *novo = (struct no *) malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
    }
    else{
        struct no *pi;
        for(pi = l->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void excluir_inicio(lista *l){
    if (l == NULL) {
        printf("não há jogadores para se eliminar");
    }
    else {
        struct no* pi = l->inicio;
        l->inicio = pi->prox;
        free(pi);
    }
}

int main(){
    lista l;
    l.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4) {
        if (op == 1) {
            jogador j;
            ler(&j);
            inserir_fim(&l, j);
        }
        if (op == 2) {
            excluir_inicio(&l);
        }
        if (op == 3) {
            imprimir(l);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}