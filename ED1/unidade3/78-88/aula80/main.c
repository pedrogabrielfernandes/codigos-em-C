#include <stdio.h>
#include "personagem.h"

int main (){
    int n;
    printf("quantos membros tem na party?\n");
    scanf("%d", &n);
    Personagem *v;
    v = cria_party(n);
    registra_membros(v, n);
    exibe_relatorio(v, n);
    libera_party(v);
}