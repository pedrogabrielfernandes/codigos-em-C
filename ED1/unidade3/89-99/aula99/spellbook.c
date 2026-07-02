#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

Spellbook* create_spellbook(){
    Spellbook *book=(Spellbook*)malloc(sizeof(Spellbook));
    book->inicio=NULL;
    return book;
}

void add_spell(Spellbook* book,int id,const char* name,int mana_cost){
    No *novo=(No*)malloc(sizeof(No));
    novo->dado.id=id;
    strcpy(novo->dado.name,name);
    novo->dado.mana_cost=mana_cost;
    novo->prox=NULL;
    if(book->inicio==NULL){
        book->inicio=novo;
    }
    else{
        No *aux;
        for(aux=book->inicio;aux->prox!=NULL;aux=aux->prox);
        aux->prox=novo;
    }
}

void display_spellbook(Spellbook* book){
    No *aux;
    for(aux=book->inicio;aux!=NULL;aux=aux->prox){
        printf("ID: %d, Feitico: %s, Custo de Mana: %d\n",
        aux->dado.id,
        aux->dado.name,
        aux->dado.mana_cost);
    }
}

void destroy_spellbook(Spellbook* book){
    No *aux;
    while(book->inicio!=NULL){
        aux=book->inicio;
        book->inicio=book->inicio->prox;
        free(aux);
    }
    free(book);
}