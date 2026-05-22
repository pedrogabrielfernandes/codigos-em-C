#include <stdio.h>

struct funcionario{
  char nome[50];
  float salario;
  int identificador;
  char cargo[50];
};

void alterar_salario(float *salario){
    float novo_salario = 0;
    printf("qual o novo salário do funcionário?");
    scanf("%f", &novo_salario);
    *salario = novo_salario;
}

int main (){
    struct funcionario f1 = {
        .salario = 1800.00
    };
    printf("salario atual: %.2f\n", f1.salario);
    alterar_salario(&f1.salario);
    printf("novo salario: %.2f\n", f1.salario);
    return 0;
}
