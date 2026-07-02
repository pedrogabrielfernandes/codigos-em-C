#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char nome[100];
}Membro;

struct no{
    struct no *prox;
    Membro dado;
};

typedef struct{
    struct no *inicio;
}Lista;

void menu(){
    printf("=========== escolha a opcao =============\n");
    printf("1- adicionar membro\n");
    printf("2- mostrar lista\n");
    printf("3- alterar nome do membro\n");
    printf("4- tamanho da guilda\n");
    printf("5- sair\n");
    printf("=========================================\n");
}

void ler(Membro *m){
    printf("Digite o ID do membro: ");
    scanf("%d",&m->id);
    printf("Digite o nome do membro: ");
    scanf("%s",m->nome);
}

void inserir_fim(Lista *lista,Membro dado){
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
        printf("ID: %d Nome: %s\n",aux->dado.id,aux->dado.nome);
    }
}

struct no *pesquisar(Lista *lista,int id){
    struct no *aux;
    for(aux=lista->inicio;aux!=NULL;aux=aux->prox){
        if(aux->dado.id==id){
            return aux;
        }
    }
    return NULL;
}

void alterar_nome(Lista *lista,int id,char novo_nome[]){
    struct no *membro;
    membro=pesquisar(lista,id);
    if(membro!=NULL){
        strcpy(membro->dado.nome,novo_nome);
        printf("Nome alterado com sucesso!\n");
    }
    else{
        printf("Membro nao encontrado!\n");
    }
}

int tamanho(Lista lista){
    struct no *aux;
    int cont=0;
    for(aux=lista.inicio;aux!=NULL;aux=aux->prox){
        cont++;
    }
    return cont;
}

int main(){
    Lista lista;
    lista.inicio=NULL;
    int op;
    menu();
    scanf("%d",&op);
    while(op!=5){
        if(op==1){
            Membro m;
            ler(&m);
            inserir_fim(&lista,m);
        }
        if(op==2){
            mostrar_lista(lista);
        }
        if(op==3){
            int id;
            char novo_nome[100];
            printf("Digite o ID do membro: ");
            scanf("%d",&id);
            printf("Digite o novo nome: ");
            scanf("%s",novo_nome);
            alterar_nome(&lista,id,novo_nome);
        }
        if(op==4){
            printf("Tamanho atual da guilda: %d mercenarios\n",tamanho(lista));
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}