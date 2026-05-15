#include <stdio.h>

int main (){
    int n;
    int produto = 0;
    printf("determine o tamanho dos vetores: \n");
    scanf("%d", &n);
    int v[n], v2[n];
    for (int i = 0; i<n; i++){
        printf("digite os valores do vetor A: \n");
        scanf("%d", &v[i]);
    }
    for (int j=0; j<n; j++){
        printf("digite os valores do vetor B: \n");
        scanf("%d", &v2[j]);
    }
    for (int i=0; i<n; i++){
       produto += v[i] * v2[i];
    }
    if (produto==0){
         printf("os vetores são ortogonais: %d", produto);
    }
    else {
        printf("os vetores não são ortogonais: %d", produto);
    }
    return 0;
}
