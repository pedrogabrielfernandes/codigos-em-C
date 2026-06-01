#include "combate.h"

int calcular_atk(int atk, int sword) {
    return atk + sword;
}

int aplicar_dano(int hp, int dano) {
    int temp = hp - dano;
    if (temp < 0) {
        return 0;
    }
    return temp;
}
