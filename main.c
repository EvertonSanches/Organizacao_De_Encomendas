#include <stdio.h>
#include "Encomenda.h"

int main() {
    Encomenda encomendas[MAX_ENCOMENDAS];
    int quantidade = 0;
    int opcao;

    while(opcao != 0) {
        printf("\n1. Cadastrar Encomenda\n2. Listar Encomendas\n3. Buscar Encomenda\n4. Atualizar Encomenda\n5. Excluir Encomenda\n6. Reorganizar Encomendas\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarEncomenda(encomendas, &quantidade);
                break;
            case 2:
                listarEncomendas(encomendas, quantidade);
                break;
                case 3: {
                int codigo;
                printf("Digite o codigo da encomenda: ");
                scanf("%d", &codigo);
                buscarEncomenda(encomendas, quantidade, codigo);
                break;
            }
            case 0:
                printf(" saindo \n");
                break;
            default:
                printf(" opcao invalida \n");
        }
    } ;

    return 0;
}