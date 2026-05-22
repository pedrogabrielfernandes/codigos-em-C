#include <stdio.h>

struct dados{
    char nome[50];
    char numero_documento[12];
    int idade;
};

void alterar_idade(struct dados *pessoas){
    int nova_idade;
    printf("atualize sua idade:\n");
    scanf("%d", &nova_idade);
    pessoas->idade = nova_idade;
}

int main (){
    struct dados pessoa1 = {
      .nome = "Pedro Gabriel Alves Fernandes",
      .numero_documento = "11096680408",
      .idade = 19
    };
    printf("idade atual: %d\n", pessoa1.idade);
    alterar_idade(&pessoa1);
    printf("idade atualizada!\n");
    printf("idade atual: %d\n", pessoa1.idade);
    return 0;
}
