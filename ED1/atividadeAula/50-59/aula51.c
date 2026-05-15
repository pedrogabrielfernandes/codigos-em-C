#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
}personagem;

void menu() {
    printf("========= Escolha uma opção ==========\n");
    printf("1 - consultar Personagem\n");
    printf("2 - sair\n");
    printf("======================================\n");
}

int busca(personagem v[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (v[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    personagem v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &v[i].id, v[i].nome, &v[i].forca, &v[i].agilidade, &v[i].inteligencia);
    }
    int op;
    do {
        menu();
        scanf("%d", &op);
        if (op == 1) {
            int id;
            scanf("%d", &id);
            int pos = busca(v, n, id);
            if (pos != -1) {
                float media = (v[pos].forca + v[pos].agilidade + v[pos].inteligencia) / 3;
                printf("%s %.2f\n", v[pos].nome, media);
            }
            else {
                printf("personagem nao existe\n");
            }
        }

    } while (op != 2);
    return 0;
}
