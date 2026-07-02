#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ward {
    int id;
    char nome[100];
} Ward;

typedef struct No {
    Ward ward;
    struct No *prox;
} No;

typedef struct Lista {
    No *inicio;
} Lista;

void adicionar_ward(Lista *lista, Ward ward) {
    No *novo = malloc(sizeof(No));
    novo->ward = ward;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    }
    else {
        No *aux = lista->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void deletar_apos(Lista *lista, int id) {
    if (lista->inicio == NULL) {
        printf("A lista de wards está vazia!\n");
        return;
    }
    No *aux = lista->inicio;
    while (aux != NULL && aux->ward.id != id) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Ward de referencia nao encontrado.\n");
        return;
    }
    if (aux->prox == NULL) {
        printf("Esse ward é o último da lista. Não existe ward após ele.\n");
        return;
    }
    No *remover = aux->prox;
    aux->prox = remover->prox;
    free(remover);
    printf("Ward Shatter realizado!\n");
}

void mostrar_wards(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Nao existem wards ativos.\n");
        return;
    }
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->ward.id, aux->ward.nome);
        aux = aux->prox;
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar Ward\n");
        printf("2. Lancar Ward Shatter\n");
        printf("3. Mostrar Wards Ativos\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Ward w;
            printf("ID: ");
            scanf("%d", &w.id);
            printf("Nome: ");
            scanf("%s", w.nome);
            adicionar_ward(&lista, w);
        }
        else if (opcao == 2) {
            int id;
            printf("ID do ward de referencia: ");
            scanf("%d", &id);
            deletar_apos(&lista, id);
        }
        else if (opcao == 3) {
            mostrar_wards(&lista);
        }
    } while (opcao != 4);
    return 0;
}