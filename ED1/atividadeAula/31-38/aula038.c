#include <inttypes.h>
#include <stdio.h>

enum estado_personagem {PARADO, CORRENDO, PULANDO};

int main (){
    enum estado_personagem estado_atual;
    printf("=====estados=====\n");
    printf("    0 - Parado   \n");
    printf("    1 - Correndo \n");
    printf("    2 - Pulando  \n");
    printf("=================\n");
    printf("digite um número para definir o estado do personagem:\n");
    scanf("%d", &estado_atual);
    if (estado_atual == PARADO){
        printf("o personagem está parado.\n");
    }
    else if (estado_atual == CORRENDO) {
        printf("o personagem está correndo!\n");
    }
    else if (estado_atual == PULANDO) {
        printf("o personagem está pulando no ar!\n");
    }
    else {
        printf("estado invalido. (escolha um estado valido.)\n");
    }
    return 0;
}
