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
    printf("=====Escolha uma Opção=====\n");
    printf("1- Adcionar um novo feitiço a pilha\n");
    printf("2- sair\n");
    printf("==========================\n");
}

int main (){
    Pilha p;
    p.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2) {
        if (op == 1) {
            feitico dado;
            ler(&dado);
            push(&p, dado);
        }
    menu();
    scanf("%d", &op);
    }
    return 0;
}