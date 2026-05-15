#include <stdio.h>
#include <stdlib.h>

int main (){
    int n_inimigos;
    printf("digite a quantidade de inimigos da onda: \n");
    scanf("%d", &n_inimigos);
    int *ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));
    if(ponteiro_onda == NULL){
        printf("ocorreu algum erro!");
        return 1;
    }
    printf("digite os IDs dos inimigos: \n");
    for (int i = 0; i < n_inimigos; i++) {
        scanf("%d", (ponteiro_onda + i));
    }
    printf("onda de inimigos criada com sucesso! IDs: ");
    for (int i = 0; i < n_inimigos; i++) {
        printf("%d ", *(ponteiro_onda + i));
    }
    printf("\n");
    free(ponteiro_onda);
    return 0;
}
