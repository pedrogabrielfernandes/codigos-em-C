#include <stdio.h>
#include <stdlib.h>

int main (){
    int *duracao_fumaca = malloc(sizeof(int));
    if (duracao_fumaca == NULL){
        printf("ocorreu um erro!");
        return 0;
    }
    *duracao_fumaca += 5;
    printf("bomba de fumaça ativada! duração: %d segundos\n", *duracao_fumaca);
    free(duracao_fumaca);
    duracao_fumaca = NULL;
    printf("a fumaça se dissipou.\n");
    return 0;
}
