#include <stdio.h>

int somaVetor(int *v, int n){
    int z = 0;
    for (int i = 0; i<n; i++){
        z += *(v + i);
    }
    return z;
}

int main () {
    int numero;
    int *pv;
    int resultado;
    printf("qual o numero do seu vetor? ");
    scanf("%d", &numero);
    int vetor[numero];
    for (int i = 0; i<numero; i++){
        printf("digite o valor do vetor: ");
        scanf("%d", &vetor[i]);
    }
    pv = vetor;
    resultado = somaVetor (pv, numero);
    printf("resultado da soma: %d\n", resultado);

}
