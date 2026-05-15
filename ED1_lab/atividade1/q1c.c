#include <stdio.h>
#include <math.h>

int main (){
    float v1[2];
    float v2[2];
    float distancia;
    for (int i = 0; i<2; i++){
        printf("digite as cordenadas de P: ");
        scanf("%f", &v1[i]);
    }
    for (int j = 0; j<2; j++){
        printf("digite as cordenadas de Q: ");
        scanf("%f", &v2[j]);
    }
    distancia = sqrt(pow(v2[0]-v1[0], 2)+pow(v2[1]-v1[1], 2));
    printf("distancia: %.2f\n", distancia);
}
