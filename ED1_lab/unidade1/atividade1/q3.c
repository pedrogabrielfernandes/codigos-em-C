#include <stdio.h>

int main (){
    int matriz[2][2];
    int determinante;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            printf("digite os números da matriz: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    determinante = (matriz[0][0]*matriz[1][1])-(matriz[0][1]*matriz[1][0]);
    printf("determinante: %d", determinante);
    return 0;
}
