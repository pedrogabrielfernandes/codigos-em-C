#include <stdio.h>

int maior (int *a, int *b){
    if (*a>*b){
     printf("valor de A é o maior valor: %d\n", *a);
     return *a;
    }
    else{
        printf("valor de B é o maior valor: %d\n", *b);
        return *b;
    }
}

int main (){
    int a, b;
    printf("digite os valores para fazer as comparações:\n");
    scanf("%d %d", &a, &b);
    maior (&a, &b);
    return 0;
}
