#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
} mercenario;

struct no{
    struct no *prox;
    mercenario dado;
};

typedef struct {
    struct no *inicio;
}lista;

void menu(){
    printf("=========== escolha a opção =============\n");
    printf("1- contatar mercenario\n");
    printf("2- exibir companhia\n");
    printf("3- declarar falencia\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(mercenario *a){
    printf("digite as informações abaixo:\n");
    scanf("%d %s", &a->id, a->nome);
}

void inserir_fim(lista *l, mercenario dado){
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

void falencia(lista *l){
    struct no *pi;
    while (l->inicio != NULL) {
        pi = l->inicio;
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
            mercenario a;
            ler(&a);
            inserir_fim(&l, a);
        }
        if (op == 2) {
            imprimir(l);
        }
        if (op == 3) {
            falencia(&l);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}