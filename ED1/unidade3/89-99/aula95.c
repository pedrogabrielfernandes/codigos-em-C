#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char tipo[100];
}Inimigo;

struct no{
    struct no *prox;
    Inimigo dado;
};

typedef struct{
    struct no *inicio;
}Lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1- adicionar inimigo\n");
    printf("2- mostrar inimigos\n");
    printf("3- iniciar nova onda\n");
    printf("4- sair\n");
    printf("=========================================\n");
}

void ler(Inimigo *i){
    printf("Digite o ID do inimigo: ");
    scanf("%d",&i->id);
    printf("Digite o tipo do inimigo: ");
    scanf("%s",i->tipo);
}

void inserir_fim(Lista *lista,Inimigo dado){
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

void mostrar_lista(Lista lista){
    struct no *aux;
    for(aux=lista.inicio;aux!=NULL;aux=aux->prox){
        printf("ID: %d Tipo: %s\n",aux->dado.id,aux->dado.tipo);
    }
}

Lista criar_lista(int n){
    Lista nova;
    nova.inicio=NULL;
    int i;
    for(i=0;i<n;i++){
        Inimigo inimigo;
        ler(&inimigo);
        inserir_fim(&nova,inimigo);
    }
    return nova;
}

int main(){
    Lista lista;
    lista.inicio=NULL;
    int op;
    menu();
    scanf("%d",&op);
    while(op!=4){
        if(op==1){
            Inimigo i;
            ler(&i);
            inserir_fim(&lista,i);
        }
        if(op==2){
            mostrar_lista(lista);
        }
        if(op==3){
            int n;
            printf("Digite a quantidade de inimigos da nova onda: ");
            scanf("%d",&n);
            lista=criar_lista(n);
            printf("Nova onda criada!\n");
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}