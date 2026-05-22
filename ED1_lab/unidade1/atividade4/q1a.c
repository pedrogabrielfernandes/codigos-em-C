#include <stdio.h>

struct funcionario{
  char nome [50];
  float salario;
  int identificador;
  char cargo[50];
};

void preencher_funcionário(struct funcionario *f){
printf("digite o nome do funcionário:\n");
scanf(" %[^\n]", f->nome);
printf("o salário do funcioário:\n");
scanf("%f", &f->salario);
printf("identificador do funcionário:\n");
scanf("%d", &f->identificador);
printf("o cargo do funcionário:\n");
scanf(" %[^\n]", f->cargo);
}

int main (){
    struct funcionario f1;
    preencher_funcionário(&f1);
    return 0;
}
