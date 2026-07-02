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
    printf("3- salvar guilda no arquivo\n");
    printf("4- sair\n");
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

void salvar_guild_arquivo(Lista lista){
    FILE *arquivo;
    struct no *aux;
    arquivo=fopen("guild_roster.bin","wb");
    if(arquivo==NULL){
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    for(aux=lista.inicio;aux!=NULL;aux=aux->prox){
        fwrite(&aux->dado,sizeof(Membro),1,arquivo);
    }
    fclose(arquivo);
    printf("Guilda salva com sucesso!\n");
}

int main(){
    Lista lista;
    lista.inicio=NULL;
    int op;
    menu();
    scanf("%d",&op);
    while(op!=4){
        if(op==1){
            Membro m;
            ler(&m);
            inserir_fim(&lista,m);
        }
        if(op==2){
            mostrar_lista(lista);
        }
        if(op==3){
            salvar_guild_arquivo(lista);
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}