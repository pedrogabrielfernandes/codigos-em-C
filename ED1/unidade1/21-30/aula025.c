#include <stdio.h>
#include <stdlib.h>

int main (){
    int x;
    printf("digite a quantidade de inimigos:\n");
    scanf("%d", &x);
    int *status_inimigos = (int *) calloc(x, sizeof(int));
    for (int i = 0; i < x; i++){
        status_inimigos[i] = 0;
        printf("inimigo %d: inativo(%d)\n", (i + 1), status_inimigos[i]);
    }
    printf("\n");
    for(int i = 0; i < x; i++){
        status_inimigos[i] = 1;
        printf("inimigo %d: ativo(%d)\n", (i + 1), status_inimigos[i]);
    }
    free(status_inimigos);
    return 0;
}
