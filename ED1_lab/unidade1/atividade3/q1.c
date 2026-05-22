#include <stdio.h>
#include <stdlib.h>

int main (){
    int tamanho_vetor;
    printf("qual o tamanho do seu vetor?\n");
    scanf("%d", &tamanho_vetor);
    int *vetor = malloc(tamanho_vetor * sizeof(int));
    printf("insira os elementos do vetor:\n");
    for (int contador = 0; contador < tamanho_vetor; contador++){
        scanf("%d", (vetor + contador));
    }
    printf("vetor:\n");
    for (int contador = (tamanho_vetor - 1); contador > -1; contador--){
        printf("%d ", *(vetor + contador));
    }
    printf("\n");
    return 0;
}
