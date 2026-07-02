#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
} heroi;

struct no{
    heroi dado;
    struct no *prox;
};

typedef struct{
    struct no *inicio;
} lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1 - adcionar heroi no final da formação\n");
    printf("2 - adicionar guarda costas (inserir antes)\n");
    printf("3- mostrar formação\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(heroi *h){
    printf("Digite o ID e o nome do heroi ou guarda costas:\n");
    scanf("%d %s", &h->id, h->nome);
}

void imprimir(lista l){
    struct no *pi;
    for(pi = l.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
}

void inserir_fim(lista *l, heroi dado){
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

struct no* inserir_antes(lista *l, heroi dado, int id){
    if (l->inicio == NULL) {
        return NULL;
    }
    else if (l->inicio->dado.id == id) {
        struct no* novo = (struct no*) malloc(sizeof(struct no));
        novo->dado = dado;
        novo->prox = l->inicio;
        l->inicio = novo;
        return novo;
    }
    else {
        struct no* pi;
        for (pi = l->inicio; pi->prox != NULL && pi->prox->dado.id != id; pi = pi->prox);
        if (pi->prox == NULL) {
            return NULL;
        }
        else {
            struct no* novo = (struct no*) malloc(sizeof(struct no));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return novo;
        }
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
            heroi h;
            ler(&h);
            inserir_fim(&l, h);
        }
        if (op == 2) {
            printf("informe o id para posicionar o guarda costas antes:\n");
            int id;
            scanf("%d", &id);
            heroi h;
            ler(&h);
            struct no* pi = inserir_antes(&l, h, id);
            if (pi == NULL) {
                printf("não foi possível adicionar guarda costas!\n");
            }
        }
        if (op == 3) {
            imprimir(l);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}