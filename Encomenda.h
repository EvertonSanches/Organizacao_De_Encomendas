#ifndef ENCOMENDA_H
#define ENCOMENDA_H

#define MAX_ENCOMENDAS 50

typedef struct {
	int codigo;
	char nome[50];
	char endereco[100];
	float peso;
	int prazo;
		
} Encomenda;

void cadastrarEncomenda(Encomenda encomendas[], int *quantidade);

void listarEncomendas(Encomenda encomendas[], int quantidade);

int buscarEncomenda(Encomenda encomendas[], int quantidade, int codigo);

void atualizarEncomenda(Encomenda encomendas[], int quantidade, int codigo);

void deletarEncomenda(Encomenda encomendas[], int *quantidade);
#endif