#ifndef ENCOMENDA.H
#define ENCOMENDA.H

#define MAX_ENCOMENDAS 50

typedef struct {
	int codigo;
	char nome[50];
	float peso;
	int prazo;
		
} Encomenda;

void cadastrarEncomenda(Encomenda encomendas[], int *quantidade);

void listarEncomendas(Encomenda encomendas[], int *quantidade);

#endif