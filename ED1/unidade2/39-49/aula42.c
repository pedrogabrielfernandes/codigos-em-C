#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int resolucao_x;
    int resolucao_y;
    float volume_som;
}configuracao;

int main (){
    FILE *file = fopen("./aula42.txt", "r");
    if (file == NULL) {
        printf("arquivo aula42.txt nao encontrado!\n");
        exit(1);
    }
    configuracao c1;
    fscanf(file, "%d %d %f", &c1.resolucao_x, &c1.resolucao_y, &c1.volume_som);
    printf("Configuracoes carregadas:\nResolucao: %dx%d\nVolume: %.1f\n", c1.resolucao_x, c1.resolucao_y, c1.volume_som);
    fclose(file);
    return 0;
}
