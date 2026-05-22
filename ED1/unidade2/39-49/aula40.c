#include <stdio.h>

typedef struct{
    char nome [50];
    int pont;
}jogador;

int main (){
    int n = 0;
    printf("quantos jogadores vão ser rigistrados?\n");
    scanf("%d", &n);
    jogador players[n];
    printf("escreva os dados dos %d jogadores:\n", n);
    int maior = players[0].pont;
    int indice = 0;
    for (int i = 0; i<n; i++){
        scanf("%s", players[i].nome);
        scanf("%d", &players[i].pont);
        if (players[i].pont > maior) {
            maior = players[i].pont;
            indice = i;
        }
    }
    FILE *file = fopen("./aula40.txt", "w");
    fprintf(file, "Nome: %s, Pontuação: %d", players[indice].nome, players[indice].pont);
    fclose(file);
    return 0;
}
