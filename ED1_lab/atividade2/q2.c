#include <stdio.h>

int main (){
    int n = 5;
    printf("valor de n: %d\n", n);
    int *pn;
    pn = &n;
    *pn = 20;
    printf("valor de n alterado: %d\n", n);
    return 0;
}
