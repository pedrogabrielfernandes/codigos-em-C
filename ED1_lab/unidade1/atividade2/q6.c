//#include <inttypes.h>
#include <stdio.h>

int main (){
    int v[] = {1,2,3,4,5};
    int x = 0;
    int *px;
    px = &x;
    printf("valores dos vetores: \n");
    for (*px = 0; *px<5; (*px)++){
        printf("\n%d\n", v[*px]);
    }
    return 0;
    }
