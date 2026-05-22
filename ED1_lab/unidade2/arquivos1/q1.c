#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [100];
    float n1;
    float n2;
    float n3;
    float media;
}estudantes;

int main (){
    FILE *entrada = fopen("./entrada_q1.txt", "r");
    if (entrada == NULL){
        printf("erro ao ler o arquivo!");
        exit(1);
    }
    FILE *saida = fopen("./saida_q1.txt", "w");
    if (saida == NULL) {
        printf("erro ao criar o arquivo!");
        exit(1);
    }
    estudantes v[8];
    int i = 0;
    while (fscanf(entrada, " %[^\t] %f %f %f", v[i].nome, &v[i].n1, &v[i].n2, &v[i].n3) != EOF) {
        v[i].media = (v[i].n1 + v[i].n2 + v[i].n3)/3;
        if (v[i].media >= 7) {
            fprintf(saida, "%s\t%f\tAprovado\n", v[i].nome, v[i].media);
        }
        else {
            fprintf(saida, "%s\t%f\tReprovado\n", v[i].nome, v[i].media);
        }
        i++;
        if (i > 7) {
            break;
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}
