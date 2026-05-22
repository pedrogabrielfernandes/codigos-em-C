#include <stdio.h>

typedef struct{
    char nome[50];
    float hp;
    float atk;
}inimigos;

int main(){
    inimigos ini1;
    inimigos ini2;
    inimigos ini3;
    inimigos v[3] = {ini1, ini2, ini3};
    FILE *file = fopen("./aula39.txt", "r");
    float nivel = 0;
    for (int i = 0; i<3;i++){
    fscanf(file, "%s %f %f", v[i].nome, &v[i].hp, &v[i].atk);
    nivel = v[i].hp + v[i].atk;
    if (nivel >=200){
        printf("%s tem o nível de ameaça de: %.2f\n", v[i].nome, nivel);
    }
    }
    fclose(file);
}
