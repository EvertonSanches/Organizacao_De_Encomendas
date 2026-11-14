#include <stdio.h>
#include "Encomenda.h"

int main() {
    Encomenda encomendas[MAX_ENCOMENDAS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar Encomenda\n2. Listar Encomendas\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarEncomenda(encomendas, &quantidade);
                break;
            case 2:
                listarEncomendas(encomendas, quantidade);
                break;
            case 0:
                printf(" saindo \n");
                break;
            default:
                printf(" opcao invalida \n");
        }
    } while(opcao != 0);

    return 0;
}