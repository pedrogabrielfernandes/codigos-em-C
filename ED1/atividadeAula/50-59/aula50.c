#include <stdio.h>

typedef struct{
    char nome [50];
    int hp;
}inimigo;

int main (){
    int n = 0;
    printf("quantos inimigos você quer cadastrar?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        inimigo ini;
        printf("digite as informações do %dº inimigo:\n", (i+1));
        scanf("%s %d", ini.nome, &ini.hp);
        printf("inimigo: %s, HP: %d\n", ini.nome, ini.hp);
    }
    return 0;
}
