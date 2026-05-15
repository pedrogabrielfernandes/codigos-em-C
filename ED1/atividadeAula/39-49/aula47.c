#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char nome[50];
    int vida;
    int ataque;
}unidade;

int main (){
    int n;
    printf("digite o tamanho do esquadrão:\n");
    scanf("%d", &n);
    unidade *v = malloc(n * sizeof(unidade));
    printf("preencha os dados das unidades do esquadrão\n");
    for (int i = 0; i < n; i++){
        scanf("%s %d %d", (v + i)->nome, &(v + i)->vida, &(v + i)->ataque);
    }
    FILE *file = fopen("./squad.dat", "wb");
    fwrite(v, sizeof(unidade), n, file);
    int maior_ataque = v->ataque;
    int indice = 0;
    for (int i = 0; i < n; i++) {
        if ((v + i)->ataque > maior_ataque) {
            maior_ataque = (v + i)->ataque;
            indice = i;
        }
    }
    printf("%s tem o maior ataque!\n", (v + indice)->nome);
    fclose(file);
    free(v);
    return 0;
}
