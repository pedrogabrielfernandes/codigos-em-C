#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 3

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];
int total_turmas = 0;

Turma* cria_turma(char id){
    Turma* t = (Turma*) malloc(sizeof(Turma));
    t->id = id;
    t->vagas = MAX_VAGAS;

    for(int i = 0; i < MAX_VAGAS; i++){
        t->alunos[i] = NULL;
    }

    return t;
}

Turma* procura_turma(Turma** turmas, int n, char id){
    for(int i = 0; i < n; i++){
        if(turmas[i]->id == id){
            return turmas[i];
        }
    }
    return NULL;
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    if(turma->vagas == 0){
        printf("Turma cheia!\n");
        return;
    }

    for(int i = 0; i < MAX_VAGAS; i++){
        if(turma->alunos[i] == NULL){
            Aluno* a = (Aluno*) malloc(sizeof(Aluno));

            a->mat = mat;
            strcpy(a->nome, nome);

            for(int j = 0; j < 3; j++){
                a->notas[j] = 0;
            }

            a->media = 0;

            turma->alunos[i] = a;
            turma->vagas--;

            printf("Aluno matriculado com sucesso!\n");
            return;
        }
    }
}

void lanca_notas(Turma* turma){
    for(int i = 0; i < MAX_VAGAS; i++){
        if(turma->alunos[i] != NULL){
            Aluno* a = turma->alunos[i];

            printf("Matricula: %d Aluno: %s\n", a->mat, a->nome);

            float soma = 0;

            for(int j = 0; j < 3; j++){
                printf("Digite a nota %d: ", j+1);
                scanf("%f", &a->notas[j]);
                soma += a->notas[j];
            }

            a->media = soma / 3;
        }
    }
}

void imprime_alunos(Turma* turma){
    for(int i = 0; i < MAX_VAGAS; i++){
        if(turma->alunos[i] != NULL){
            Aluno* a = turma->alunos[i];

            printf("Matricula: %d\n", a->mat);
            printf("Nome: %s\n", a->nome);
            printf("Media: %.1f\n\n", a->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n){
    for(int i = 0; i < n; i++){
        printf("Turma %c - %d vagas disponiveis\n",
               turmas[i]->id,
               turmas[i]->vagas);
    }
}

int main(){
    int opcao;

    do {
        printf("\nMENU:\n");
        printf("1 - Criar turma\n");
        printf("2 - Listar turmas\n");
        printf("3 - Matricular aluno\n");
        printf("4 - Lancar notas\n");
        printf("5 - Listar alunos\n");
        printf("6 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            char id;
            printf("Digite um id: ");
            scanf(" %c", &id);

            turmas[total_turmas] = cria_turma(id);
            total_turmas++;

            printf("Turma %c criada com sucesso!\n", id);
        }

        else if(opcao == 2){
            imprime_turmas(turmas, total_turmas);
        }

        else if(opcao == 3){
            char id;
            int mat;
            char nome[81];

            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            Turma* t = procura_turma(turmas, total_turmas, id);

            if(t == NULL){
                printf("Turma inexistente!\n");
            } else {
                printf("Digite a matricula: ");
                scanf("%d", &mat);

                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);

                matricula_aluno(t, mat, nome);
            }
        }

        else if(opcao == 4){
            char id;
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            Turma* t = procura_turma(turmas, total_turmas, id);

            if(t == NULL){
                printf("Turma inexistente!\n");
            } else {
                lanca_notas(t);
            }
        }

        else if(opcao == 5){
            char id;
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            Turma* t = procura_turma(turmas, total_turmas, id);

            if(t == NULL){
                printf("Turma inexistente!\n");
            } else {
                imprime_alunos(t);
            }
        }

    } while(opcao != 6);

    printf("Obrigado por usar este programa!\n");

    return 0;
}
