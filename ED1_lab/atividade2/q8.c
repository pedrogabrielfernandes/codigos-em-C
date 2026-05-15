#include <stdio.h>

int maiorElemento (int *v, int n){
    int z = 0;
    for (int i = 0; i<n; i++){
      if (*(v+i)>z){
        z = *(v+i);
      }
      else{
        z = z;
      }      
}
    return z;
}

int main (){
    int num, resultado;
    printf("digite o tamanho do vetor: \n");
    scanf("%d", &num);
    int vetor[num];
    for (int i = 0; i<num; i++){
        printf("digite os valores do seu vetor: ");
        scanf("%d", &vetor[i]);
    }
    int *pv;
    pv = vetor;
    resultado = maiorElemento (pv, num);
    printf("o maior elemento do vetor é: %d\n", resultado);
    return 0;
}