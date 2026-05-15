#include <stdio.h>

int main (){
    char linha [100];
    int c;
    FILE * arquivo;
    arquivo = fopen("entrada.txt", "r");
    if (arquivo==NULL){
        printf("Não foi possível criar o arquivo");
        return 1;
    }
    else{
        printf("Arquivo criado\n");
    }
    //fputc('A', arquivo);
    //fputs("si mati", arquivo);
    fprintf(arquivo, "meu fi gosta de farinha?\nE de peixe?\nTU É DOIDOOO");
    // while(!feof(arquivo)){
    //     c = fgetc(arquivo);
    //     printf("%c", c);
    // }
    fscanf(arquivo, " %[^\n]", linha);
    printf("%s", linha);

    fclose(arquivo);
    return 0;
}