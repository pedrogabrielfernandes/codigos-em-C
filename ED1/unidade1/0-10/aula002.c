#include <stdio.h>

int main (){
    int tesouro_local = 0;
    int *plataforma_secreta;
    plataforma_secreta = &tesouro_local;
    printf("o tesouro ainda não apareceu. valor: %d\n", *plataforma_secreta);
    *plataforma_secreta = 1;
    printf("o personagem acessou a plataforma secreta! o tesouro apareceu! valor %d\n", *plataforma_secreta);
    return 0;
}
