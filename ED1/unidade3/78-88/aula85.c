#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
} Item;

struct no{
    Item dado;
    struct no *prox;
};

typedef struct{
    struct no *inicio;
} lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1 - inserir item no inicio\n");
    printf("2 - inserir item no fim\n");
    printf("3 - inserir catalisador apos um fragmento\n");
    printf("4 - mostrar inventario\n");
    printf("5 - sair\n");
    printf("=========================================\n");
}

void ler(Item *i){
    printf("Digite o ID e o nome do item:\n");
    scanf("%d %s", &i->id, i->nome);
}

void inserir_inicio(lista *l, Item dado){
    struct no *novo = (struct no *) malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void inserir_fim(lista *l, Item dado){
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

struct no *inserir_apos_fragmento(lista *l, Item dado, int id){
    struct no *pi;
    for(pi = l->inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    if(pi == NULL){
        return pi;
    }
    else{
        struct no *novo = (struct no *) malloc(sizeof(struct no));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

void imprimir(lista l){
    struct no *pi;
    for(pi = l.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
}

int main(){
    lista l;
    l.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);

    while(op != 5){

        if(op == 1){
            Item item;
            ler(&item);
            inserir_inicio(&l, item);
        }
        if(op == 2){
            Item item;
            ler(&item);
            inserir_fim(&l, item);
        }
        if(op == 3){
            Item catalisador;
            int id;

            printf("digite os dados do catalisador:\n");
            ler(&catalisador);

            printf("digite o ID do fragmento:\n");
            scanf("%d", &id);

            if(inserir_apos_fragmento(&l, catalisador, id) == NULL){
                printf("fragmento nao encontrado, insercao cancelada!\n");
            }
            else{
                printf("catalisador inserido com sucesso\n");
            }
        }

        if(op == 4){
            imprimir(l);
        }

        menu();
        scanf("%d", &op);
    }

    printf("programa finalizado!\n");

    return 0;
}
