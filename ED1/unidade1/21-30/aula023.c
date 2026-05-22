#include <stdio.h>
#include <stdlib.h>

#define linha 5
#define coluna 10

int main (){
    int *level_map = (int *) malloc( linha * coluna * sizeof(int));
    if (level_map == NULL){
        printf("erro!");
        return 1;
    }
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++) {
            if (i == (linha - 1)){
                *(level_map + (i * coluna) + j) = 1;
            }
            else {
                *(level_map + (i * coluna) + j) = 0;
            }
        }
    }
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%d ", *(level_map + (i * coluna) + j));
        }
        printf("\n");
    }
    free (level_map);
    return 0;
}
