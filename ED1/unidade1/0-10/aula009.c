#include <stdio.h>

int main () {
    int moedas_coletadas [] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moeda;
    ponteiro_moeda = moedas_coletadas;
    for (int i = 0; i<5; i++){
        pontuacao_total += *ponteiro_moeda;
        ponteiro_moeda ++;
    }
    printf("pontuação total do nível: %d\n", pontuacao_total);
    return 0;
}
