#include <stdio.h>

struct funcionario {
  char nome[50];
  float salario;
  int identificador;
  char cargo[50];
};

void imprimir_valores(struct funcionario *f){
    printf("nome: %s\n", f->nome);
    printf("salario: %.2f\n", f->salario);
    printf("identificador: %d\n", f->identificador);
    printf("cargo: %s\n", f->cargo);
}

int main () {
    struct funcionario f1 = {
      .nome = "Pedro do Grau",
      .salario = 1453.00,
      .identificador = 6436436,
      .cargo = "Pedreiro"
    };
    imprimir_valores(&f1);
    return 0;
}
