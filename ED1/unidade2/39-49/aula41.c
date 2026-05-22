#include <stdio.h>

void menu(){
    printf("======Digite o que quer=====\n");
    printf("1- Resgistrar novo evento\n2- Sair\n");
    printf("============================\n");
}

int main (){
    FILE *file = fopen("./aula41.txt", "a");
    int n = 0;
    menu();
    scanf("%d", &n);
    while (n!=2){
        if (n == 1) {
        char evento[50];
        scanf("%s", evento);
        fprintf(file, "%s\n", evento);
        fflush(file);
        }
        menu();
        scanf("%d", &n);
    }
    printf("programa finalizado.");
    fclose(file);
    return 0;
}
