#include <stdio.h>
#include <stdlib.h>

int main (){
    int *mochila = (int *) malloc(3 * sizeof(int));
    for(int i = 0; i < 3; i++){
        printf("digite o valor do %d° item: ", (i + 1));
        scanf("%d", (mochila + i));
    }
    printf("\n");
    for (int i = 0; i < 3; i++){
        printf("%d° item: %d\n", (i + 1), *(mochila + i));
    }
    mochila = realloc(mochila, 6 * sizeof(int));
    printf("o herói acabou de encontrar um item de expansão na sua mochila!\n");
    printf("digite os valores dos novos 3 itens do herói:\n");
    for (int i = 3; i < 6; i++){
        printf("%d° item: ", (i + 1));
        scanf("%d", (mochila + i));
    }
    printf("inventário atualizado!:\n");
    for (int i = 0; i < 6; i++){
        printf("%d\n", *(mochila + i));
    }
    free(mochila);\
    return 0;
}
