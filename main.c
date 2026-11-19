#include <stdio.h>
#include "Encomenda.h"

int main() {
    Encomenda encomendas[MAX_ENCOMENDAS];
    int quantidade = 0;
    int opcao = -1;

    while(opcao != 0) {
        printf("\n1. Cadastrar Encomenda\n2. Listar Encomendas\n3. Buscar Encomenda\n4. Atualizar Encomenda\n5. Excluir Encomenda\n6. Reorganizar Encomendas\n7. Carregar Dados de Teste\n0. Sair\nEscolha: ");
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
                int posi=-1;
                posi= buscarEncomenda(encomendas, quantidade, codigo);
                if (posi != -1) {
                    Encomenda encomenda = encomendas[posi];
                    printf("\n===== ENCOMENDA ENCONTRADA =====\n");
                    printf("codigo: %d\n", encomenda.codigo);
                    printf("nome da encomenda: %s\n", encomenda.nome);
                    printf("endereco de entrega: %s\n", encomenda.endereco);
                    printf("peso da encomenda: %.2f kg\n", encomenda.peso);
                    printf("prazo de entrega: %d dias\n", encomenda.prazo);
                } 
                
                break;
            }
            case 4: {
                int codigo;
                printf("Digite o codigo da encomenda a ser atualizada: ");
                scanf("%d", &codigo);
                atualizarEncomenda(encomendas, quantidade, codigo);
                break;
            }   
            
            case 5:{
                deletarEncomenda(encomendas, &quantidade);
                break;
            }

            case 6:
                organizarEncomendas(encomendas, quantidade);
                break;

            case 7:
                carregarDadosMocados(encomendas, &quantidade);
                break;


            case 0:
                printf(" saindo \n");
                break;
            default:
                printf(" opcao invalida \n");
        }
    }

    return 0;
}