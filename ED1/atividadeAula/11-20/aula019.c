#include <stdio.h>
#include <stdlib.h>

int main (){
    float *ponteiro_altura_salto_duplo = NULL;
    printf("o jogador não possui salto duplo.\n");
    ponteiro_altura_salto_duplo = malloc(sizeof(float));
    if (ponteiro_altura_salto_duplo == NULL){
        return 0;
    }
    *ponteiro_altura_salto_duplo = 15.5;
    printf("pena dourada coletada! altura do salto duplo: %.2f\n", *ponteiro_altura_salto_duplo);
    free(ponteiro_altura_salto_duplo);
    //essa linhha seria para liberar a memoria quando o powerup não for mais necessário.
    return 0;
}
