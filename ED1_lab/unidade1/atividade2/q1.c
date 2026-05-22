#include <stdio.h>

int main (){
    int x = 10;
    int *p;
    p = &x;
    printf("valor de x: %d\n", x);
    printf("endereço de x: %p\n", &x);
    printf("o valor armazenado em p: %p\n", p);
    printf("valor apontado por p: %d\n", *p);
    return 0;
}
