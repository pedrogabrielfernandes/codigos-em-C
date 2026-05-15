#include <stdio.h>

int main (){
    int sala1[3] = {10, 20, 5};
    int sala2[2] = {50, 100};
    int sala3[4] = {5, 5, 5, 10};

    int *ponteiro_salas[3];

    ponteiro_salas[0] = sala1;
    ponteiro_salas [1] = sala2;
    ponteiro_salas [2] = sala3;

    //tamanho = sizeof(sala(x)) / sizeof(salax[0]); //achei o tamanho do vetor!
    printf("sala 1: ");
    for (int i = 0; i < sizeof(sala1) / sizeof(sala1[0]); i++){
        printf("%d ", ponteiro_salas[0][i]);
    }
    printf("\nsala 2: ");
    for (int i = 0; i < sizeof(sala2) / sizeof(sala2[0]); i++){
        printf("%d ", ponteiro_salas[1][i]);
    }
    printf("\nsala 3: ");
    for (int i = 0; i < sizeof(sala3) / sizeof(sala3[0]); i++) {
        printf("%d ", ponteiro_salas[2][i]);
    }
    printf("\n");
    return 0;
}
