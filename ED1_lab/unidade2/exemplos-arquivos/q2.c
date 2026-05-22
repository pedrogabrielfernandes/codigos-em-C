#include <stdio.h>

int main(){
    int v[10];
    FILE *arquivo;
    arquivo = fopen("entrada_q2.txt", "w");
    if (arquivo==NULL){
        return 1;
    }
    int i = 0;
    while (!feof(arquivo)){
        fscanf(arquivo, "%d", &v[i]);
        i++;
    }
    printf("%d", v[1]);
    return 0;
}