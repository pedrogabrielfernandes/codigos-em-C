#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[100];
    int nivel;
}Membro;

struct no{
    struct no *prox;
    Membro dado;
};

typedef struct{
    struct no *inicio;
}Lista;

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

void mostrar_guilda(Lista lista){
    struct no *aux;
    for(aux=lista.inicio;aux!=NULL;aux=aux->prox){
        printf("ID: %d Nome: %s Nivel: %d\n",aux->dado.id,aux->dado.nome,aux->dado.nivel);
    }
}

void salvar_guilda_teste(){
    FILE *arquivo;
    Membro m;
    arquivo=fopen("guild_roster.b","wb");
    if(arquivo==NULL){
        printf("Erro ao criar arquivo!\n");
        return;
    }
    m.id=1;
    strcpy(m.nome,"Arthas");
    m.nivel=50;
    fwrite(&m,sizeof(Membro),1,arquivo);
    m.id=2;
    strcpy(m.nome,"Luna");
    m.nivel=35;
    fwrite(&m,sizeof(Membro),1,arquivo);
    m.id=3;
    strcpy(m.nome,"Drake");
    m.nivel=70;
    fwrite(&m,sizeof(Membro),1,arquivo);
    fclose(arquivo);
}

Lista carregar_guilda(){
    Lista lista;
    lista.inicio=NULL;
    FILE *arquivo;
    Membro m;
    arquivo=fopen("guild_roster.b","rb");
    if(arquivo==NULL){
        printf("Erro ao abrir arquivo!\n");
        return lista;
    }
    while(fread(&m,sizeof(Membro),1,arquivo)){
        inserir_fim(&lista,m);
    }
    fclose(arquivo);
    return lista;
}

int main(){
    Lista lista;
    salvar_guilda_teste();
    lista=carregar_guilda();
    mostrar_guilda(lista);
    return 0;
}