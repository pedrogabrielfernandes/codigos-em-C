#include <stdio.h>
#include <string.h>

int main (){
    char inventario [5][20];
    printf("digite o nome dos 5 itens que estão no seu inventário: \n");
    for (int i = 0; i<5; i++){
        scanf("%s", inventario[i]);
    }
    char item [20];
    int x = 1;
    printf("digite o nome do item necessário para abrir a porta: ");
    scanf("%s", item);
    for (int i = 0; i<5; i++){
        if (strcmp(inventario[i], item) == 0){
            printf("a porta se abre!\n");
            x = 0;
            break;
        }
    }
    if (x == 1){
        printf("você não tem o item necessário!\n");
    }
    return 0;
}
