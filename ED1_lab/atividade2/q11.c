#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    printf("digite o tamanho do seu vetor:\n");
    scanf("%d", &n);
    int *v;
    v = (int *) malloc(n * sizeof(int));
    printf("preencha o vetor:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", v + i);
    }
    float soma = 0;
    for (int i = 0; i < n; i++){
        soma += *(v + i);
    }
    float media = soma/n;
    printf("a média dos conjuntos dos vetores são: %.2f\n", media);
    free(v);
    return 0;
}
