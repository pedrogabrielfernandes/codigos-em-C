#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
}movimento;

struct no{
    movimento dado;
    struct no *prox;
};

typedef struct {
    struct no *inicio;
}lista;

void inicio(lista *lista, movimento dado){
    struct no * novo = (struct no *) malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void ler(movimento *m){
    scanf("%d %s", &m->id, m->nome);
}

void menu(){
    printf("=======registre os seus movimentos ============\n");
    printf("1 - registrar\n");
    printf("2 - sair\n");
    printf("===============================================\n");
}

int main (){
    lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2) {
        if (op == 1) {
            movimento m;
            ler(&m);
            inicio(&lista, m);
        }
        menu();
        scanf("%d", &op);
    }
    printf("programa finalizado!\n");
    return 0;
}