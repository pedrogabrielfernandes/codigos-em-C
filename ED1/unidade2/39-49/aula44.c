#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float pontos;
}conquista;

int main (){
    FILE *file = fopen("./aula44.txt", "r+");
    if (file == NULL) {
        printf("erro ao achar o arquivo!");
        exit(1);
    }
    int n = 0;
    conquista c1;
    fscanf(file, "%d", &n);
    float total = 0;
    for (int i = 0; i < n; i++){
        fscanf(file, "%d %f", &c1.id, &c1.pontos);
        total += c1.pontos;
    }
    fseek(file, 0, SEEK_CUR);
    fprintf(file, "\n--- SESSION CONCLUDED ---");
    printf("total de pontos: %.2f\n", total);
    fclose(file);
    return 0;
}
