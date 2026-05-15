#include <stdio.h>
#include <stdlib.h>

int main (){
    void *ponteiro_duracao = malloc(sizeof(int));
    *((int *)ponteiro_duracao) = 10;
    printf("Power-up 'super salto' ativado! duração: %d segundos\n", *(int *)ponteiro_duracao);
    *(int *)ponteiro_duracao -=3;
    printf("3 segundos passaram... duração restante: %d\n", *(int *)ponteiro_duracao);
    free(ponteiro_duracao);
    return 0;
}
