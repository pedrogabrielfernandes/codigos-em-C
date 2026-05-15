#include <stdio.h>

int main (){
    int pontuacao = 0;
    int *ponteiro_pontuacao;
    ponteiro_pontuacao = &pontuacao;
    printf("pontuação inicial: %d\n", *ponteiro_pontuacao);
    for (int i=0; i<3; i++){
        *ponteiro_pontuacao += 10;
    }
    printf ("você coletou 3 moedas! pontuação após coletar moedas: %d\n", *ponteiro_pontuacao);
    return 0;
}
