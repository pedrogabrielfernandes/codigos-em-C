#include <stdio.h>

typedef struct{
    char nome [50];
    int vida;
    int ataque;
}campeao;

int main (){
    FILE *file = fopen("./squad.dat", "rb");
    campeao v[3];
    fread(v, sizeof(campeao), 3, file);
    fclose(file);
    int maior_vida = v[0].vida;
    int indice = 0;
    for (int i = 0; i < 3; i++) {
        if (v[i].vida > maior_vida) {
            maior_vida = v[i].vida;
            indice = i;
        }
    }
    printf("%s: tanque do esquadrão\n", v[indice].nome);
    return 0;
}
