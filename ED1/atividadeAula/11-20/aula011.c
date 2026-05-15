#include <stdio.h>

int main (){
    int balas [] = {30, 30};
    int granadas [] = {5, 5};
    int foguetes [] = {2, 2};
    int *inventario [3];
    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;
    printf("inventario inicial:\nbalas: %d \ngranadas: %d\nfoguetes: %d\n", *(inventario[0] + 0), *(inventario[1] + 0), *(inventario[2] + 0));
    for (int i = 0; i < 3; i++){
        *(inventario [i] + 0) -= 1;
    }
    printf("inventario após o uso:\nbalas: %d \ngranadas: %d\nfoguetes: %d\n", *(inventario[0] + 0), *(inventario[1] + 0), *(inventario[2] + 0));
    return 0;
}
