#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    printf("digite um número:\n");
    scanf("%d", &n);
    int *matriz = malloc(n * n * sizeof(int));
    if (matriz == NULL){
        printf("erro");
        return 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(matriz + i * n + j) = rand()%101;
        }
    }
    printf("matriz:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matriz + i * n + j));
        }
        printf("\n");
    }
    free (matriz);
    return 0;
}
