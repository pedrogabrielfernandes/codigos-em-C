#include <stdio.h>
#include <stdlib.h>

int main (){
    int *vida_inimigo = malloc(sizeof(int));
    if (vida_inimigo == NULL){
        printf("erro ao alocar a memória!");
        return 0;
    }
    *vida_inimigo = 80;
    printf("um novo inimigo apareceu com %d pontos de vida!\n", *vida_inimigo);
    *vida_inimigo -=35;
    printf("o jogador atacou! vida restante do inimigo: %d\n", *vida_inimigo);
    return 0;
}
