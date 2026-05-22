#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int posicao_x;
    int posicao_y;
    int valor;
}moeda;

int main (){
    int quantidade;
    printf("quantas moedas serão cadastradas?\n");
    scanf("%d", &quantidade);
    moeda *m = malloc(quantidade* sizeof(moeda));
    printf("digite as grandezas das moedas:\n");
    for (int i = 0; i < quantidade; i++){
        scanf("%d", &m[i].posicao_x);
        scanf("%d", &m[i].posicao_y);
        scanf("%d", &m[i].valor);
    }
    int total_pontos = 0;
    for (int i = 0; i < quantidade; i++){
        total_pontos += m[i].valor;
    }
    printf("pontuação máxima: %d\n", total_pontos);
    free(m);
    return 0;
}
