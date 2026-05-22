#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome [50];
    int nivel;
    int highScore;
}PlayerProfile;

int main (){
    FILE *file = fopen("./profiles.dat", "rb");
    if (file == NULL) {
        printf("erro ao abrir o arquivo");
        exit(1);
    }
    PlayerProfile p;
    while (fread(&p, sizeof(PlayerProfile), 1, file)) {
        if (p.highScore > 10000) {
            printf("%s: o Rank é: Mestre Do Jogo\n", p.nome);
        }
        else if (p.highScore > 5000) {
            printf("%s: o Rank é: Veterano\n", p.nome);
        }
        else {
            printf("%s: o Rank é: Aspirante\n", p.nome);
        }
    }
    fclose(file);
    return 0;
}
