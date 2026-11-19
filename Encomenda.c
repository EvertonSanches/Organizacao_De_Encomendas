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



static int compararEncomendas(const Encomenda *a, const Encomenda *b, int criterio) {
    if (criterio == 1) return (a->codigo > b->codigo) - (a->codigo < b->codigo);
    if (criterio == 2) return (a->peso   > b->peso)   - (a->peso   < b->peso);
    return (a->prazo > b->prazo) - (a->prazo < b->prazo);
}

/* Imprime a chave de ordenacao de v[ini..fim] (usado para mostrar os passos). */
static void imprimirTrecho(Encomenda v[], int ini, int fim, int criterio) {
    printf("[");
    for (int i = ini; i <= fim; i++) {
        if (criterio == 1)      printf("%d", v[i].codigo);
        else if (criterio == 2) printf("%.2f", v[i].peso);
        else                    printf("%d", v[i].prazo);
        if (i < fim) printf(" ");
    }
    printf("]");
}

static void imprimirRecuo(int nivel) {
    for (int i = 0; i < nivel; i++) printf("    ");
}


static void intercalar(Encomenda v[], Encomenda aux[], int ini, int meio, int fim,
                       int criterio, int nivel, int mostrar) {
    int i = ini, j = meio + 1, k = ini;

    while (i <= meio && j <= fim) {
        if (compararEncomendas(&v[i], &v[j], criterio) <= 0) aux[k++] = v[i++];
        else                                                 aux[k++] = v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim)  aux[k++] = v[j++];

    for (k = ini; k <= fim; k++) v[k] = aux[k];

    if (mostrar) {
        imprimirRecuo(nivel);
        printf("Intercalar -> ");
        imprimirTrecho(v, ini, fim, criterio);
        printf("\n");
    }
}

static void mergeSort(Encomenda v[], Encomenda aux[], int ini, int fim,
                      int criterio, int nivel, int mostrar) {
    if (ini >= fim) return;

    int meio = ini + (fim - ini) / 2;

    if (mostrar) {
        imprimirRecuo(nivel);
        printf("Dividir ");
        imprimirTrecho(v, ini, fim, criterio);
        printf(" -> ");
        imprimirTrecho(v, ini, meio, criterio);
        printf(" | ");
        imprimirTrecho(v, meio + 1, fim, criterio);
        printf("\n");
    }

    mergeSort(v, aux, ini, meio, criterio, nivel + 1, mostrar);
    mergeSort(v, aux, meio + 1, fim, criterio, nivel + 1, mostrar);
    intercalar(v, aux, ini, meio, fim, criterio, nivel, mostrar);
}

static int lerOpcaoIntervalo(const char *mensagem, int min, int max) {
    int valor, lidos;

    while (1) {
        printf("%s", mensagem);
        lidos = scanf("%d", &valor);
        if (lidos == EOF) return min;
        if (lidos == 1 && valor >= min && valor <= max) return valor;

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf(" opcao invalida.\n");
    }
}

void organizarEncomendas(Encomenda encomendas[], int quantidade) {
    if (quantidade == 0) {
        printf("\n nenhuma encomenda cadastrada para organizar.\n");
        return;
    }

    printf("\n===== ORGANIZAR ENCOMENDAS (MERGE SORT) =====\n");
    printf("1. Por codigo\n2. Por peso\n3. Por prazo\n");
    int criterio = lerOpcaoIntervalo("Escolha o criterio: ", 1, 3);
    int mostrar  = lerOpcaoIntervalo("Mostrar divisao e intercalacao? (1 = sim, 0 = nao): ", 0, 1);

    /* vetor auxiliar do Merge Sort: O(n) de memoria extra */
    Encomenda *aux = (Encomenda *) malloc(quantidade * sizeof(Encomenda));
    if (aux == NULL) {
        printf("\n falha de alocacao de memoria. nao foi possivel organizar.\n");
        return;
    }

    if (mostrar) printf("\n");
    mergeSort(encomendas, aux, 0, quantidade - 1, criterio, 0, mostrar);

    free(aux);

    printf("\n encomendas organizadas com sucesso\n");
    listarEncomendas(encomendas, quantidade);
}

void carregarDadosMocados(Encomenda encomendas[], int *quantidade) {
    static const Encomenda mock[] = {
        {40, "Caixa de livros",   "Rua das Flores, 120",     5.50f, 10},
        {12, "Notebook",          "Av. Beira Mar, 800",      2.30f,  3},
        {77, "Televisao 50pol",   "Rua do Comercio, 45",    15.00f,  7},
        { 5, "Mouse sem fio",     "Rua Bahia, 300",          0.30f,  3},
        {30, "Cadeira gamer",     "Av. Hermes Fontes, 1500", 18.00f,  1},
        {91, "Kit de ferramentas","Rua Laranjeiras, 77",     8.00f,  5},
        {23, "Impressora",        "Rua Itabaiana, 210",      6.40f,  5},
        {68, "Monitor",           "Av. Augusto Franco, 900", 4.20f,  2}
    };
    int total = (int)(sizeof(mock) / sizeof(mock[0]));
    int inseridas = 0;

    for (int i = 0; i < total; i++) {
        if (*quantidade >= MAX_ENCOMENDAS) {
            printf("\n limite de %d encomendas atingido.\n", MAX_ENCOMENDAS);
            break;
        }
        encomendas[*quantidade] = mock[i];
        (*quantidade)++;
        inseridas++;
    }

    printf("\n %d encomendas de teste carregadas (total: %d).\n", inseridas, *quantidade);
}