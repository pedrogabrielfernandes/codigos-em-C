#include <stdio.h>

typedef struct{
    char nome [50];
    int valor_pontos;
}ItemColetavel;

int main (){
    ItemColetavel inventario[3];
    printf("digite o nome e o valor do item (em ordem):\n");
    for (int i = 0; i < 3; i++){
        scanf(" %[^\n]", inventario[i].nome);
        scanf("%d", &inventario[i].valor_pontos);
    }
    ItemColetavel n = inventario[0];
    for (int i = 1; i < 3; i++){
        if (inventario[i].valor_pontos > n.valor_pontos){
            n = inventario[i];
        }
    }
    printf("o item mais valioso coletado foi %s\n", n.nome);
    return 0;
}
