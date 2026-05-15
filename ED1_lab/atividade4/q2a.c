#include <stdio.h>

struct dados{
   char nome[50];
   char numero_documento[12];
   int idade;
};

void preencher_dados(struct dados *pessoas){
    printf("nome:\n");
    scanf(" %[^\n]", pessoas->nome);
    printf("numeros do documento:\n");
    scanf("%s", pessoas->numero_documento);
    printf("idade:\n");
    scanf("%d", &pessoas->idade);
}

int main (){
    struct dados pessoa1;
    preencher_dados(&pessoa1);
    return 0;
}
