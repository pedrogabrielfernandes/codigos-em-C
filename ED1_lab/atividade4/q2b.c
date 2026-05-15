#include <stdio.h>

struct dados{
  char nome[50];
  char numero_documento[12];
  int idade;
};

void imprimir_dados(struct dados *pessoas){
    printf("nome: %s\n", pessoas->nome);
    printf("cpf: %s\n", pessoas->numero_documento);
    printf("idade: %d\n", pessoas->idade);
}

int main (){
    struct dados pessoa1 = {
        .nome = "Pedro Gabriel Alves Fernandes",
        .numero_documento = "11096680408",
        .idade = 19
    };
    imprimir_dados(&pessoa1);
    return 0;
}
