#include <stdio.h>

typedef struct{
    char nome [50];
    int nivel;
    float vida;
    float mana;
}personagem;

void menu(){
    printf("========Registrar Novo Personagem========\n");
    printf("1 - Resgistrar Novo Personagem\n");
    printf("2 - Sair\n");
    printf("=========================================\n");
}

int main(){
    int n = 0;
    FILE *p = fopen("./savegame.sav.b", "wb");
    menu();
    scanf("%d", &n);
    while (n != 2) {
        if (n == 1) {
            personagem player;
            printf("digite os dados do seu personagem:\n");
            scanf("%s %d %f %f", player.nome, &player.nivel, &player.vida, &player.mana);
            fwrite(&player, sizeof(personagem), 1, p);
        }
        menu();
        scanf("%d", &n);
    }
    fclose(p);
    return 0;
}
