#include <stdio.h>

void troca(int *a, int *b){
   int auxiliar = *a;
   *a = *b;
   *b = auxiliar;
   printf("valor de A: %d\nvalor de B: %d\n", *a, *b);
}

int main (){
    int a, b;
    printf("digite os numeros de A e B para serem alterados:\n ");
    scanf("%d %d", &a, &b);
    troca (&a, &b);
    return 0;
}
