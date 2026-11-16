#include <stdio.h>
#include "Encomenda.h"

void cadastrarEncomenda(Encomenda encomendas[], int *quantidade) {
    printf("\n===== CADASTRAR ENCOMENDA =====\n");

    printf("digite o codigo: ");
    scanf("%d", &encomendas[*quantidade].codigo);

    printf("digite o nome da encomenda: ");
    scanf(" %49[^\n]", encomendas[*quantidade].nome);
	getchar();

    printf("digite o endereco de entrega: ");
    scanf(" %99[^\n]", encomendas[*quantidade].endereco);

    printf("digite o peso: ");
    scanf("%f", &encomendas[*quantidade].peso);

    printf("digite o prazo em dias: "); 
    scanf("%d", &encomendas[*quantidade].prazo);

    (*quantidade)++;

    printf("\n encomenda cadastrada com sucesso\n");
}

void listarEncomendas(Encomenda encomendas[], int quantidade) {
    if (quantidade == 0) {
        printf("\n nenhuma encomenda cadastrada.\n");
        return;
    }

    printf("\n===== LISTA DE ENCOMENDAS =====\n");

    for (int i = 0; i < quantidade; i++) {

        printf("\ncodigo: %d", encomendas[i].codigo);
        printf("\nnome da encomenda: %s", encomendas[i].nome);
        printf("\nendereco de entrega: %s", encomendas[i].endereco);
        printf("\npeso da encomenda: %.2f kg", encomendas[i].peso);
        printf("\nprazo de entrega: %d dias\n", encomendas[i].prazo);
    }
}

void buscarEncomenda(Encomenda encomendas[], int quantidade, int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (encomendas[i].codigo == codigo) {
            printf("\n===== ENCOMENDA ENCONTRADA =====\n");
            printf("codigo: %d\n", encomendas[i].codigo);
            printf("nome da encomenda: %s\n", encomendas[i].nome);
            printf("endereco de entrega: %s\n", encomendas[i].endereco);
            printf("peso da encomenda: %.2f kg\n", encomendas[i].peso);
            printf("prazo de entrega: %d dias\n", encomendas[i].prazo);
            return;
        }
    }
    printf("\n nenhuma encomenda encontrada com o codigo %d.\n", codigo);
}