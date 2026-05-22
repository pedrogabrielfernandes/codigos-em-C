#include <stdio.h>
#include <stdlib.h>

struct dados {
    char nome[50];
    char numero_documento[12];
    int idade;
};

void comparar_idade(struct dados *pessoas){
    int maior_idade = 0;
    int x = pessoas[0].idade;
    for (int i = 0; i < 3; i++){
        if (pessoas[i].idade > x){
            x = pessoas[i].idade;
            maior_idade = i;
        }
    }
    printf("nome e idade do funcionario mais velho:\n");
    printf("nome: %s\n", pessoas[maior_idade].nome);
    printf("idade: %d\n", pessoas[maior_idade].idade);
    int menor_idade = 0;
    x = pessoas[0].idade;
    for (int i = 0; i < 3; i++){
        if (pessoas[i].idade < x){
            x = pessoas[i].idade;
            menor_idade = i;
        }
    }
    printf("nome e idade do funcionario mais novo:\n");
    printf("nome: %s\n", pessoas[menor_idade].nome);
    printf("idade %d\n", pessoas[menor_idade].idade);
}

int main (){
    struct dados *pessoa;
    pessoa =  malloc(3 * sizeof(struct dados));
    if (pessoa == NULL){
        printf("erro de alocação de memoria!");
        exit(1);
    }
    pessoa[0] = (struct dados){
      .nome = "Gustavo Morais",
      .numero_documento = "26432409801",
      .idade = 36
    };
    pessoa[1] = (struct dados){
      .nome = "João Claudio",
      .numero_documento = "04378913212",
      .idade = 58
    };
    pessoa[2] = (struct dados){
      .nome = "Pedro Gabriel",
      .numero_documento = "11096680408",
      .idade = 19
    };
    comparar_idade(pessoa);
    free(pessoa);
    return 0;
}
