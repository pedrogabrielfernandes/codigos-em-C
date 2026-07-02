#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[100];
}Monstro;

struct no{
    struct no *prox;
    Monstro dado;
};

typedef struct{
    struct no *inicio;
}Lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1- adicionar monstro\n");
    printf("2- ordenar bestiario\n");
    printf("3- mostrar bestiario\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(Monstro *m){
    printf("Digite o nivel de ameaca: ");
    scanf("%d",&m->id);
    printf("Digite o nome do monstro: ");
    scanf("%s",m->nome);
}

void adicionarMonstro(Lista *lista,Monstro dado){
    struct no *novo=(struct no*)malloc(sizeof(struct no));
    novo->dado=dado;
    novo->prox=NULL;
    if(lista->inicio==NULL){
        lista->inicio=novo;
    }
    else{
        struct no *aux;
        for(aux=lista->inicio;aux->prox!=NULL;aux=aux->prox);
        aux->prox=novo;
    }
}

void mostrarBestiario(Lista lista){
    struct no *aux;
    for(aux=lista.inicio;aux!=NULL;aux=aux->prox){
        printf("ID: %d Nome: %s\n",aux->dado.id,aux->dado.nome);
    }
}

void ordenarBestiario(Lista *lista){
    struct no *i;
    struct no *j;
    Monstro aux;
    for(i=lista->inicio;i!=NULL;i=i->prox){
        for(j=i->prox;j!=NULL;j=j->prox){
            if(i->dado.id>j->dado.id){
                aux=i->dado;
                i->dado=j->dado;
                j->dado=aux;
            }
        }
    }
    printf("Bestiario ordenado!\n");
}

int main(){
    Lista lista;
    lista.inicio=NULL;
    int op;
    menu();
    scanf("%d",&op);
    while(op!=4){
        if(op==1){
            Monstro m;
            ler(&m);
            adicionarMonstro(&lista,m);
        }
        if(op==2){
            ordenarBestiario(&lista);
        }
        if(op==3){
            mostrarBestiario(lista);
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}