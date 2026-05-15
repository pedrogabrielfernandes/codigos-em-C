#include <stdio.h>

typedef struct{
    int id;
    char nick[50];
    int rep;
}jogador;

void menu(){
    printf("======== Escolha uma opção ========\n");
    printf("1- Pesquisar\n");
    printf("2- Sair\n");
    printf("===================================\n");
}

int busca(int n, jogador v[], int busca_id){
   int i = 0;
   int f = n - 1;
   while (i<=f) {
       int meio = (i + f)/2;
       if (v[meio].id == busca_id) {
           return meio;
       }
       else if (v[meio].id < busca_id) {
           i = meio + 1;
       }
       else {
           f = meio - 1;
       }
   }
   return -1;
}

int main (){
    int n;
    printf("quantos jogadores você quer cadastrar:\n");
    scanf("%d", &n);
    jogador v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &v[i].id, v[i].nick, &v[i].rep);
    }
    int op;
    menu();
    scanf("%d", &op);
    while (op!=2) {
        if (op == 1) {
            int id_busca;
            printf("qual id você quer pesquisar?\n");
            scanf("%d", &id_busca);
            int idx = busca(n, v, id_busca);
            if (idx >= 0) {
                v[idx].rep += 100;
                printf("Nickname: %s, Nova Reputação: %d\n", v[idx].nick, v[idx].rep);
            }
            else {
                printf("jogador com id: %d não encontrado.\n", id_busca);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}
