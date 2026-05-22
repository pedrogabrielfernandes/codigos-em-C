#include <stdio.h>

void ler_cenario(int n, int *v){
    for (int i = 0; i<n; i++){
        scanf("%d", (v+i));
    }
}

int main (){
    int n;
    printf ("digite o número de blocos no cenário:\n");
    scanf("%d", &n);
    int v[n];
    ler_cenario(n, v);
    for (int i = 0; i<n; i++){
        if (*(v + i) == 1){
            *(v + i) = 2;
            break;
        }
    }
    for (int i = 0; i<n; i++){
      printf("%d ", *(v + i));
    }
    printf("\n");
    return 0;
}
