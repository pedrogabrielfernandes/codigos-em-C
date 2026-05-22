#include <stdio.h>
#include <stdlib.h>

struct funcionario {
  char nome[50];
  float salario;
  int identificador;
  char cargo[50];
};

void comparar_salarios (struct funcionario *funcionarios){
    float x = funcionarios[0].salario;
    int maior_salario = 0;
    for (int i = 0; i < 3; i++){
        if (funcionarios[i].salario > x){
            x = funcionarios[i].salario;
            maior_salario = i;
        }
    }
    printf("maior salario e seu cargo:\n");
    printf("cargo: %s\nsalario: %.2f\n",
    funcionarios[maior_salario].cargo, funcionarios[maior_salario].salario);
    int menor_salario = 0;
    x = funcionarios[0].salario;
    for (int i = 0; i < 3; i++){
        if (funcionarios[i].salario < x){
            x = funcionarios[i].salario;
            menor_salario = i;
        }
    }
    printf("menor salario e o seu cargo:\n");
    printf("cargo: %s\nsalario: %.2f\n",
    funcionarios[menor_salario].cargo, funcionarios[menor_salario].salario);
}

int main () {
    struct funcionario *funcionarios;
    funcionarios = malloc(3 * sizeof(struct funcionario));
    if (funcionarios == NULL) {
        printf("erro na alocação dinamica!");
        exit(1);
    }
    funcionarios[0] = (struct funcionario){
        .nome = "junior morais",
        .salario = 1432.00,
        .identificador = 53242,
        .cargo = "dev junior"
    };
    funcionarios[1] = (struct funcionario){
      .nome = "gustavo montes",
      .salario = 2594.00,
      .identificador = 85323,
      .cargo = "dev pleno"
    };
    funcionarios[2] = (struct funcionario){
      .nome = "figueiredo diaz",
      .salario = 4567.00,
      .identificador = 13679,
      .cargo = "dev senior"
    };
    comparar_salarios(funcionarios);
    free(funcionarios);
    return 0;
}
