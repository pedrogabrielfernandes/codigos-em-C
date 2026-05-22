#include <stdio.h>

int main (){
    FILE *entrada = fopen("./entrada_q2.txt", "r");
    int v[10];
    int i = 0;
    while (fscanf(entrada, "%d", &v[i]) != EOF) {
        i++;
    }
    FILE *saida = fopen("./saida_q2.txt", "w");
    int menor = v[0];
    int maior = v[0];
    float media = 0;
    for (int i = 0; i < 10; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
        if (v[i] > maior) {
            maior = v[i];
        }
        media += v[i];
    }
    media = media / 10;
    fprintf(saida, "menor elemento: %d\n", menor);
    fprintf(saida, "maior elemento: %d\n", maior);
    fprintf(saida, "Media dos elementos: %f\n", media);
    fclose(entrada);
    fclose(saida);
    return 0;
}
