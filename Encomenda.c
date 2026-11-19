#include <stdio.h>
#include <stdlib.h>
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
        printf("\n-----------------------------\n");
    }
}


int buscarEncomenda(Encomenda encomendas[], int quantidade, int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (encomendas[i].codigo == codigo) {
            printf("\n===== ENCOMENDA ENCONTRADA =====\n");
            printf("codigo: %d\n", encomendas[i].codigo);
            printf("nome da encomenda: %s\n", encomendas[i].nome);
            printf("endereco de entrega: %s\n", encomendas[i].endereco);
            printf("peso da encomenda: %.2f kg\n", encomendas[i].peso);
            printf("prazo de entrega: %d dias\n", encomendas[i].prazo);
            return i;
        }
    }
    printf("\n nenhuma encomenda encontrada com o codigo %d.\n", codigo);

;
    return -1;
}


void atualizarEncomenda(Encomenda encomendas[], int quantidade, int codigo) {
    int posicao = buscarEncomenda(encomendas, quantidade, codigo);
    if (posicao == -1) {
        printf("\n nenhuma encomenda encontrada com o codigo %d.\n", codigo);
        return;
    }

    printf("\n===== ATUALIZAR ENCOMENDA =====\n");
    printf("digite o novo nome da encomenda: ");
    scanf(" %49[^\n]", encomendas[posicao].nome);
    getchar();

    printf("digite o novo endereco de entrega: ");
    scanf(" %99[^\n]", encomendas[posicao].endereco);

    printf("digite o novo peso: ");
    scanf("%f", &encomendas[posicao].peso);

    printf("digite o novo prazo em dias: ");
    scanf("%d", &encomendas[posicao].prazo);

    printf("\n encomenda atualizada com sucesso\n");
}

void deletarEncomenda(Encomenda encomendas[], int *quantidade) {
    int codigoBusca;

    if (*quantidade == 0) {
        printf("\n nenhuma encomenda cadastrada para excluir.\n");
        return;
    }

    printf("\n===== EXCLUIR ENCOMENDA =====\n");
    printf("digite o codigo da encomenda que deseja excluir: ");

    if (scanf("%d", &codigoBusca) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\n codigo invalido.\n");
        return;
    }

    int posicao = buscarEncomenda(encomendas, *quantidade, codigoBusca);


    for (int j = posicao; j < *quantidade - 1; j++) {
        encomendas[j] = encomendas[j + 1];
    }

    (*quantidade)--;

    printf("\n encomenda com codigo %d excluida com sucesso\n", codigoBusca);
}


void intercalarEncomendas(Encomenda encomendas[], int inicio, int meio, int fim) {

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    Encomenda *temp = malloc((fim - inicio + 1) * sizeof(Encomenda));

    if (temp == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    // Comparação e ordenação pelo código
    while (i <= meio && j <= fim) {

        if (encomendas[i].codigo <= encomendas[j].codigo) {
            temp[k] = encomendas[i];
            i++;
        } else {
            temp[k] = encomendas[j];
            j++;
        }

        k++;
    }

    // Copia os elementos restantes da primeira metade
    while (i <= meio) {
        temp[k] = encomendas[i];
        i++;
        k++;
    }

    // Copia os elementos restantes da segunda metade
    while (j <= fim) {
        temp[k] = encomendas[j];
        j++;
        k++;
    }

    // Devolve os elementos ordenados ao vetor original
    for (i = inicio, k = 0; i <= fim; i++, k++) {
        encomendas[i] = temp[k];
    }

    free(temp);
}


void mergeSort(Encomenda encomendas[], int inicio, int fim) {

    if (inicio < fim) {

        int meio = inicio + (fim - inicio) / 2;

        mergeSort(encomendas, inicio, meio);

        mergeSort(encomendas, meio + 1, fim);

        intercalarEncomendas(encomendas, inicio, meio, fim);
    }
}


void organizarEncomendas(Encomenda encomendas[], int quantidade) {

    if (quantidade <= 1) {
        printf("\nNao ha encomendas suficientes para organizar.\n");
        return;
    }

    mergeSort(encomendas, 0, quantidade - 1);

    printf("\nEncomendas organizadas por codigo com sucesso!\n");
}

        printf("\npeso da encomenda: %.2f kg", encomendas[i].peso);

        printf("\nprazo de entrega: %d dias\n", encomendas[i].prazo);
    }
}
