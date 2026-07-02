#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} jogador;

struct No{
    jogador dado;
    struct No* prox;
};

typedef struct No no;

typedef struct{
    no * inicio;
    no * fim;
} fila;

void menu(){
    printf("========== escolha uma opção ==========\n");
    printf("1 - inserir\n");
    printf("2 - mostrar fila\n");
    printf("3 - remover jogador / iniciar partida\n");
    printf("4 - verificar se a fila está vazia\n");
    printf("5 - ver quem é o próximo da fila\n");
    printf("6 - salvar fila em arquivo.\n");
    printf("7 - sair\n");
    printf("=======================================\n");
}

void inserir_fila(fila *f, jogador j){
    no * novo = malloc(sizeof(no));
    novo->dado = j;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void ler(jogador *j){
    printf("digite o id e o nome do seu jogador:\n");
    scanf("%d %s", &j->id, j->nome);
}

void mostrar(fila *f){
    no * pi;
    if (f->inicio == NULL) {
        printf("a fila de matchmaking está vazia.\n");
        return;
    }
    for (pi = f->inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
}

jogador remover(fila *f){
    jogador removido;
    removido.id = -1;
    if (f->inicio == NULL) {
        printf("a fila já está vazia.\n");
        return removido;
    }
    no *pi = f->inicio;
    removido = pi->dado;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(pi);
    return removido;
}

int estaVazia(fila *f){
    if (f->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

jogador verinicio(fila *f){
    jogador novo;
    novo.id = -1;
    if (estaVazia(f)) {
        return novo;
    }
    novo = f->inicio->dado;
    return novo;
}

void salvarFila(fila *f, const char *nomeArquivo){
    no * pi;
    FILE *file = fopen(nomeArquivo, "wb");
    if (file == NULL) {
        printf("erro ao abrir o arquivo.\n");
        return;
    }
    for (pi = f->inicio; pi != NULL; pi = pi->prox) {
        fwrite(&pi->dado, sizeof(jogador), 1, file);
    }
    fclose(file);
}

 void carregarFila(fila *f, const char *nomeArquivo){
     f->inicio = NULL;
     f->fim = NULL;
     FILE *file = fopen(nomeArquivo, "rb");
     if (file == NULL) {
         printf("o arquivo não existe.\n");
         return;
     }
     jogador j;
     while (fread(&j, sizeof(jogador), 1, file)) {
         inserir_fila(f, j);
     }
     fclose(file);
 }

int main(){
    fila f;
    f.inicio = NULL;
    f.fim = NULL;
    carregarFila(&f, "matchmaking_queue.bin");
    int op;
    do{
        menu();
        scanf("%d", &op);
        if(op == 1){
            jogador j;
            ler(&j);
            inserir_fila(&f, j);
        }
        if(op == 2){
            mostrar(&f);
        }
        if(op == 3){
            jogador j = remover(&f);
            if(j.id != -1){
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n",
                j.nome, j.id);
            }
        }
        if (op == 4) {
            if (estaVazia(&f)) {
                printf("sim, a fila está vazia.\n");
            } else {
                printf("não, a fila contem jogadores.\n");
            }
        }
        if (op == 5) {
            jogador j = verinicio(&f);
            if (j.id == -1) {
                printf("não há players na fila\n");
            } else {
                printf("o proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nome, j.id);
            }
        }
        if (op == 6) {
            salvarFila(&f, "matchmaking_queue.bin");
        }
    }while(op != 7);
    return 0;
}