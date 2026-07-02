#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
} aventureiro;

struct no{
    struct no *prox;
    aventureiro dado;
};

typedef struct {
    struct no *inicio;
}lista;

void menu(){
    printf("=========== escolha a opção =============\n");
    printf("1- cadastrar no inicio da lista\n");
    printf("2- cadastrar no fim da lista\n");
    printf("3- ver lista\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(aventureiro *a){
    printf("digite as informações abaixo:\n");
    scanf("%d %s", &a->id, a->nome);
}

void inserir_inicio (lista *l, aventureiro dado){
    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void inserir_fim(lista *l, aventureiro dado){
    struct no *novo = (struct no *) malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;
    if (l->inicio == NULL) {
        l->inicio = novo;
    }
    else {
        struct no *pi;
        for (pi = l->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void imprimir(lista l){
    struct no *pi;
    for (pi = l.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
}

int main (){
    lista l;
    l.inicio =  NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4) {
        if (op == 1) {
            aventureiro a;
            ler(&a);
            inserir_inicio(&l, a);
        }
        if (op == 2) {
            aventureiro a;
            ler(&a);
            inserir_fim(&l, a);
        }
        if (op == 3) {
            imprimir(l);
        }
        menu();
        scanf("%d", &op);
    }
    printf("programa finalizado!\n");
    return 0;
}