printf(" Nome da Encomenda: ");
scanf("%49[^/n]"), Encomendas[*quantidade].nome);

return;

{    printf("\n====   CADASTRAR ECOMENDA ====\n")

printf(" Digite o codigo");
scanf(%d, &encomendas[*quantidade].codigo);

printf(" Digite o nome da encomenda");
scanf("%49[^\n]", encomendas[*quantidade].nome);

printf(" Digite o peso");
scanf(%f, &encomendas[*quantidade].peso);

printf(" Digite o prazo em dias ");
scanf(%d, &encomendas[*quantidade].prazo);

(*quantidade)++;

printf("\n Encomenda cadastrada com sucesso \n ");

(*quantidade)++;

}

void listarEncomendas(Encomenda encomendas[], int quantidade); {


if (quantidade == 0) {
	printf("\n Nenhuma encomenda cadastrada \n");
	return;
	
}

printf(\n ===== LISTA DE ENCOMENDAS =====\n);

for (int i = o; i < quantidade; i++) {
	
	printf("\n codigo: %d", encomendas[i].codigo);
	
	printf("\n nome da encomenda: %s", encomendas[i].nome);
	
	printf("\n peso: %2.f kg", encomendas[i].peso);
	
	printf("\n prazo: %d", encomendas[i].codgo);
	
}