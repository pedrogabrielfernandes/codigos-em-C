#include <stdio.h>
#include <stdlib.h>

int main (){
    int linha, coluna;
    printf("digite a quantidade de linhas e colunas de sua matriz:\n");
    scanf("%d %d", &linha, &coluna);
    int *matriz = (int *) malloc(linha * coluna * sizeof(int));
    printf("insira os valores da matriz abaixo:\n");
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            scanf("%d", (matriz + (i * coluna) + j));
        }
    }
    printf("matriz:\n");
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%d ", *(matriz + (i * coluna) + j));
        }
        printf("\n");
    }
    printf("matriz transposta:\n");
    for (int j = 0; j < coluna; j++){
        for (int i = 0; i < linha; i++){
            printf("%d ", *(matriz + (i * coluna) + j));
        }
        printf("\n");
    }
    free (matriz);
    return 0;
}
