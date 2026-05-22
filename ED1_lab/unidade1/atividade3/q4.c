#include <stdio.h>
#include <stdlib.h>

struct NomeIdade{
    char nome [50];
    int idade;
};

int main (){
    int pessoas;
    printf("quantas pessoas vc quer arquivar?\n");
    scanf("%d", &pessoas);
    if ((pessoas > 100) || (pessoas <=0)){
        printf("a quantidade de pessoas que você quer arquivar é inapropriado.\n");
        printf("(escolha algo entre 1 a 100.)\n");
        exit(0);
    }
    struct NomeIdade *v;
    v = malloc(pessoas * sizeof(struct NomeIdade));
    if (v == NULL){
        printf("erro na alocação dinâmica");
        exit(1);
    }
    for (int i = 0; i < pessoas; i++){
        printf("Pessoa %d:\n", i + 1);
        scanf(" %[^\n]", v[i].nome);
        scanf("%d", &v[i].idade);
    }
    printf("----informações----\n");
    for (int i = 0; i < pessoas; i++){
        printf("%s, idade: %d\n", v[i].nome, v[i].idade);
    }
    free(v);
    return 0;
}
