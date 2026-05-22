#include <stdio.h>
#include <math.h>

int main (){
    float cordenada_px, cordenada_py, cordenada_qx, cordenada_qy, distancia;
    printf("digite as cordenanas de do ponto P (x, y): \n");
    scanf("%f %f", &cordenada_px, &cordenada_py);
    printf("digite as cordenadas do ponto Q (x, y): \n");
    scanf("%f %f", &cordenada_qx, &cordenada_qy);
    printf("cordenada P: %f, %f\ncordenada Q: %f, %f\n", cordenada_px, cordenada_py, cordenada_qx, cordenada_qy);
    distancia = sqrt(pow(cordenada_qx-cordenada_px, 2)+pow(cordenada_qy-cordenada_py, 2));
    printf("distancia: %.2f\n", distancia);

    return 0;
}
