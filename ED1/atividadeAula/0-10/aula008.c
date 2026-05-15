#include <stdio.h>

int main (){
    int v[] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
    int *ponteiro_jogador;
    int moedas_coletadas = 0;
    ponteiro_jogador = v;
    for (int i = 0; i<11; i++){
        if (*(ponteiro_jogador + i) == 1){
            moedas_coletadas += 1;
        }
    }
    printf("moedas coletadas: %d\n", moedas_coletadas);
    return 0;
}
