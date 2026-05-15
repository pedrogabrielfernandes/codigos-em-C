#include <stdio.h>

typedef struct{
    int saude;
    int pontuacao;
    int posX;
    int posY;
}heroi;

int main (){
    heroi meuHeroi = {100,0,0,0};
    heroi *ptrheroi;

    ptrheroi = &meuHeroi;
    ptrheroi->saude -=25;
    ptrheroi->pontuacao +=50;
    ptrheroi->posX +=10;
    ptrheroi->posY -=5;

    printf("saúde: %d\n", ptrheroi->saude);
    printf("pontuação: %d\n", ptrheroi->pontuacao);
    printf("posição X: %d\n", ptrheroi->posX);
    printf("posição Y: %d\n", ptrheroi->posY);

    printf("saude: %d\n", meuHeroi.saude);
    return 0;
}
