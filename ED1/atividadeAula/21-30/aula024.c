#include <stdio.h>
#include <stdlib.h>

int main (){
    int linha, coluna;
    printf("digite o número de linhas e o número de colunas do mapa:\n");
    scanf("%d %d", &linha, &coluna);
    int **mapa = (int **) malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++){
        mapa[i] = (int *) malloc(coluna * sizeof(int));
    }
    printf("digite os valores da sua matriz: (somente 0, 1, 2)\n");
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            scanf("%d", &mapa[i][j]);
        }
    }
    int bloco_tijolo = 0;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if (mapa[i][j] == 1){
                bloco_tijolo ++;
            }
        }
    }
    printf("o mapa possui %d blocos de tijolo.\n", bloco_tijolo);
    for(int i = 0; i < linha; i++){
        free (mapa[i]);
    }
    free (mapa);
    return 0;
}
