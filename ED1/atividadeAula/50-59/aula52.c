#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
} unidade;

int main (){
    unidade  *v;
    int n;
    printf("digite a quantidade de unidades que quer armazenar:\n");
    scanf("%d", &n);
    v = malloc(n * sizeof(unidade));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].x, &v[i].y);
    }
    float raio;
    printf("informe o raio da explosão:\n");
    scanf("%f", &raio);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                float distancia = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
                if (distancia <= raio) {
                    cont++;
                }
            }
        }
    }
    printf("quantidade de unidades agrupadas: %d\n", cont);
    free(v);
    return 0;
}
