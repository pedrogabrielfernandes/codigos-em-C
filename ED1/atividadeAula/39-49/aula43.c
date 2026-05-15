#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome [50];
    int vida;
    int ataque;
}inimigo;

int main(){
    FILE *file = fopen("./aula43.txt", "r");
    if (file == NULL) {
        printf("erro ao achar ao arquivo!");
        exit(1);
    }
    inimigo ini;
    inimigo ini_maior;
    int maior = 0;

    while (fscanf(file, "%s %d %d", ini.nome, &ini.vida, &ini.ataque) != EOF) {
        if (ini.ataque >= maior) {
            maior = ini.ataque;
            strcpy(ini_maior.nome, ini.nome);
            ini_maior.vida = ini.vida;
            ini_maior.ataque = ini.ataque;
        }
    }
   printf("Maior Ameaça: %s, Vida: %d, Ataque: %d\n", ini_maior.nome, ini_maior.vida, ini_maior.ataque);
   fclose(file);
   return 0;
}
