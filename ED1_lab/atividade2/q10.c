#include <stdio.h>

void inverter (int *v, int n){
int v2[n];
for (int i = 0; i < n; i++){
    *(v2 + i) = *(v + i);
}
for(int i = 0; i < n; i++){
    *(v + i) = *(v2 + (n - 1 - i));
}
}
int main (){
    int n;
    printf("digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int v[n];
    printf("preencha o vetor:\n");
    for (int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    printf("entrada:\n");
    for (int i = 0; i<n; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
    inverter(v, n);
    printf("saída:\n");
    for (int i = 0; i<n; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
    return 0;
}
