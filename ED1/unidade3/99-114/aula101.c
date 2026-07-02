#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int custo_mana;
} feitico;

struct No{
    feitico dado;
    struct No* prox;
};

typedef struct No no;

typedef struct{
    no *topo;
} Pilha;

void push(Pilha *p, feitico dado){
    no * novo = malloc(sizeof(no));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

void ler(feitico *dado){
    printf("digite o nome e o custo de mana do seu feitiço:\n");
    scanf("%s %d", dado->nome, &dado->custo_mana);
}

void menu(){
    printf("============Escolha uma Opção============\n");
    printf("1- Adcionar um novo feitiço a pilha\n");
    printf("2- mostrar pilha de comandos\n");
    printf("3- sair\n");
    printf("=========================================\n");
}

void mostrar(Pilha p){
    no *pi = p.topo;
    if (pi == NULL) {
        printf("a lista está vazia!\n");
        return;
    }
    for (pi = p.topo; pi != NULL; pi = pi->prox) {
        printf("%s, custo: %d\n", pi->dado.nome, pi->dado.custo_mana);
    }
}

int main (){
    Pilha p;
    p.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3) {
        if (op == 1) {
            feitico dado;
            ler(&dado);
            push(&p, dado);
        }
        if (op == 2) {
            mostrar(p);
        }
    menu();
    scanf("%d", &op);
    }
    return 0;
}