#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char nome[50];
    int matricula;
    float nota;
}estudante;

//30 minutos
void cad_aluno(estudante *e){
    FILE *arquivo = fopen("./dados.dat", "wb");
    printf("digite os dados dos 3 alunos:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%s %d %f", (e+i)->nome, &(e+i)->matricula, &(e+i)->nota);
    }
        fwrite(e, sizeof(estudante), 3, arquivo);
        fclose(arquivo);
}

//20 minutos
void imprimir(){
    FILE *arquivo = fopen("./dados.dat", "rb");
    estudante imprime;
    while (fread(&imprime, sizeof(estudante), 1, arquivo)) {
        printf("matricula: %d\tnome: %s\tnota:%.2f\n", imprime.matricula, imprime.nome, imprime.nota);
    }
    fclose(arquivo);
}

//10 minutos
void contador(){
    FILE *arquivo = fopen("./dados.dat", "rb");
    estudante cont;
    int contador = 0;
    while (fread(&cont, sizeof(estudante), 1, arquivo) == 1) {
        contador ++;
    }
    printf("total de registros: %d\n", contador);
    fclose(arquivo);
}

//8 minutos
void buscar(){
    FILE *arquivo = fopen("./dados.dat", "rb");
    estudante busca;
    int n = 0;
    printf("escreva a matricula que quer buscar:\n");
    scanf("%d", &n);
    while (fread(&busca, sizeof(estudante), 1, arquivo)) {
        if (n == busca.matricula) {
            printf("matricula: %d\tnome: %s\tnota: %f\n", busca.matricula, busca.nome, busca.nota);
        }
    }
    fclose(arquivo);
}
//12 minutos
void media(){
    FILE *arquivo = fopen("./dados.dat", "rb");
    estudante atualizar_media;
    float media = 0;
    while (fread(&atualizar_media, sizeof(estudante), 1, arquivo)) {
        media += atualizar_media.nota;
    }
    media /= 3;
    printf("a media geral das notas é: %.2f", media);
    fclose(arquivo);
}
//4 minutos
void atualizar_nota(){
    FILE *arquivo = fopen("./dados.dat", "rb+");
    estudante atualiza;
    int mat = 0;
    printf("digite o nome da matrícula para atualizar a nota:\n");
    scanf("%d", &mat);
    while (fread(&atualiza, sizeof(estudante), 1, arquivo)) {
        if (mat == atualiza.matricula) {
            printf("atualize a nota do aluno %s:\n", atualiza.nome);
            scanf("%f", &atualiza.nota);
            fseek(arquivo, -sizeof(estudante), SEEK_CUR);
            fwrite(&atualiza, sizeof(estudante), 1, arquivo);
            break;
        }
    }
    fclose(arquivo);
}

int main (){
    estudante *e;
    e = malloc(3 * sizeof(estudante));
    cad_aluno(e);
    imprimir();
    contador();
    buscar();
    atualizar_nota();
    media();
    free(e);
    return 0;
}
