#include <stdio.h>

int main (){
    int x = 10;
    int *p;
    int *pp;
    p = &x;
    pp = p;
    printf("x: %d\nponteiro de x: %d\nponteiro de ponteiro de x: %d\n", x, *p, *pp);
    return 0;
}
